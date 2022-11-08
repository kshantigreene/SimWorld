#ifndef STILL_SUIT_SIM
#define STILL_SUIT_SIM
#pragma once
class StillsuitSim
{
public:
	StillsuitSim();
	void setLiquid(int liquid);
	void StillsuitCompoundID();
	void StillsuitCompoundDestination();
	void setTime(int time);
	void seperateFluid();
	
	void setUrine(int urine);
	int getUrine();
	void setSweat(int sweat);
	int getSweat();
	void checkTemperature(int temp);
	void startHeat(int temp);
	void startAirCon(int temp);


	

	int batteryAlert(int time);

private:
	int worldTime;
	int urine;
	int sweat;
	int urineTotal;
	int sweatTotal;
	

};

#endif