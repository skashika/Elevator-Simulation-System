#ifndef VISITOR_H_
#define VISITOR_H_

#include "passenger.h"
using namespace std;

class visitor : public Passenger
{
private:
	static int cntVis;
	string visitorID;
public:
	visitor();
	virtual void introduce();
	static void counterIncrementor();
	static int getCounter();
};

#endif // !VISITOR_H_