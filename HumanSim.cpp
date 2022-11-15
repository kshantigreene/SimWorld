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

// Calculates the sweat based on activity, temperature and weight (including suit)
double HumanSim::calculateSweat(int temp, double InternalTemp, int weight) {
    
    // Average Temperature of Human
    InternalTemp = 98.6;

    // Current Temp of Human (may need additional data on this from others)
    double currentTemp=98.6;

    // Curent milliliters for an active male.
    const double MAX_SWEAT = 23;
    
    // Calculates the temperature the human has overheated.
    //
    // This equation looks at the current temperature minus the average body temperature (98.6).
    double tempOverheated = (currentTemp - InternalTemp);

    // Range of active milliliters (ML) equation
    // 
    // This equation rises up graphically where it starts at 0 and gets close but not equal to 25.
    double sweat = (MAX_SWEAT - 1 / log(tempOverheated + 1));

    return sweat;
}

// Calculates the urine based on activity level and amount to drink.
void HumanSim::calculateUrine(int weight) {

    // Based on activity and amount to drink (you can assume they are getting 
    // water from outside if the suit isn’t providing enough)

    // Compositions of urine variables

    // Percentage of urine composed of water.
    double urineComposedOfWater = 0.95;

    // Percentage of urine composed of urea.
    double urineComposedOfUrea = 0.2;

    // Percentage of urine composed of creatinine.
    double urineComposedOfCreatinine = 0.1;

    // Percentage of urine composed of uric acid.
    double urineComposedOfUricAcid = 0.03;

    // The max activity used in urine function. (Human)
    double activityLevel = 1.0;

    // The max amount of milliliters per kilograms per hour.
    double maxMLPerKgPerHr = 1.5;

    // The max amount of urine that can be produced per minute.
    //
    // This equation takes the maxMLPerKgPerHr variable, times the activityLevel, times the weight of the human in kg.
    //
    // Note: Does NOT take into account the percentages of urine above yet.
    //
    double maxUrineProducedPerMin = (((maxMLPerKgPerHr * activityLevel) * weight)*60);

    this->bladderCapacity++;

    // Comes from Hydration function
    double hydration=0.0;

    // Comes from Drinking Function
    double drinkingWater=0.0;

    // (Hydration + Drinking) * percentageOfWater
    double urine = (hydration + drinkingWater) * urineComposedOfWater;
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



