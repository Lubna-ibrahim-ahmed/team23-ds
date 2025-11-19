#include "DiggingRover.h"

DiggingRover::DiggingRover(int id, int speed, int checkupDuration, int missionsBeforeCheckup)
    : Rover(id, RoverType::DR, speed, checkupDuration, missionsBeforeCheckup) {
}

bool DiggingRover::canHandleMission(char missionType) const {
    return missionType == 'D'; // Only Digging missions
}

std::string DiggingRover::getTypeString() const {
    return "Digging Rover";
}