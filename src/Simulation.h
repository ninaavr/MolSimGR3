/*
 * Simulation.h
 *
 *  Created on: 27.11.2014
 *      Author: christiansturm
 */

#ifndef SRC_SIMULATION_H_
#define SRC_SIMULATION_H_

#include <cstring>
#include <cstdlib>
#include <iostream>

#include "BoundaryConds.h"

using namespace std;

class Simulation {
public:
	Simulation() {
		start_time = 0;
		end_time = 1000;
		delta_t = 0.014;
		out_name = string("MD_vtk");
		writeFreq = 10;
		cutoff = 3.0;
		meshWidth = 1.1225;
		boundaries = new BoundaryConds;
	}

	/** destructor */
	virtual ~Simulation() {};

	/** start time of the simulation */
	double start_time;

	/** end time of the simulation */
	double end_time;

	/** size of the time step */
	double delta_t;

	/** common prefix for output files */
	string out_name;

	/** number of iterations before next file will be written */
	int writeFreq;

	/** domain size for LC algo */
	double domainSize[3];

	/** cut off radius for LC algo */
	double cutoff;

	/** distance between particles (2^(1/6)*sigma) */
	double meshWidth;

	/** stores boundary conditions for LC algo */
	BoundaryConds *boundaries;
};



#endif /* SRC_SIMULATION_H_ */