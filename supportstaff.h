#ifndef SUPPORTSTAFF_H_
#define SUPPORTSTAFF_H_

#include "staff.h"
using namespace std;

class supportstaff : public staff
{
private:
	string supStaffId;
	static int cntSup;
public:
	supportstaff();
	virtual void introduce();
	static void counterIncrementor();
	static int getCounter();
};

#endif // !STAFF_HEADER
