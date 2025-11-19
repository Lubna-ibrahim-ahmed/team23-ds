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

int Rover::getAssignedMissionID() const {
    return assignedMissionID;
}

int Rover::getCheckupDuration() const {
    return checkupDuration;
}

int Rover::getMissionsBeforeCheckup() const {
    return missionsBeforeCheckup;
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


// 6. Function to increment the number of missions completed by the rover
void Rover::incrementMissions() {
    missionsCompletedCount++;
    // Check if the rover needs to go for checkup after completing the mission
    if (missionsCompletedCount >= missionsBeforeCheckup) {
        startCheckup();
    }
}

//7. Implementation of checkupRequired
bool Rover::checkupRequired() const {
    // A checkup is required if the number of missions completed
    // equals or exceeds the missions before checkup
    return missionsCompletedCount >= missionsBeforeCheckup;
}

//8. Implementation of setStatus
void Rover::setStatus(RoverStatus newStatus) {
    status = newStatus;
}

// 8. Daily Checkup Countdown
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

//9. Function definition for getRemainingCheckupDays
int Rover::getRemainingCheckupDays() const {
    return remainingCheckupDays;
}

//10. Implementation of getMissionsCompletedCount
int Rover::getMissionsCompletedCount() const {
    return missionsCompletedCount;
}