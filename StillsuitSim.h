#ifndef STILL_SUIT_SIM
#define STILL_SUIT_SIM
#pragma once
class StillsuitSim
{
public:
	StillsuitSim();
	void StillsuitCompoundID();
	void setTime(int time);
	int batteryAlert(int time);

private:
	int worldTime;

};

#endif