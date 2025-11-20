#pragma once
#include "RoverClass.h"
#include <iostream>
using namespace std;
enum MissionState
{
    READY,
    OUT,
    EXEC,
    BACK,
    DONE,
    ABORTED
};
class MissionClass 
{   
protected: //so that the derived classes can access these members easily
	int ID; 			 // mission ID
	char Type;           //mission type n,d,p
    int RDay;           // ready day
    int Duration;       // time for a mission to excute at target location
    int TLOC;           // dstance to target loc
    int LDay;           // launch day
    int FDay;           // finish day
    int WDays;          // waiting days = LDay - RDay
    int TDays;          // total (turnaround)days
    MissionState state; //current state of the mission
    Rover* assignedRover; // Pointer to assigned rover
public:
    MissionClass(int id, char type, int rday, int duration, int tloc);
	int getID() const;
    char getType() const;
    int getRDay() const;
    int getDuration() const;
    int getTLOC() const;
    int getLDay() const;
    int getFDay() const;
    int getWDays() const;
    int getTDays() const;
    MissionState getState() const;
    Rover* getAssignedRover() const;
	void setLDay(int lday);
	Rover* setAssignedRover(Rover* rover);
	MissionState setState(MissionState newState);
    void calculateFDay();
    void calculateTDay();
    void calculateWDay();
    virtual void Operate() = 0;
    ostream& operator<<(ostream& os, const MissionClass* m);
    
};