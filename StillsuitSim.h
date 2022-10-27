#pragma once
#include "HumanSim.h"

class StillsuitSim
{
public:
	StillsuitSim(HumanSim* human);
	void StillsuitCompoundID();
	
private:
	HumanSim* human;
	
};

