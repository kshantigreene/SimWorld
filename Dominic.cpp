#include "HumanSim.h"
#include "StillsuitSim.h"
#include <cmath>

int HumanSim::calculateInternalTemp(int temp, int InternalTemp) // Function for calculating body temp
{
    double activityLevel;
    activityLevel = calculateActivityLevel();
    InternalTemp += activityLevel * 2;

    if (temp < 60)
    {
        InternalTemp -= 2;

    }
    else if (temp >= 60 && temp < 70)
    {
        InternalTemp -= 1;

    }
    else if (temp > 70 && temp <= 80)
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