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
	// ==================================================
	// Public data members
	// ==================================================

	HumanSim(string n, StillsuitSim* suit);


	// ==================================================
	// Setter functions
	// ==================================================

	void setWorldInfo(int time, int temp);
	void setInternalTemp();
	void setInternalTemp(int InternalTemp); // sets the Internal temperature


	// ==================================================
	// Getter functions
	// ==================================================

	double getBattery(); //gets the current battery life
	int getSuitWeight(); //gets how much the suit weighs
	int getWater(); //gets the current amount of drinkable water
	int getAvailWater(); //gets the current filtration process of the water
	int getInternalTemp(); // gets the current internal temperature 

private:

	// ===================================================
	// Private data members
	// ===================================================

	string name;
	StillsuitSim* suit;
	double worldTemp;
	int weight;			// in kg
	int height;			// in cm
	bool sex;				// 0 female; 1 male
	double waterLevel;		// in liters
	double bmrM;
	double bmrF;
	double internalTemp;    // base human internal temp is 98.6F


	// ==================================================
	// Calculation functions
	// ==================================================

	void calculateSweat(int time, int temp, int weight);
	double calculateHydration(int height, int weight, bool s);
	int calculateInternalTemp(int temp, int InternalTemp);
	double calculateActivityLevel(int height, int weight, int age);

};

#endif