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
	 void setInternalTemp();
	 void calculateSweat(int time, int temp, int weight);
	 double calculateHydration(int height, int weight, bool s);
	 int CalculateInternalTemp(int temp, int InternalTemp);
	 double getBattery(); //gets the current battery life

	 int getSuitWeight(); //gets how much the suit weighss

	 int getWater(); //gets the current amount of drinkable water

	 int checkAvailWater(); //gets the current filtration process of the water

	 int getInternalTemp(); // gets the current internal temperature 
	 void setInternalTemp(int InternalTemp); // sets the Internal temperature

	 double calculateActivityLevel(int height, int weight, int age);

private:
	 string name;
	 StillsuitSim* suit;
	 double worldTemp;

	 // Weight of Human
	 int weight;
	 int height;			// in cm
	 bool sex;				// 0 female; 1 male
	 double waterLevel;		// in liters
	 double bmrM;
	 double bmrF;
	 // Internal temperature of human
	 double internalTemp;    // base temp is 98F



};

#endif