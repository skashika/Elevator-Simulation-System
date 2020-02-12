#include "supportstaff.h"

int supportstaff::cntSup = 0;

supportstaff::supportstaff()
{
	counterIncrementor();
	supStaffId = "SS" + to_string(cntSup);
}

void supportstaff::introduce()
{
	cout << "Support Staff function called \n";
	cout << "Support Staff ID: " << supStaffId << endl;
	cout << "Current Floor: " << getCurrFloor() << endl;
	cout << "Destination Floor: " << getDesFloor() << endl;
	cout << "Weightage: " << getWeightage() << endl;
	/*cout << "Creation Time: " << 1 + getCreationTime().tm_hour << ":";
	cout << 1 + getCreationTime().tm_min << ":";
	cout << 1 + getCreationTime().tm_sec << endl << endl;*/

}

void supportstaff::counterIncrementor()
{
	cntSup++;
}

int supportstaff::getCounter()
{
	return cntSup;
}
