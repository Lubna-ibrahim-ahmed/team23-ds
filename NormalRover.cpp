#include "NormalRover.h"

NormalRover::NormalRover(int id, int speed, int checkupDuration, int missionsBeforeCheckup)
    : Rover(id, RoverType::NR, speed, checkupDuration, missionsBeforeCheckup) {
}

bool NormalRover::canHandleMission(char missionType) const {
    return missionType == 'N' || missionType == 'P'; // Normal and Polar missions
}

std::string NormalRover::getTypeString() const {
    return "Normal Rover";
}