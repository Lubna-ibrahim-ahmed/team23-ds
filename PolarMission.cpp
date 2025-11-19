#include <iostream>
#include "PolarMission.h"
#include "RoverClass.h"
#include "MissionClass.h"
using namespace std;
PolarMission::PolarMission(int id, int rday, int duration, int tloc)
	: MissionClass(id, 'P', rday, duration, tloc) {
}
void PolarMission::Operate() {
	cout << "Operating Polar Mission ID: " << ID << endl;
	cout << "Ready Day: " << RDay << ", Duration: " << Duration << ", TLOC: " << TLOC << endl;
	if (assignedRover != nullptr)
	{
		cout << "Assigned Rover ID: " << assignedRover->getID() << endl;
	} else 
	{
		cout << "No Rover Assigned" << endl;
	}
}
bool PolarMission::ShouldAutoAbort() const {
	if (getState() == READY && getWDays() > 2 * getDuration())
	{
		return true;
	}
	else
	{
		return false;
	}
}