#include "HumanSim.h"
#include "StillsuitSim.h"
#include <cmath>
using std::log;



HumanSim::HumanSim(string n, StillsuitSim* suit) {
	this->name = name;
    this->suit = suit;
    this->currentActivity = MODERATEACTIVE; // FOR NOW
};

void HumanSim::updateHuman(int time,int temp) {
	this->worldTemp = temp;
    this->time = time;
    this->usingSuit = true;
    int hour = (int)time / 60;
    int minute = time;
    if (hour > 0) {
        minute = time - hour * 60;
    }
    printf("Current time is: %02d:%02d, %dF\n", hour, minute, temp);
}



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


