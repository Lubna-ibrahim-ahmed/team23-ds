#include "DiggingMission.h"
#include <iostream>
#include "RoverClass.h"
#include "MissionClass.h"
using namespace std;
DiggingMission::DiggingMission(int id, int rday, int duration, int tloc)
	: MissionClass(id, 'D', rday, duration, tloc) {
}
void DiggingMission::Operate() {
	cout << "Operating Digging Mission ID: " << ID << endl;
	cout << "Ready Day: " << RDay << ", Duration: " << Duration << ", TLOC: " << TLOC << endl;
	if (assignedRover != nullptr) {
		cout << "Assigned Rover ID: " << assignedRover->getID() << endl;
	} else {
		cout << "No Rover Assigned" << endl;
	}
}