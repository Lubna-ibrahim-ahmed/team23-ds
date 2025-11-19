#include "MissionClass.h"
#include <iostream>
#include "RoverClass.h"
using namespace std;
NormalMission::NormalMission(int id, int rday, int duration, int tloc)
	: MissionClass(id, 'N', rday, duration, tloc) {
}
void NormalMission::Operate() {
	cout << "Operating Normal Mission ID: " << ID << endl;
	cout << "Ready Day: " << RDay << ", Duration: " << Duration << ", TLOC: " << TLOC << endl;
	if (assignedRover != nullptr)
	{
		cout << "Assigned Rover ID: " << assignedRover->getID() << endl;
	}
	else
	{
		cout << "No Rover Assigned" << endl;
	}
}