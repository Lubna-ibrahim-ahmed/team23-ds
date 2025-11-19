#include "PolarRover.h"

PolarRover::PolarRover(int id, int speed, int checkupDuration, int missionsBeforeCheckup)
    : Rover(id, RoverType::PR, speed, checkupDuration, missionsBeforeCheckup) {
}

bool PolarRover::canHandleMission(char missionType) const {
    return missionType == 'P' || missionType == 'N'; // Polar and Normal missions
}

std::string PolarRover::getTypeString() const {
    return "Polar Rover";
}