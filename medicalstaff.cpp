#include "medicalstaff.h"

int medicalstaff::cntMed = 0;

medicalstaff::medicalstaff()
{
	counterIncrementor();
	medStaffId = "MS" + to_string(cntMed);
}

void medicalstaff::introduce()
{
	cout << "Medical Staff function called \n";
	cout << "Medical Staff ID: " << medStaffId << endl;
	cout << "Current Floor: " << getCurrFloor() << endl;
	cout << "Destination Floor: " << getDesFloor() << endl;
	cout << "Weightage: " << getWeightage() << endl;
	//cout << "Creation Time: " << 1 + getCreationTime().tm_hour << ":";
	//cout << 1 + getCreationTime().tm_min << ":";
	//cout << 1 + getCreationTime().tm_sec << endl << endl;

}

void medicalstaff::counterIncrementor()
{
	cntMed++;
}

int medicalstaff::getCounter()
{
	return cntMed;
}

