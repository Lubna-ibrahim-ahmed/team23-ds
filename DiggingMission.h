#pragma once
#include <iostream>
#include "MissionClass.h"
#include "RoverClass.h"
using namespace std;
class DiggingMission : public MissionClass
{
	public:
	DiggingMission(int id, int rday, int duration, int tloc);
	virtual void Operate() override;
};