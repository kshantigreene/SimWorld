#include "HumanSim.h"
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
double HumanSim::calculateSweat(int temp, double InternalTemp) {
    
    // Average Temperature of Human
    InternalTemp = 98.6;

    // Current Temp of Human (may need additional data on this)
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


}

/// <summary>
/// Uses the Hume-Weyers formulas for calculating human's Total Body Water
/// and subtracts sweat from result to calculate how much water is lost
/// </summary>
/// <param name="h">Human's height (cm)</param>
/// <param name="w">Human's weight (kg)</param>
/// <param name="s">Human's sex (0 female, 1 male)</param>
/// <returns>Human's Total Body Water amount after sweating in liters</returns>
double HumanSim::calculateHydration(int h, int w, bool s) {
    double heightConst;
    double weightConst;
    double sexConst;
    double sweatAmnt = 0.0;             // in liters (default value ssumes Human hasn't begun sweating yet)
    const double SWEAT_WATER = 0.99;    // How much water is lost through sweat

    if (s == 0) {
        heightConst = 0.34454;
        weightConst = 0.183809;
        sexConst = 35.270121;
    }
    else {
        heightConst = 0.194786;
        weightConst = 0.296785;
        sexConst = 14.012934;
    }

    double formulaHW = (heightConst * h) + (weightConst * w) + (sexConst * s);  // Hume-Weyers Formula
    
    // sweat function for assigning sweatAmnt to a real value goes here if I knew how to use it

    sweatAmnt = sweatAmnt * SWEAT_WATER;
    double result = formulaHW - sweatAmnt;
    
    return result;
}

int HumanSim::calculateInternalTemp(int temp, int InternalTemp) // Function for calculating body temp
{
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
double HumanSim::calculateActivityLevel(int height, int weight, int age) {
    double bmrM = 66 + (13.7 * weight) + (5 * height) - (6.8 * age); // Harris-Benedict Formula
    double bmrF = 655 + (9.6 * weight) + (1.8 * height) - (4.7 * age);


    double sedentaryM = bmrM * 1.2;
    double lightActiveM = bmrM * 1.375;
    double moderateActiveM = bmrM * 1.55;
    double veryActiveM = bmrM * 1.725;
    double extraActiveM = bmrM * 1.9;

    double sedentaryF = bmrF * 1.2;
    double lightActiveF = bmrF * 1.375;
    double moderateActiveF = bmrF * 1.55;
    double veryActiveF = bmrF * 1.725;
    double extraActiveF = bmrF * 1.9;

    double levelResultM = 0.0;
    double levelResultF = 0.0;

    //you are converting a double to boolean.. 
    //I think you want a separate boolean and to use the variables in your computation depending on level
    if (extraActiveM == true)
    {
        levelResultM = 0.20;
    }
    else if (veryActiveM == true)
    {
        levelResultM = 0.40;
    }
    else if (moderateActiveM == true)
    {
        levelResultM = 0.60;
    }
    else if (lightActiveM == true)
    {
        levelResultM = 0.80;
    }
    else if (sedentaryM == true)
    {
        levelResultM = 0.1;
    }
    else
    {
        levelResultM = 0.0;


        if (extraActiveF == true)
        {
            levelResultF = 0.20;
        }
        else if (veryActiveF == true)
        {
            levelResultF = 0.40;
        }
        else if (moderateActiveF == true)
        {
            levelResultF = 0.60;
        }
        else if (lightActiveF == true)
        {
            levelResultF = 0.80;
        }
        else if (sedentaryF == true)
        {
            levelResultF = 0.1;
        }
        else
        {
            levelResultF = 0;
        }

        //can't return both, but you will know whether your person is M or F so you can access the member variable 
        return levelResultM;
        return levelResultF;
    }
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

void HumanSim::inAndOut()
{
   

    if (usingSuit)
    {
        //call suit to tell it whether in or out
    }
         


}

int HumanSim::evaporate(int sweat, int temp) {
    float evap = 0;
    evap = sweat / temp;
    evap = sweat / evap;
    int e = static_cast<int>(evap);
    return e;
}