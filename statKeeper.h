#pragma once
#include<chrono>
using namespace std;
class statKeeper
{
private:
	static int totalPass,visiTotal,paitTotal,suppstaffTotal,medstaffTotal,secTotal,no_ele;
	static int no_floor;
public:
	static void setTotalPass(int val);
	static void setvisiTotalPass(int val);
	static void setpaitTotalPass(int val);
	static void setsuppstaffTotalPass(int val);
	static void setmedstaffTotalPass(int val);
	static void setsecTotalPass(int val);
	static void setNoEle(int val);
	static void setNoFloor(int val);
	static int getTotalPass();
	static int getNoEle();
	static int getNoFloor();
	void statistics();
};


