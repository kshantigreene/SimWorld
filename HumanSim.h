#ifndef HUMAN_SIM
#define HUMAN_SIM
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "StillsuitSim.h"
#include "RSAEncryption.h"
using namespace std;

// declares activity level constants
const double SEDENTARY = 1;
const double LIGHTACTIVE = 3;
const double MODERATEACTIVE = 5;
const double VERYACTIVE = 8;
const double EXTRAACTIVE = 10;
class HumanSim
{
public:
	// ==================================================
	// Public data members
	// ==================================================

	HumanSim(string n, StillsuitSim* suit);
	HumanSim(string n, StillsuitSim* suit, double currentActivity, int age, int height, int weight, bool sex, RSAEncryption* encryption);

	// ==================================================
	// Setter functions
	// ==================================================

	void setInternalTemp(int InternalTemp); // sets the Internal temperature
	void updateHuman(int time, int temp);


	// ==================================================
	// Getter functions
	// ==================================================

	void getBattery(); //gets the current battery life
	int getSuitWeight(); //gets how much the suit weighs
	void getWater(); //gets the current amount of drinkable water
	void getAvailWater(); //gets the current filtration process of the water
	int getInternalTemp(); // gets the current internal temperature 

private:

	// ===================================================
	// Private data members
	// ===================================================

	double sweat;			// in milliliters
	double currentWL;		// current total water of human
	double expectedWL;		// how much water human should have
	double waterDrank;
	bool dead;

	double bladderCapacity;	
	void setTotalBodyWater();
	double calculateSweat(double InternalTemp);
	void calculateUrine(double urine);

	// ==================================================
	// Calculation functions
	// ==================================================

	void calculateHydration();
	int calculateInternalTemp(int temp, int InternalTemp);
	double calculateActivityLevel();
	bool HumanLocation(bool inSuit); 
	void amountDrank();
	int activity(int time, int hour, int minute);
	void calculateDeath();

	// ==================================================
	// Sending functions
	// ==================================================

	void sendFluidsToSuit(double water, double urea, double chloride, double sodium, double creatinine, double potassium);

private:
	 string name;
	 StillsuitSim* suit;
	 double worldTemp;

	 // Weight of Human
	 int weight;			// in kg
	 int height;			// in cm
	 int age;
	 bool sex;				// 0 female; 1 male
	 double waterLevel;		// in liters
	 double urine;			// in milliliters
	 double bmrM;
	 double bmrF;
	 // Internal temperature of human
	 int internalTemp;    // base temp is 98F
	 int time; 
	 bool usingSuit;
	 int evaporate(int sweat, int temp);
	 int currentActivity;
	 double activityLevel;
	 RSAEncryption* encryption;
	 int activityChange;


};

#endif