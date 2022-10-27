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
	 void calculateSweat(int time, int temp, int weight);

private:
	 string name;
	 StillsuitSim* suit;
	 double worldTemp;

	 // Weight of Human
	 int weight;

};

#endif

