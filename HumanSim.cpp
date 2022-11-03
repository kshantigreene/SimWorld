#include "HumanSim.h"

HumanSim::HumanSim(string n, StillsuitSim* suit) {
	this->name = name;
    this->suit = suit;
};

void HumanSim::setWorldInfo(int time,int temp) {
	this->worldTemp = temp;
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
/// Subtracts sweat from result to calculate how much water is lost
/// </summary>
/// <param name="h">Human's height</param>
/// <param name="w">Human's weight</param>
/// <param name="s">Human's sex</param>
/// <returns>Human's Total Body Water amount after sweating in liters</returns>
double HumanSim::calculateHydration(int h, int w, bool s) {
    double heightConst;
    double weightConst;
    double sexConst;
    double sweatAmnt = 0.0;             // Assumes Human hasn't begun sweating yet
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

int HumanSim::CalculateInternalTemp(int temp, int InternalTemp) // Function for calculating body temp
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
    // getters and setters for Internal Temo
void HumanSim::setInternalTemp(int Internaltemp) // Setter for Internal temp
{
    InternalTemp = 98; // base body temp
}
int HumanSim::CheckInternalTemp(int Internaltemp) // getter for Internal temp 
{
    return Internaltemp;
}