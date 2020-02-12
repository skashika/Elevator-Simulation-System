#ifndef MEDICALSTAFF_H_
#define MEDICALSTAFF_H_

#include "staff.h"
using namespace std;
class medicalstaff : public staff
{
private:
	static int cntMed;
	string medStaffId;
public:
	medicalstaff();
	virtual void introduce();
	static void counterIncrementor();
	static int getCounter();

};

#endif // !STAFF_HEADER
