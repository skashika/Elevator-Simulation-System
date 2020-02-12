#include "security.h"

int security::cntSec = 0;

security::security()
{
	counterIncrementor();
	securityID = "SE" + to_string(cntSec);
}

void security::introduce()
{
	cout << "Security function called \n";
	cout << "Security ID: " << securityID << endl;
	cout << "Current Floor: " << getCurrFloor() << endl;
	cout << "Destination Floor: " << getDesFloor() << endl;
	cout << "Weightage: " << getWeightage() << endl;
	//cout << "Creation Time: " << 1 + getCreationTime().tm_hour << ":";
	//cout << 1 + getCreationTime().tm_min << ":";
	//cout << 1 + getCreationTime().tm_sec << endl << endl;


}

void security::evacuate()
{

}

void security::counterIncrementor()
{
	cntSec++;
}

int security::getCounter()
{
	//cout << "Idhar kya value hai " << cntSec << endl;
	return cntSec;
}
