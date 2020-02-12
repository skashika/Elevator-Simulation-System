
#ifndef SYSGENERATOR
#define SYSGENERATOR
#include <map>
#include <vector>
#include "passenger.h"
#include "statKeeper.h"

class sysGenerator
{
public:
	int floor, no_elev, capacity, no_pass;
	map <int, vector<Passenger> > up;
	map <int, vector<Passenger> > down;

	sysGenerator();
	void readfile();
	void queueGenerate(int currFloor, int desFloor, Passenger* p);
	void dequeue(sysGenerator* sg,int currFloor, int);
};

#endif //!SYSGENERATOR


