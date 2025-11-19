#pragma once
#include "Rover.h"

class DiggingRover : public Rover {
public:
    DiggingRover(int id, int speed, int checkupDuration, int missionsBeforeCheckup);
    bool canHandleMission(char missionType) const;
    std::string getTypeString() const;
};
