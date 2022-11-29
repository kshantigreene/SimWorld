#include "HumanSim.h"
#include "StillsuitSim.h"
#include <cmath>
using std::log;

HumanSim::HumanSim(string n, StillsuitSim* suit) {
    this->name = name;
    this->suit = suit;
    this->currentActivity = MODERATEACTIVE; // FOR NOW (ADDED THIS)
    setInternalTemp(98.6);
    setTotalBodyWater();                    // Will remove this entire constructor once implementation added for the other (full) constructor in simworld
};

HumanSim::HumanSim(string n, StillsuitSim* suit, double currentActivity, int age, int height, int weight, bool sex) {
	this->name = name;
    this->suit = suit;
    this->currentActivity = currentActivity;
    this->age = age;
    this->height = height;
    this->weight = weight;
    this->sex = sex;
    setInternalTemp(98.6);
    setTotalBodyWater();
};


int HumanSim::calculateInternalTemp(int temp, int InternalTemp) // Function for calculating body temp
{
    double activityLevel;
    activityLevel = calculateActivityLevel();
    InternalTemp += activityLevel * 2;

    if(temp < 60)
    {
        InternalTemp -= 2;

    }else if(temp >= 60 && temp < 70)
    {
        InternalTemp -= 1;

    }
    else if (temp >  70 && temp <= 80) 
    {
        InternalTemp += 1;
    }
    else
    {
        InternalTemp += 2;
    }
    return InternalTemp;

    
}





    // getters and setters for Internal Temo
void HumanSim::setInternalTemp(int InternalTemp) // Setter for Internal temp
{
    this->internalTemp = InternalTemp; // base body temp
}

int HumanSim::getInternalTemp() // getter for Internal temp 
{
    return this->internalTemp;
}


