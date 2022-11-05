#ifndef HUMAN_SIM
#define HUMAN_SIM
#pragma once
#include <iostream>
#include <string>
#include "StillsuitSim.h"
using namespace std;

class HumanSim
{
public:
	 HumanSim(string n, StillsuitSim* suit);
	 void setWorldInfo(int time, int temp);
	 void calculateSweat(int temp);
	 void calculateUrine(int weight);
	 double calculateHydration(int height, int weight, bool s);

private:
	 string name;
	 StillsuitSim* suit;
	 double worldTemp;

	 int weight;			// in kg
	 int height;			// in cm
	 bool sex;				// 0 female; 1 male
	 double waterLevel;		// in liters
	 double sweatInLPerMin;	// in liters per minute

};

#endif

