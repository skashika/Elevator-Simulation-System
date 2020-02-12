#include "visitor.h"

int visitor::cntVis = 0;

visitor::visitor()
{
	counterIncrementor();
	visitorID = "V" + to_string(cntVis);
}

void visitor::introduce()
{
	cout << "Visitor function called \n";
	cout << "Visitor ID: " << visitorID << endl;
	cout << "Current Floor: " << getCurrFloor() << endl;
	cout << "Destination Floor: " << getDesFloor() << endl;
	cout << "Weightage: " << getWeightage() << endl;
	if (getregcall() == "Y")
	{
		cout << "Regular Call" << endl;
	}
	/*cout << "Creation Time: " << 1 + getCreationTime().tm_hour << ":";
	cout << 1 + getCreationTime().tm_min << ":";
	cout << 1 + getCreationTime().tm_sec << endl << endl;*/

}

void visitor::counterIncrementor()
{
	cntVis++;
}

int visitor::getCounter()
{
	return cntVis;
}

