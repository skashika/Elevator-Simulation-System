#ifndef PASSENGER_H_
#define PASSENGER_H_

#include <iostream>
#include <string>
#include <map>
using namespace std;

class Passenger
{
private:
	string passengerId, gender;
	static int cntPassen;
	int weightage;
	int currFloor, desFloor;
	int creationTime, getOnTime, getOffTime;
	string regCall, emerCall, evacCall;

public:

	Passenger();
	virtual void introduce();
	virtual void evacuate();
	virtual void emergency();
	static void counterIncrementor();
	static int getCounter();
	void setCurrFloor(int val);
	void setDesFloor(int val);
	void setWeightage(int val);
	void setregcall(string val);
	void setemercall(string val);
	void setevaccall(string val);
	void setCreationTime(int t);
	void setGetOnTime(int t);
	void setGetOffTime(int t);
	int getCurrFloor();
	int getDesFloor();
	int getWeightage();
	string getregcall();
	string getemercall();
	string getevaccall();
	int getCreationTime();
	int getGetOnTime();
	int getGetOffTime();
	~Passenger();
};

#endif
