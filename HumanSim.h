#pragma once
#include <iostream>
#include <string>

using namespace std;

class HumanSim
{
public:
	 HumanSim(string n);
	 void setWorldInfo(int time, int temp);
	 double getBattery(); //gets the current battery life
	 int getSuitWeight(); //gets how much the suit weighs
		 //suit->getWeight();

	 int getWater(); //gets the current amount of drinkable water
	 int checkAvailWater(); //gets the current filtration process of the water
	 


private:
	 string name;
	 double worldTemp;
};

