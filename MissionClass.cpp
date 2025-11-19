#inlcude "MissionClass.h"
#include <iostream>
#include "RoverClass.h"
using namespace std;
MissionClass::MissionClass(int id, char type, int rday, int duration, int tloc)
	: ID(id), Type(type), RDay(rday), Duration(duration), TLOC(tloc), state(READY),
	assignedRover(nullptr), LDay(0), FDay(0), WDays(0), TDays(0), state(READY) {
}
void MissionClass::setLDay(int lday) {
	LDay = lday;
	calculateWDay(); //when the rover is launched we could now calculate the waiting days
}
void MissionClass::setAssignedRover(Rover* rover) {
	assignedRover = rover;
}
void MissionClass::setState(MissionState st) {
	state = st;
}
int MissionClass::getID() const {
	return ID;
}
char MissionClass::getType() const {
	return Type;
}
int MissionClass::getRDay() const {
	return RDay;
}
int MissionClass::getDuration() const {
	return Duration;
}
int MissionClass::getTLOC() const {
	return TLOC;
}
int MissionClass::getLDay() const {
	return LDay;
}
int MissionClass::getFDay() const {
	return FDay;
}
int MissionClass::getWDays() const {
	return WDays;
}
int MissionClass::getTDays() const {
	return TDays;
}
MissionState MissionClass::getState() const {
	return state;
}
Rover* MissionClass::getAssignedRover() const {
	return assignedRover;
}
void MissionClass::calculateTDay() {
	if (assignedRover == nullptr) {
		return 0;
	}
	int speed = assignedRover->getSpeed();
	if (speed <= 0) {
		return 0;
	}
	double TravelTime = (double)(2 * TLOC) / speed;
	int TotalDays = ceil(TravelTime / 24);
	TDays = TotalDays + Duration;
	return TDays;

}
void MissionClass::calculateFDay() {
	FDay = LDay + TDays;
}
void MissionClass::calculateWDay() {
	if (LDay < RDay)
	{
		WDays = 0;
		return;
	}
	else
	{
		WDays = LDays - RDay;
	}
	WDays = LDay - RDay;
}