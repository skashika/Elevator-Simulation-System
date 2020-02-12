#include "passenger.h"

int Passenger::cntPassen = 0;

Passenger::Passenger()
{
	counterIncrementor();
	passengerId = "PASS" + to_string(cntPassen);
}

void Passenger::introduce()
{
}

void Passenger::evacuate()
{
}

Passenger::~Passenger()
{
}

void Passenger::counterIncrementor()
{
	cntPassen++;
}

int Passenger::getCounter()
{
	return cntPassen;
}

void Passenger::setCurrFloor(int val)
{
	currFloor = val;
}

void Passenger::setDesFloor(int val)
{
	desFloor = val;
}

void Passenger::setWeightage(int val)
{
	weightage = val;
}

void Passenger::setregcall(string val)
{
	regCall = val;
}

void Passenger::setemercall(string val)
{
	emerCall = val;
}

void Passenger::setevaccall(string val)
{
	evacCall = val;
}

void Passenger::setCreationTime(int t) {
}

void Passenger::setGetOnTime(int t) {
}

void Passenger::setGetOffTime(int t) {
}


int Passenger::getCurrFloor()
{
	return currFloor;
}

int Passenger::getDesFloor()
{
	return desFloor;
}

int Passenger::getWeightage()
{
	return weightage;
}

string Passenger::getregcall()
{
	return regCall;
}

string Passenger::getemercall()
{
	return emerCall;
}

string Passenger::getevaccall()
{
	return evacCall;
}

int Passenger::getCreationTime()
{
	return creationTime;
}

int Passenger::getGetOnTime()
{
	return getOnTime;
}

int Passenger::getGetOffTime()
{
	return getOffTime;
}

void Passenger::emergency()
{
}

