#ifndef STILL_SUIT_SIM
#define STILL_SUIT_SIM
#pragma once
#include <vector>
using namespace std;

class StillsuitSim
{
public:
	StillsuitSim();
	void setLiquid(int liquid);
	void StillsuitCompoundID();
	void StillsuitCompoundDestination();
	void updateSuit(int time);
	void seperateFluid();
	
	void setUrine(int urine);
	int getUrine();
	void setSweat(int sweat);
	int getSweat();
	void checkTemperature(int temp);
	void startHeat(int temp);
	void startAirCon(int temp);

	std::pair<int, int> batteryLevel(int time);

	double getAvailableWater();
	double sendWater(double amountRequested);

private:
	int worldTime;
	int urine;
	int sweat;
	int urineTotal;
	int sweatTotal;
	

};

#endif