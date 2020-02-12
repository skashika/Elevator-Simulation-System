#include "statKeeper.h"
#include <iostream>
using namespace std;

int statKeeper::totalPass = 0;
int statKeeper::secTotal = 0;
int statKeeper::suppstaffTotal = 0;
int statKeeper::paitTotal = 0;
int statKeeper::medstaffTotal = 0;
int statKeeper::visiTotal = 0;
int statKeeper::no_ele = 0;
int statKeeper::no_floor = 0;

void statKeeper::setTotalPass(int val)
{
	totalPass += val;
}

void statKeeper::setvisiTotalPass(int val)
{
	visiTotal = val;
}

void statKeeper::setpaitTotalPass(int val)
{
	paitTotal = val;
}

void statKeeper::setsuppstaffTotalPass(int val)
{
	suppstaffTotal = val;
}

void statKeeper::setmedstaffTotalPass(int val)
{
	medstaffTotal = val;
}

void statKeeper::setsecTotalPass(int val)
{
	secTotal = val;
}

void statKeeper::setNoEle(int val)
{
	no_ele = val;
}

void statKeeper::setNoFloor(int val)
{
	no_floor = val;
}

int statKeeper::getTotalPass()
{
	return totalPass;
}

int statKeeper::getNoEle()
{
	return no_ele;
}

int statKeeper::getNoFloor()
{
	return no_floor;
}

void statKeeper::statistics() 
{
	cout << "Overall Statistics" << endl;
	cout << "Total Number of Passengers: " << totalPass << endl;
	cout << "Total Number of Visitors: " << visiTotal << endl;
	cout << "Total Number of Patient: " << paitTotal << endl;
	cout << "Total Number of Support Staff: " << suppstaffTotal << endl;
	cout << "Total Number of Medical Staff: " << medstaffTotal << endl;
	cout << "Total Number of Security: " << secTotal << endl;
}