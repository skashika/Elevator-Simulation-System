#include "patient.h"

int patient::cntPat = 0;

patient::patient()
{
	counterIncrementor();
	patientID = "P" + to_string(cntPat);
}

void patient::introduce()
{
	cout << "Patient function called \n";
	cout << "Patient ID: " << patientID << endl;
	cout << "Current Floor: " << getCurrFloor() << endl;
	cout << "Destination Floor: " << getDesFloor() << endl;
	cout << "Weightage: " << getWeightage() << endl;
	//cout << "Creation Time: " << 1 + getCreationTime().tm_hour << ":";
	//cout << 1 + getCreationTime().tm_min << ":";
	//cout << 1 + getCreationTime().tm_sec << endl << endl;

}

void patient::counterIncrementor()
{
	cntPat++;
}

int patient::getCounter()
{
	return cntPat;
}
