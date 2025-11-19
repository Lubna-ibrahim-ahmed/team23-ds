#pragma once
#include <iostream>
#include "MissionClass.h"
class NormalMission : public MissionClass 
{
public:
	NormalMission(int id, int rday, int duration, int tloc);
	virtual void Operate() override;
};