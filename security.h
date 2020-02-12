#pragma once
#ifndef SECURITY_H_
#define SECURITY_H_

#include "passenger.h"
using namespace std;

class security : public Passenger
{
private:
	static int cntSec;
	string securityID;
public:
	security();
	virtual void introduce();
	virtual void evacuate();
	static void counterIncrementor();
	static int getCounter();
};

#endif // !SECURITY_H_