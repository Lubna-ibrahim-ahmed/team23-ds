#include "RoverClass.h"
Rover::Rover(int id, RoverType t, int s, int cd, int mbc) : ID(id),
type(t),speed(s),checkupDuration(cd),missionsBeforeCheckup(mbc)
{
	missionsCompletedCount = 0;
	remainingCheckupDays = 0;
	status = RoverStatus::AVAILABLE;   //New rover is ready to work
	assignedMissionID = -1;           //No mission assigned yet
}


// --- Getter Functions (Simple Data Retrieval) ---

// These functions just return the values of the private variables. 
// They are marked 'const' because they promise not to change the object's data.

int Rover::getID() const {  
   return ID;  
}


RoverType Rover::getType() const {
    return type;
}

int Rover::getSpeed() const {
    return speed;
}

RoverStatus Rover::getStatus() const {
    return status;
}

bool Rover::isAvailable() const {
    // The rover is only free if its status is AVAILABLE
    return status == RoverStatus::AVAILABLE;
}

// --- Action Functions (State Changes) ---

// 1. Mission Launch
void Rover::assignMission(int missionID) {
    assignedMissionID = missionID;
    // The rover is launched and is now busy travelling OUT
    status = RoverStatus::BUSY_OUT;
}


// 2. Rover Reaches Target
void Rover::transitionToEXEC() {
    // Rover arrived and is executing the mission
    status = RoverStatus::BUSY_EXEC;
}


// 3. Execution Finished, Rover Starts Return
void Rover::transitionToBACK() {
    // Mission execution finished, rover is travelling BACK to base
    status = RoverStatus::BUSY_BACK;
}


// 4. Checkup Start
void Rover::startCheckup() {
    status = RoverStatus::CHECKUP;
    // Set the full duration for the maintenance period
    remainingCheckupDays = checkupDuration;
    // Reset mission counter for the next checkup cycle
    missionsCompletedCount = 0;
}


// 5. Mission Completion
void Rover::missionCompleted() {
    // 1. Mission is done, count it
    missionsCompletedCount++;
    assignedMissionID = -1; // Rover is no longer attached to that mission

    // 2. CHECKUP RULE: Check if the count has reached M (missionsBeforeCheckup)
    if (missionsCompletedCount >= missionsBeforeCheckup) {
        // Yes, time for maintenance!
        startCheckup();
    }
    else {
        // No checkup needed, go back to being available immediately
        status = RoverStatus::AVAILABLE;
    }
}


// 6. Daily Checkup Countdown
void Rover::decrementCheckupDays() {
    // Only update if the rover is actually in checkup
    if (status == RoverStatus::CHECKUP) {
        remainingCheckupDays--;

        // If the days run out, the rover is free
        if (remainingCheckupDays <= 0) {
            status = RoverStatus::AVAILABLE;
        }
    }
}