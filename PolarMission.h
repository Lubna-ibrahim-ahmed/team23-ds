#pragma once
#inlcude <iostream>
#include "MissionClass.h"
#include "RoverClass.h"
using namespace std;
class PolarMission : public MissionClass
{
	public:
	PolarMission(int id, int rday, int duration, int tloc);
	virtual void Operate() override;
	bool ShouldAutoAbort() const;
};