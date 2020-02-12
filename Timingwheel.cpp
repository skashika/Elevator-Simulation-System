#include "Timingwheel.h"
#include "statKeeper.h"
#include "security.h"
#include "passenger.h"
using namespace std;
Timingwheel::Timingwheel()
{
	
	for (int i = 0; i <= statKeeper::getNoFloor() * 3;i++)
	{
		slot.push_back(eleVec);
	}
	
	for (int i = 0; i < statKeeper::getNoEle();i++)
	{
		eleVec.push_back(*(new Elevator()));
	}
	slot[0] = eleVec;
}
void Timingwheel::schedule(Timingwheel* tw, int sim_time)
{
	//statKeeper sk;
	Elevator* e{};
	Elevator *temp{};

	if(!tw->slot.at(sim_time).empty())
		temp = &tw->slot.at(sim_time).back();
	else
		return;

	int num_elevator;
	
	if (temp != NULL)
	{
		int i = 0;

		//Insert method
		num_elevator = slot[sim_time].size();
//		while (num_elevator)
		for(int j = 0; j<num_elevator;j++)
		{


			e = &tw->slot[sim_time][i];

			if (e == NULL)
			{

				break;
			}
			else
			{

				tw->insert(tw,e,sim_time);

			}
//			num_elevator--;
		}
	}
	else
	{
		//Do Nothing
	}

}


void Timingwheel::insert(Timingwheel* tw,Elevator* e,int sim_time)
{

	//statKeeper sk;
	int tempSimTime;
	int time_per_floor = 3;
	int floor = e->getCurrFloor();
	int destinationFloor = e->getDesFloor();


	
	int increment = abs(destinationFloor-floor) * time_per_floor;
	

	int change = sim_time + increment;
	//Check Dest FLoor


	if (floor == destinationFloor)
	{
		tempSimTime = sim_time;
		//Do not delete the elevator from the current slot as the elevator is stationry
		tw->slot.at(tempSimTime).push_back(*e);

	}
	else
	{

		tw->slot.at(change).push_back(*e);
		tw->slot.at(change).back().setCurrFloor(destinationFloor);
	}
	tw->clear_curr_slot(tw, sim_time);
}

void Timingwheel::clear_curr_slot(Timingwheel* tw, int sim_time)
{
	//delete &(tw->slot[sim_time][pos]);
	//slot[sim_time].pop_back();
	slot[sim_time].erase(slot[sim_time].begin());
}


