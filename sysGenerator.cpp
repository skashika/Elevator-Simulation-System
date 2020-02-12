#include <iostream>
#include <fstream>
#include <string>
#include "sysGenerator.h"
using namespace std;
string p;
sysGenerator::sysGenerator()
{

}

void sysGenerator::readfile()
{
	fstream fin("file.txt");
	while (fin >> p) {

		fstream finn("Data.txt");
		finn >> floor;
		finn >> no_elev;
		finn >> capacity;
		finn >> no_pass;
		//cout << p << floor << no_elev << capacity << no_pass << endl;
	}
	statKeeper::setNoEle(no_elev);
	statKeeper::setNoFloor(floor);
}

void sysGenerator::queueGenerate(int currFloor, int desFloor, Passenger* p)
{
	vector<Passenger> temp;
	string direction;
	if (currFloor > desFloor)
	{
		temp = down[currFloor];
		temp.push_back(*p);
		down[currFloor] = temp;
	}
	else if (currFloor < desFloor)
	{
		temp = up[currFloor];
		temp.push_back(*p);
		up[currFloor] = temp;
	}

	temp.clear();
}

void sysGenerator::dequeue(sysGenerator* sg, int currFloor, int pos)
{
	vector<Passenger> temp;
	temp = sg->up[currFloor];
	//cout << temp.size() << "Size of vector in DEQUEUE\n";
	//cout << pos << "Pos in DEQUEUE\n";
	//cout << currFloor << "Curr floor in DEQUEUE\n \n";
	if (pos >= 0) {
		temp.erase(temp.begin(), temp.begin() + pos);
	}
	else
	{
		return;
	}
}