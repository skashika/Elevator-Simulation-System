#include "trafficGenerator.h"
#include "statKeeper.h"
#include "passenger.h"
#include "sysGenerator.h"
#include "Elevator.h"
#include "Timingwheel.h"
#include <iostream>
using namespace std;
int main()
{
	int typeNo, initialPassCount = 40;
	trafficGenerator* t;
	Passenger* P;
	//vector<Elevator*> ele;
	vector<Elevator> ele;
	statKeeper stats;
	sysGenerator* sg;
	sg = new sysGenerator();
	sg->readfile();
	t = new trafficGenerator("Data.txt");
	statKeeper::setTotalPass(initialPassCount);
	Timingwheel* tw = new Timingwheel();

	////////////////////////////////////////
	//INITIAL PASSENGER GENERATION
	cout << " ------- Initial Passenger Traffic generation -------- ";

	for (int i = 0; i < initialPassCount; i++)
	{
		typeNo = t->randNumGen(100, 'Y');
		P = t->generatePassenger(sg, typeNo);
		if (P == NULL)
			i--;
	}
	cout << "40 Passengers generated" << endl;
	for (int i = 0; i < sg->no_elev;i++)
	{
		int random;
		Elevator e;
		random = t->randNumGen(sg->floor, 'N');
		cout << "Elevator " << i << "is created" <<endl;
		e.setCurrFloor(random);
		e.setCurrWeight(0);
		e.setMaxCapacity(sg->capacity);
		cout << "Elevator's Current Floor is " << e.getCurrFloor() << endl;
		e.setState("s");
		e.setDirection("up");
		ele.push_back(e);
		cout << "Elevator's Direction is " << e.getDirection() << endl;
		e.movePassToElev(&e, sg);	
		cout << "Elevator's Destination Floor is " << e.getDesFloor() << endl;
		tw->slot[0][i] = e;
	}
	////////////////////////////////////////

	int end_of_simulation_time, simulation_time = 0, no_of_pass, time_slot;
	//cout << "-------- Overall Statistics after simulation completion";
	stats.setmedstaffTotalPass(medicalstaff::getCounter());
	stats.setpaitTotalPass(patient::getCounter());
	stats.setsecTotalPass(security::getCounter());
	stats.setsuppstaffTotalPass(supportstaff::getCounter());
	stats.setvisiTotalPass(visitor::getCounter());
	//cout << endl;
	cout << "-----------------------------------------" << endl;
	stats.statistics();
	cout << "-----------------------------------------" << endl;

	cout << "\n";
	cout << "Enter the simulation time : ";
	cin >> end_of_simulation_time;

	//push backall elevator objects to slot before simulation
	//2. declare size of slot and 3. go back to 0 once 8*3 is reached
	cout << endl<< "Simulation Started" << endl << endl;
	while (simulation_time < end_of_simulation_time)
	{
		
		time_slot = simulation_time % (sg->floor * 3);
		no_of_pass = t->randNumGen(sg->no_pass + 1, 'N');
		statKeeper::setTotalPass(no_of_pass);
		cout << "\nCurrent Time Unit " << simulation_time << endl;

		int count = 0;
		for (int i = 0; i < no_of_pass; i++)
		{
			count++;
			typeNo = t->randNumGen(100, 'Y');
			P = t->generatePassenger(sg, typeNo);

			if (P == NULL)
				i--;
			//else
			//	P->introduce();
		}
		cout << "Number of Passenger Generated in this time unit " << no_of_pass << endl;
		//////////////////Move Pass to Elevator//////////
		if (simulation_time != 0)
		{
			for (int i = 0; i < tw->slot[time_slot].size(); i++) {
				tw->slot[time_slot][i].movePassToElev(&tw->slot[time_slot][i], sg);
			}
		}
		cout << "Passengers are moved to respective direction to the elevators" << endl;
		////////////////////////////////////////////////
		for (int k = 0; k < tw->slot[time_slot].size();k++) {
			cout << "\nElevator Number " << tw->slot[time_slot].at(k).getEleID() << endl;
			cout << "Elevators Current Floor Before Schedule call " << tw->slot[time_slot].at(k).getCurrFloor() << endl;
			cout << "Elevators Destination Floor Before Schedule call " << tw->slot[time_slot].at(k).getDesFloorValue() << endl;
			cout << "Elevators Direction of Moving Before Schedule call " << tw->slot[time_slot].at(k).getDirection() << endl;
		}

		tw->schedule(tw, time_slot);

		for (int k = 0; k < tw->slot[time_slot].size();k++) {
			cout << "\nElevator Number " << tw->slot[time_slot].at(k).getEleID() << endl;
			cout << "Elevators Current Floor After Schedule call " << tw->slot[time_slot].at(k).getCurrFloor() << endl;
			cout << "Elevators Destination Floor After Schedule call " << tw->slot[time_slot].at(k).getDesFloorValue() << endl;
			cout << "Elevators Direction of Moving After Schedule call " << tw->slot[time_slot].at(k).getDirection() << endl;
		}

		simulation_time++;

		no_of_pass = 0;
	}
	/////////////////////////////////////////////
	//cout << "Sec Counter Val for ni bhar" << security::getCounter() << endl;

	cout << "-------- Overall Statistics after simulation completion ------------------";

	stats.setmedstaffTotalPass(medicalstaff::getCounter());
	stats.setpaitTotalPass(patient::getCounter());
	stats.setsecTotalPass(security::getCounter());
	stats.setsuppstaffTotalPass(supportstaff::getCounter());
	stats.setvisiTotalPass(visitor::getCounter());
	cout << endl;
	cout << "-----------------------------------------" << endl;
	stats.statistics();
	cout << "-----------------------------------------" << endl;
	return  0;
}

