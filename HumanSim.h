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

	void setInternalTemp(int InternalTemp); // sets the Internal temperature
	 void updateHuman(int time, int temp);
	 double calculateSweat(int temp, double InternalTemp);
	 void calculateUrine(int weight);
	 int calculateInternalTemp(int temp, int InternalTemp);


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

	double sweat;			// in milliliters

	 double bladderCapacity;	

	// ==================================================
	// Calculation functions
	// ==================================================

	double calculateHydration(int height, int weight, bool s);
	int calculateInternalTemp(int temp, int InternalTemp);
	double calculateActivityLevel(int height, int weight, int age);
	void HumanLocation(); 
	

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
	 int internalTemp;    // base temp is 98F
	 int time; 
	 bool usingSuit;
	 int evaporate(int sweat, int temp);
	 double activityLevel;

};

#endif