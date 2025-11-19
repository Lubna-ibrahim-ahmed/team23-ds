#pragma once
#include "Rover.h"

class PolarRover : public Rover {
public:
    PolarRover(int id, int speed, int checkupDuration, int missionsBeforeCheckup);
    bool canHandleMission(char missionType) const;
    std::string getTypeString() const;
};