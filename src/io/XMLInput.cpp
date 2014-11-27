/*
 * XMLInput.cpp
 *
 *  Created on: 15.11.2014
 *      Author: christiansturm
 */

#include <io/input.h>
#include "XMLInput.h"
#include "../Logger.h"
#include "../ParticleGenerator.h"

using namespace std;
using namespace input;

const LoggerPtr iolog(log4cxx::Logger::getLogger("molsim.io"));

XMLInput::~XMLInput() {
	// TODO Auto-generated destructor stub
}

void XMLInput::getFileInput(char* fileName, ParticleContainer* pc, Simulation *sim) {
	try {
		// initialize xml object
		string file(fileName);
		auto_ptr<molsimdata> molsim (molsimdata_ (file));

		// set simulation parameters
		LOG4CXX_INFO(iolog, "reading simulation parameters...");
		sim->start_time = 0;
		sim->out_name = molsim->outputbasename();
		sim->writeFreq = molsim->writefreq();
		sim->delta_t = molsim->timestep();
		sim->end_time = molsim->endtime();
		sim->domainSize[0] = molsim->domain()->size().x();
		sim->domainSize[1] = molsim->domain()->size().y();
		sim->domainSize[2] = molsim->domain()->size().z();
		if (sim->domainSize[2] == 0)
			sim->domainSize[2] = 1;
		sim->cutoff = molsim->domain()->cutoff();
		LOG4CXX_DEBUG(iolog, "out: " << sim->out_name << ", wFq: " << sim->writeFreq << ", delta t: " <<
				sim->delta_t << ", end: " << sim->end_time << ", cutoff: " << sim->cutoff << ", domain: " <<
				sim->domainSize[0] << " x " << sim->domainSize[1] << " x " << sim->domainSize[2]);

		// get boundary conditions
		BoundaryConditions *bc = sim->boundaries;
		string str = molsim->domain()->boundaries().front();
		bc->setBoundary(BoundaryConditions::FRONT, defineBoundary(str));
		str = molsim->domain()->boundaries().back();
		bc->setBoundary(BoundaryConditions::BACK, defineBoundary(str));
		str = molsim->domain()->boundaries().left();
		bc->setBoundary(BoundaryConditions::LEFT, defineBoundary(str));
		str = molsim->domain()->boundaries().right();
		bc->setBoundary(BoundaryConditions::RIGHT, defineBoundary(str));
		str = molsim->domain()->boundaries().top();
		bc->setBoundary(BoundaryConditions::TOP, defineBoundary(str));
		str = molsim->domain()->boundaries().bottom();
		bc->setBoundary(BoundaryConditions::BOTTOM, defineBoundary(str));

		LOG4CXX_INFO(iolog, "reading object data...");
		objectlist objects = molsim->objectlist();

		// iterating over cuboids
		for (objectlist::cuboid_const_iterator i (objects.cuboid().begin());
	         i != objects.cuboid().end();
	         ++i) {
			LOG4CXX_DEBUG(iolog, "generating cuboid...");
			// set coordinates
			utils::Vector<double, 3> x;
			x[0] = i->location().x();
			x[1] = i->location().y();
			x[2] = i->location().z();

			// set dimensions
			utils::Vector<int, 3> n;
			n[0] = i->numparticles().x();
			n[1] = i->numparticles().y();
			n[2] = i->numparticles().z();

			// set velocity
			utils::Vector<double, 3> v;
			v[0] = i->velocity().x();
			v[1] = i->velocity().y();
			v[2] = i->velocity().z();

			sim->meshWidth = i->meshwidth();
	    	ParticleGenerator pg;
	    	pg.createCuboid(x, n, v, i->meshwidth(), i->mass(), i->brownian(), pc);
	    }

		// iterating over spheres
		for (objectlist::sphere_const_iterator i (objects.sphere().begin());
			 i != objects.sphere().end();
			 ++i) {
			LOG4CXX_DEBUG(iolog, "generating sphere...");
			// set coordinates
			utils::Vector<double, 3> x;
			x[0] = i->location().x();
			x[1] = i->location().y();
			x[2] = i->location().z();

			// set velocity
			utils::Vector<double, 3> v;
			v[0] = i->velocity().x();
			v[1] = i->velocity().y();
			v[2] = i->velocity().z();

			sim->meshWidth = i->meshwidth();
			ParticleGenerator pg;
			pg.createSphere(x, i->numparticles(), v, i->meshwidth(), 1.0, 0.1, pc);
		}

		// iterating over particles
		for (objectlist::particle_const_iterator i (objects.particle().begin());
			 i != objects.particle().end();
			 ++i) {
			LOG4CXX_DEBUG(iolog, "generating particle...");
			// set coordinates
			utils::Vector<double, 3> x;
			x[0] = i->location().x();
			x[1] = i->location().y();
			x[2] = i->location().z();

			// set velocity
			utils::Vector<double, 3> v;
			v[0] = i->velocity().x();
			v[1] = i->velocity().y();
			v[2] = i->velocity().z();

			Particle p(x, v, i->mass(), 0);
			pc->add(p);
		}
		LOG4CXX_INFO(iolog, "reading done...");
	}
	catch (const xml_schema::exception& e) {
		LOG4CXX_FATAL(iolog, "couldn't read XML file: " << e);
		exit(-1);
	}
}

BoundaryConditions::Boundary XMLInput::defineBoundary(string str) {
	return string("outflow").compare(str) == 0 ? BoundaryConditions::OUTFLOW : BoundaryConditions::REFLECTING;;
}
