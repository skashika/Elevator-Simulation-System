#ifndef TRAFFICGENERATOR
#define TRAFFICGENERATOR
#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <iostream>
#include <string>
#include <map>
#include <cmath>
#include <ctime>
#include "medicalstaff.h"
#include "supportstaff.h"
#include "visitor.h"
#include "patient.h"
#include "security.h"
#include "passenger.h"
#include "statKeeper.h"
#include "sysGenerator.h"
using namespace std;

class trafficGenerator
{
	struct dataAttributes {
		string passengerType;
		double passArrivingProb;
		int regCall, emerCall, evacCall;
		int ExWgh1, ExWgh2;
	};

private:
	int totalFloor;
	dataAttributes visiRequir, patiRequir, supstaffRequir, medstaffRequir, secstaffRequir;
	string fname;
	map<int, string> passType;

public:
	trafficGenerator(string fName = "");
	void setFilename(string fileName);
	string getFilename();
	void settingDataMembers();
	void display();
	int randNumGen(int range, char addreq);
	Passenger* generatePassenger(sysGenerator* sg, int typeNo);
	int addweight(int max_weight);
};

#endif //TRAFFICGENERATOR