#include "HumanSim.h"
#include "StillsuitSim.h"
#include <cmath>

double HumanSim::calculateInternalTemp(int temp, double activityLevel) // Function for calculating body temp
{
    double internalTemp = 98.6;  // base human temp

    internalTemp += activityLevel * 2;

    if (temp < 60)                           // calculates human temp off outside temp
    {
        internalTemp -= 2;

    }
    else if (temp >= 60 && temp < 70)
    {
        internalTemp -= 1;

    }
    else if (temp > 70 && temp <= 80)
    {
        internalTemp += 1;
    }
    else
    {
        internalTemp += 2;
    }

    std::cout << internalTemp << "F is your current internal temperature" << std::endl;

    return internalTemp;




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