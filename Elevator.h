#ifndef ELEVATOR_H_
#define ELEVATOR_H_

#include <iostream>
#include <string>
#include <vector>
#include "Passenger.h"
#include "sysGenerator.h"
using namespace std;
class Elevator
{
private:
	string ElevatorID, State, Direction;
	static int cntElevator;
	int maxCapacity;
	int currWeight, currFloor, desFloorValue;
	map <int, vector<Passenger> > elevator_queue;


public:
	vector<bool> desFloor;
	Elevator();
	//~Elevator();
	static void cntIncrementor();
	static int getCnt();
	void setState(string s);
	void setDirection(string s);
	void setMaxCapacity(int);
	void setCurrWeight(int);
	void setCurrFloor(int);
	void setDesFloor(int);
	string getState();
	string getDirection();
	int getMaxCapacity();
	int getCurrWeight();
	int getCurrFloor();
	int getDesFloor();
	int getDesFloorValue();
	string getEleID();
	void incrementWeight(int);
	void enqueuePass(int destFloor,Passenger* P);
	void movePassToElev(Elevator* e,sysGenerator* sg);

};
#endif !ELEVATOR_H_
