#ifndef STILL_SUIT_SIM
#define STILL_SUIT_SIM
#pragma once
#include <vector>
#include "RSAEncryption.h"

using namespace std;

class StillsuitSim
{
public:
	StillsuitSim(RSAEncryption * encrypt);
	void setLiquid(int liquid);
	void StillsuitCompoundID(int incomingLiquid);
	void StillsuitCompoundDestination();
	void updateSuit(int time, double temp);
	void seperateFluid();
	void liquidPurifier(char);
	double checkTemperature();
	auto startHeat();
	auto startAirCon();

	double batteryLevel(int time, double currentActivityLevel);

	double getAvailableWater();
	double sendWater(double amountRequested);

	void setInSuit(bool inSuit);

	double calculateSuitWeight();

	int decrypt(int incomingLiquid);
	
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
	RSAEncryption *encryption;
	bool inSuit;

};

#endif