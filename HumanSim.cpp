#include "HumanSim.h"
#include <cmath>
using std::log;

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
void HumanSim::calculateSweat(int temp) {
    
    // Average Temperature of Human
    double avgBodyTemp = 98.6;

    // Current Temp of Human (may need additional data on this)
    double currentTemp;

    // Human's rest liters per hour
    double restLPerHr = 0.8;

    // Human's active liters per hour
    double activeLPerHr = 1.4;

    // active milliliters (ML) per minute equation
    // 
    // Doing activeLPerHr divided by 60 gives you 0.023 mL per minute.
    // Rounding to three decimal places to the right gives us 23 mL/min.
    double activeMLperMin = (round(activeLPerHr/60));
    
    // Random number picked as a placeholder on the graph.
    double x = 19.6;

    // Range of active milliliters (ML) equation
    // 
    // This equation rises up graphically where it starts at 0 and gets close but not equal to 25.
    double rangeOfactiveML = (25-1/log(x+1));

    // The amount a human can sweat per hour.
    // 
    // Note: Need current temp from others.
    //
    double amountOfSweatPerMin = ((currentTemp - (avgBodyTemp * 10))*60);
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

    // The max amount of urine that can be produced.
    //
    // This equation takes the maxMLPerKgPerHr variable, times the activityLevel, times the weight of the human in kg.
    // 
    // Note: Human's weight must be converted to kg if not already for this equation. Can be converted to pounds later if needed.
    //
    double maxUrineProducedPerHr = ((maxMLPerKgPerHr * activityLevel) * weight);


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