#ifndef STILL_SUIT_SIM
#define STILL_SUIT_SIM
#pragma once
class StillsuitSim
{
public:
	StillsuitSim();
	void StillsuitCompoundID();
	void setTime(int time);
	void seperateFluid();
	

private:
	int worldTime;
	
};

#endif