#include "HumanSim.h"
#include "StillsuitSim.h"
#include <cmath>
using std::log;

HumanSim::HumanSim(string n, StillsuitSim* suit) {
	this->name = name;
    this->suit = suit;
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

/// <summary>
/// Uses the Hume-Weyers formula for initializing human's Total Body Water (only called once)
/// </summary>
void HumanSim::setTotalBodyWater() {

    // Variables
    double heightConst;
    double weightConst;
    double sexConst;

    // Constants depending on sex of human
    if (sex == 0) {
        heightConst = 0.34454;
        weightConst = 0.183809;
        sexConst = 35.270121;
    }
    else {
        heightConst = 0.194786;
        weightConst = 0.296785;
        sexConst = 14.012934;
    }

    currentWL = (heightConst * height) + (weightConst * weight) + (sexConst * sex);  // Hume-Weyers Formula
    expectedWL = currentWL;

}

/// <summary>
/// Subtracts water loss from sweat and urine from current total body water of human
/// </summary>
/// <returns>Human's Total Body Water amount after sweat/urine outtake in liters</returns>
void HumanSim::calculateHydration() {
    double sweatAmnt = 0.0;             // in liters (default value ssumes Human hasn't begun sweating yet)
    const double SWEAT_WATER = 0.99;    // How much water is lost through sweat

    // Same as above but for urine
    double urineAmnt = 0.0;
    const double URINE_WATER = 0.95;
    
    // calculates how much water is lost through sweat and urine
    sweatAmnt += sweat;
    sweatAmnt = sweatAmnt * SWEAT_WATER;
    // urineAmnt += urine;                                      Waiting until urine function is ready
    urineAmnt = urineAmnt * URINE_WATER;
    
    currentWL = currentWL - sweatAmnt - urineAmnt;
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


// Calculates the level of activity as a percentage (double) based on weight, height, age
double HumanSim::calculateActivityLevel() {
    double bmrM = 66 + (13.7 * weight) + (5 * height) - (6.8 * age); // Harris-Benedict Formula
    double bmrF = 655 + (9.6 * weight) + (1.8 * height) - (4.7 * age);


    double sedentaryM = bmrM * 1.2; //delete
    double lightActiveM = bmrM * 1.375;
    double moderateActiveM = bmrM * 1.55;
    double veryActiveM = bmrM * 1.725;
    double extraActiveM = bmrM * 1.9;

    double sedentaryF = bmrF * 1.2; //delete
    double lightActiveF = bmrF * 1.375;
    double moderateActiveF = bmrF * 1.55;
    double veryActiveF = bmrF * 1.725;
    double extraActiveF = bmrF * 1.9;

    return 0;
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

void HumanSim::HumanLocation()
{
   

    if (usingSuit)
    {
        //call suit to tell it whether inside  or outside 
    }
         


}



