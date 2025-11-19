#pragma once
#include "Rover.h"

class NormalRover : public Rover {
public:
    NormalRover(int id, int speed, int checkupDuration, int missionsBeforeCheckup);
    bool canHandleMission(char missionType) const;
    std::string getTypeString() const;
};