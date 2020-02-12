#pragma once

#ifndef STAFF_HEADER
#define STAFF_HEADER

#include "passenger.h"
using namespace std;


	class staff : public Passenger
	{
	private:
		string staffId;
	public:
		virtual void emergency();
		virtual void introduce();
	};


#endif // !STAFF_HEADER

