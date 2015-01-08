/*
 * ParticleGenerator.cpp
 *
 *  Created on: 03.11.2014
 *      Author: christiansturm
 */

#include "ParticleGenerator.h"
#include "MaxwellBoltzmannDistribution.h"
#include "Logger.h"

#include <fstream>
#include <sstream>
#include <iostream>
#include <cstdlib>

const LoggerPtr particlelog(Logger::getLogger("molsim.particle"));
const LoggerPtr iolog(log4cxx::Logger::getLogger("molsim.io"));

ParticleGenerator::ParticleGenerator() {

}

void ParticleGenerator::getFileInput(char* fileName, ParticleContainer* pc, Simulation *sim) {
	double m = 1;
	int num_cuboids = 0;

	std::ifstream input_file(fileName);
	string tmp_string;

	if (input_file.is_open()) {
		getline(input_file, tmp_string);
		LOG4CXX_DEBUG(iolog, "Read line: " << tmp_string);

		while (tmp_string.size() == 0 || tmp_string[0] == '#') {
			getline(input_file, tmp_string);
			LOG4CXX_DEBUG(iolog, "Read line: " << tmp_string);
		}

		istringstream numstream(tmp_string);
		numstream >> num_cuboids;
		LOG4CXX_DEBUG(iolog, "Reading " << num_cuboids << ".");
		getline(input_file, tmp_string);
		LOG4CXX_DEBUG(iolog, "Read line: " << tmp_string);

		for (int i = 0; i < num_cuboids; i++) {
			istringstream datastream(tmp_string);

			for (int j = 0; j < 3; j++) {
				datastream >> X[j];
			}
			for (int j = 0; j < 3; j++) {
				datastream >> V[j];
			}

			for (int j = 0; j < 3; j++) {
				datastream >> num[j];
			}
			if (datastream.eof()) {
				LOG4CXX_ERROR(iolog, "Error reading file: eof reached unexpectedly reading from line " << i);
				exit(-1);
			}

			datastream >> meanV;
			datastream >> M;
			datastream >> H;

			// create particles from cuboid data
			LOG4CXX_ERROR(particlelog, "Generating Cuboid...");
			createParticles(pc);

			getline(input_file, tmp_string);
		}
	} else {
		LOG4CXX_ERROR(iolog, "Error: could not open file " << fileName);
		exit(-1);
	}

}

ParticleGenerator::ParticleGenerator(utils::Vector<double, 3>& x, utils::Vector<int, 3>& n,
			utils::Vector<double, 3>& v, double h, double m, double meanv) {
	X = x;
	num = n;
	V = v;
	H = h;
	M = m;
	meanV = meanv;
}


ParticleGenerator::~ParticleGenerator() {

}

void ParticleGenerator::createParticles(ParticleContainer* pc) {
	int dim = num[2] <= 1 ? 2 : 3;

	for (int i = 0; i < num[0]; i++) {	// X dimension
		for (int j = 0; j < num[1]; j++) {	// Y dimension
			for (int k = 0; k < num[2]; k++) {	// Z dimension
				utils::Vector<double, 3> x;
				// calculate position
				x[0] = X[0] + i * H;
				x[1] = X[1] + j * H;
				x[2] = X[2] + k * H;
				Particle p(x, V, M, 0);
				MaxwellBoltzmannDistribution(p, meanV, dim);
				pc->add(p);
			}
		}
	}
}

void ParticleGenerator::createCuboid(utils::Vector<double, 3>& xn, utils::Vector<int, 3>& n,
		utils::Vector<double, 3>& v, double h, double m, double meanv, ParticleContainer* pc, Simulation * sim, int particleType) {

	int dim = n[2] <= 1 ? 2 : 3;
	Particle* cP;															//current Particle; just an aid that points to the Particle that the neighbour-assigning routine further below for the membrane is currently working on.
	Particle* membraneBuffer [n[0]] [n[1]];										//matrix of particle pointers that the neighbour-assigning routine for the membrane works on.

	for (int i = 0; i < n[0]; i++) {	// X dimension
		for (int j = 0; j < n[1]; j++) {	// Y dimension
			for (int k = 0; k < n[2]; k++) {	// Z dimension
				utils::Vector<double, 3> x;
				// calculate position
				x[0] = xn[0] + i * h;
				x[1] = xn[1] + j * h;
				x[2] = xn[2] + k * h;

				Particle p(x, v, m, particleType);
				if(sim->meanVelocityTypeFlag==1){
					CalcT::initializeV(&meanv,sim->initTemp,p.getM());
				}
				//cout<<"meanV     "<<meanv<<endl;
				MaxwellBoltzmannDistribution(p, meanv, dim);
				if ((*sim).membrane && k == 0) {
					membraneBuffer [i] [j] = &p;								//fills up the membraneBuffer during particle generation, only if the Simulation is for a membrane of course.
				}
				pc->add(p);
			}
		}
	}
	
	if ((*sim).membrane) {													//the neighbour-assigning routine for the membrane.
		for (int i = 0; i < n[0]; i++) {	// X dimension
			for (int j = 0; j < n[1]; j++) {	// Y dimension
				cP = membraneBuffer [i] [j];

				if (i != 0) {(*cP).Neighbour[1] = membraneBuffer [i - 1] [j];}							//these four assign the left, right, bottom and top neighbours to the current Particle cP in this order.
				if (i != n[0] - 1) {(*cP).Neighbour[5] = membraneBuffer [i + 1] [j];}
				if (j != 0) {(*cP).Neighbour[7] = membraneBuffer [i] [j - 1];}
				if (j != n[1] - 1) {(*cP).Neighbour[3] = membraneBuffer [i] [j + 1];}

				if (i != 0 && j != 0) {(*cP).Neighbour[0] = membraneBuffer [i - 1] [j - 1];}				//these four assign the diagonal neighbours: bottom left, top left, bottom right, top right. In this order.
				if (i != 0 && j != n[1] - 1) {(*cP).Neighbour[2] = membraneBuffer [i - 1] [j + 1];}
				if (i != n[0] - 1 && j != 0) {(*cP).Neighbour[6] = membraneBuffer [i + 1] [j - 1];}
				if (i != n[0] - 1 && j != n[1] - 1) {(*cP).Neighbour[4] = membraneBuffer [i + 1] [j + 1];}
			}
		}
	}
}

void ParticleGenerator::createSphere(utils::Vector<double, 3>& x, int n,
			utils::Vector<double, 3>& v, double h, double m, double meanv, int brownDim, ParticleContainer* pc, Simulation * sim, int particleType) {

	for (int i = -n; i <= n; i++) {	// X dimension
		for (int j = -n; j <= n; j++) {	// Y dimension
			for (int k = -n; k <= n; k++) {	// Z dimension
				utils::Vector<double, 3> xn;

				if (sqrt(i * i + j * j + k * k) <= n) {								//checks if proposed particle position is within the radius
					// calculate position
					xn[0] = x[0] + i * h;
					xn[1] = x[1] + j * h;
					xn[2] = x[2] + k * h;

					Particle p(xn, v, m, 0);
					if(sim->meanVelocityTypeFlag==1){
						CalcT::initializeV(&meanv,sim->initTemp,p.getM());
					}
					//cout<<"meanV     "<<meanv<<endl;
					MaxwellBoltzmannDistribution(p, meanv, brownDim);
					pc->add(p);
				}
			}
		}
	}
}
