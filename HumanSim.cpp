#include "HumanSim.h"

HumanSim::HumanSim(string n, StillsuitSim* suit) {
	this->name = name;
    this->suit = suit;
};

void HumanSim::setWorldInfo(int time,int temp) {
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
void HumanSim::calculateSweat(int time, int temp, int weight) {
    this->worldTemp = temp;
    int hour = (int)time / 60;


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

        return levelResultM;
        return levelResultF;
    }
}
    // getters and setters for Internal Temo
void HumanSim::setInternalTemp() // Setter for Internal temp
{
    this->internalTemp = 98.6; // base body temp
}
int HumanSim::getInternalTemp() // getter for Internal temp 
{
    return this->internalTemp;
}
    return Internaltemp;
}

void HumanSim::inAndOut()
{
   

    if (usingSuit)
    {
        //call suit to tell it whether in or out
    }
         


}