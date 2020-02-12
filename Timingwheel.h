#pragma once
#ifndef  TIMINGWHEEL
#define TIMINGWHEEL

#include <vector>
#include <string>
#include <cstdlib>
#include "Elevator.h"
using namespace std;

class Timingwheel
{
public:
	vector<Elevator> eleVec;
 	vector<vector<Elevator>> slot;
	Timingwheel();
	void schedule(Timingwheel*,int sim_time);
	void insert(Timingwheel* tw,Elevator*,int);
	void clear_curr_slot(Timingwheel* tw,int sim_time);
};


#endif // ! TIMINGWHEEL


