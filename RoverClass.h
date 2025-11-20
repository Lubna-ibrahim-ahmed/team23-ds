#pragma once
#include <iostream>
#include <string>
#include "RoverClass.h"
using namespace std;
// Enum for Rover Type for easy identification
enum class RoverType {
    DR, // Digging Rover
    PR, // Polar Rover
    NR  // Normal Rover
};
// Enum for Rover State to track its availability
enum class RoverStatus {
    AVAILABLE,
    BUSY_OUT,
    BUSY_EXEC,
    BUSY_BACK,
    CHECKUP
};

class Rover {
private:

    // --- Static Properties (Set at creation) ---
    int ID;
    RoverType type;                   // Type of the rover
    int speed;                        // km/h
    int checkupDuration;              // CD, CP, or CN (in days)
    int missionsBeforeCheckup;         // M from input


    // --- Dynamic State (Changes during simulation) ---
    RoverStatus status;
    int missionsCompletedCount;
    int remainingCheckupDays;
    int assignedMissionID; // ID of the mission the rover is currently carrying


public:
    // Constructor
    Rover(int id, RoverType t, int s, int cd, int mbc);
       /* : ID(id), type(t), speed(s), checkupDuration(cd),
       /* missionsBeforeCheckup(mbc), missionsCompletedCount(0),
        //remainingCheckupDays(0), status(RoverStatus::AVAILABLE),
        //assignedMissionID(-1) {};*/

    // Getters (Essential for BaseStation logic)
    int getID() const;
    RoverType getType() const;
    int getSpeed() const;
    RoverStatus getStatus() const;
    bool checkupRequired() const;


    int getMissionsCompletedCount() const;
    int getMissionsBeforeCheckup() const;
    int getCheckupDuration() const;
    int getRemainingCheckupDays() const;
    int getAssignedMissionID() const;

    
    void setStatus(RoverStatus newStatus);
    void assignMission(int missionID);
    void transitionToEXEC();
        // Rover arrived and is executing
       
    void transitionToBACK();
       // Execution finished, rover is returning
      
    void missionCompleted();
        // 1. Mission is done, increment count
       
    void incrementMissions();

    void startCheckup();

    void decrementCheckupDays();


    // Check if the rover is currently free to take a new mission
    bool isAvailable() const;
    ostream& operator<<(ostream& os, const Rover* r);
};



    
    
    












