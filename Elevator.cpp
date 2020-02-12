#include "Elevator.h"


int Elevator::cntElevator = 0;


Elevator::Elevator()
{
	cntIncrementor();
	ElevatorID = "E" + to_string(cntElevator);
	for (int i = 0; i < statKeeper::getNoFloor();i++)
		desFloor.push_back(false);
}

//Elevator::~Elevator()


void Elevator::cntIncrementor()
{
	cntElevator++;
}

int Elevator::getCnt()
{
	return cntElevator;
}

void Elevator::setState(string s)
{
	State = s;
}

void Elevator::setDirection(string s)
{
	Direction = s;
}

void Elevator::setMaxCapacity(int val)
{
	maxCapacity = val;
}

void Elevator::setCurrWeight(int val)
{
	currWeight = val;
}

void Elevator::setCurrFloor(int val)
{
	currFloor = val;
}

void Elevator::setDesFloor(int val)
{
	desFloorValue = val;
}

string Elevator::getState()
{
	return State;
}

string Elevator::getDirection()
{
	return Direction;
}

int Elevator::getMaxCapacity()
{
	return maxCapacity;
}

int Elevator::getCurrWeight()
{
	return currWeight;
}

int Elevator::getCurrFloor()
{
	return currFloor;
}

int Elevator::getDesFloor()
{
	
	if (Direction == "up") {
		
		desFloor[currFloor] = 0;
		if (currFloor == desFloor.size() - 1)
		{
			
			Direction = "down";
			for (int i = currFloor - 1; i > -1; i--) {
				if (desFloor[i] == true) {
					return i;
				}
			}
			return currFloor;
		}
		else {
			for (int i = currFloor + 1; i < desFloor.size(); i++) {
				if (desFloor[i] == 1) {
					return i;
				}
			}
			Direction = "down";
			for (int i = currFloor - 1; i > -1; i--) {
				if (desFloor[i] == 1) {
					return i;
				}
			}
		}
	}
	else if(Direction == "down") {
		if (currFloor == 0) {
			Direction = "up";
			for (int i = currFloor + 1; i < desFloor.size(); i++) {
				if (desFloor[i] == true) {
					return i;
				}
			}
			return currFloor;
		}
		else{
			desFloor[currFloor] = false;
			for (int i = currFloor - 1; i > -1; i--) {
				if (desFloor[i] == true) {
					return i;
				}
			}
			Direction = "up";
			for (int i = currFloor + 1; i < desFloor.size(); i++) {
				if (desFloor[i] == true) {
					return i;
				}
			}
		}
	}
	return currFloor;
}

int Elevator::getDesFloorValue()
{
	return desFloorValue;
}

string Elevator::getEleID()
{
	return ElevatorID;
}

void Elevator::incrementWeight(int val)
{
	currWeight += val;
}

void Elevator::enqueuePass(int destFloor,Passenger* P)
{
	vector<Passenger> temp;
	temp = elevator_queue[destFloor];
	temp.push_back(*P);
	elevator_queue[destFloor] = temp;
	temp.clear();
}

void Elevator::movePassToElev(Elevator* e, sysGenerator* sg)
{
	vector<Passenger> temp;

	int curr_floor = e->getCurrFloor();

	if (Direction == "up") 
		temp = sg->up[curr_floor];
	else if(Direction=="down")
		temp = sg->down[curr_floor];

	//cout << temp.size() << " kon kon hai gussa\n";
	for (int i = 0; i < temp.size();i++)
	{
		int pass_weight = 0;

		if (e->getCurrWeight() < e->getMaxCapacity())
		{
			pass_weight = temp[i].getWeightage();

			if (pass_weight + e->getCurrWeight() < e->getMaxCapacity())
			{
				e->incrementWeight(pass_weight);
				e->enqueuePass(temp[i].getDesFloor(), &temp[i]);
				//cout << temp[i].getDesFloor() << " pass ka konsa sthanak\n";
				if (e->desFloor[temp[i].getDesFloor()] == 0)
				{
				//	cout << "dest if me jara kya";
					e->desFloor[temp[i].getDesFloor()] = 1;
					e->setDesFloor(temp[i].getDesFloor());
				}
			}
			else
			{
				//deque
				sg->dequeue(sg, currFloor, i - 1);
			}
		}
	}
}
