#pragma once
#include "HumanSim.h"

class StillsuitSim
{
public:
	StillsuitSim(HumanSim* human);
	int StillsuitCompoundID();
	
private:
	HumanSim* human;
	
};

