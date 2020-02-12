#ifndef PATIENT_H_
#define PATIENT_H_

#include "passenger.h"
using namespace std;

class patient : public Passenger
{
private:
	static int cntPat;
	string patientID;
public:
	patient();
	virtual void introduce();
	static void counterIncrementor();
	static int getCounter();
};

#endif // !PATIENT_H_
