
#ifndef SRC_TEST_THERMOSTATTEST_H_
#define SRC_TEST_THERMOSTATTEST_H_

#include <cppunit/TestCase.h>
#include <cppunit/TestAssert.h>
#include <cppunit/TestSuite.h>
#include <cppunit/TestCaller.h>

#include "../ParticleContainerLC.h"
#include "../Simulation.h"

using namespace CppUnit;

/** Defines test suite for Thermostat */
class ThermostatTest : public TestCase {
public:
	virtual ~ThermostatTest();

	void setUp();
	void tearDown();

	void testT();

	static Test *suite ()  {
		TestSuite *suiteOfTests = new TestSuite;
		suiteOfTests->addTest (new TestCaller<ThermostatTest>("testT", &ThermostatTest::testT));
		return suiteOfTests;
	}

private:
	double Beta;
	ParticleContainerLC* pc;
	Simulation *sim;
	Particle *p;
};

#endif /* SRC_TEST_THERMOSTATTEST_H_ */
