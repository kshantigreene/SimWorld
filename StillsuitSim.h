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
	void updateSuit(int time, double temp);
	void seperateFluid();
	void liquidPurifier(char);
	void checkTemperature(int temp);
	void startHeat(int temp);
	void startAirCon(int temp);

	double batteryLevel(int time, double currentActivityLevel);

	double getAvailableWater();
	double sendWater(double amountRequested);

	double calculateSuitWeight();
	
private:
	int incomingLiquid;
	double waterStg;
	double MAX_waterStg = 2000;
	double emptySuitWeight = 6.8;
	int worldTime;
	int urine;
	int sweat;
	double outsideTemp;
	double battery;
	

};

#endif