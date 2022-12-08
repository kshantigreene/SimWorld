#include "HumanSim.h"

// Calculates the level of activity as a percentage (double) based on weight, height, age
double HumanSim::calculateActivityLevel() {
    
    double suitWeight = suit->calculateSuitWeight();
    double totalWeight = weight + suitWeight;

    double bmrM = 66 + (13.7 * totalWeight) + (5 * height) - (6.8 * age); // Harris-Benedict Formula
    double bmrF = 655 + (9.6 * totalWeight) + (1.8 * height) - (4.7 * age);

    double currentActivityLevel = 1;

    if (sex == true)
    {
        currentActivityLevel = bmrM / 7100 * currentActivity / EXTRAACTIVE; // average man has BMR of 7,100 kJ per day
    }
    else
    {
        currentActivityLevel = bmrF / 5900 * currentActivity /  EXTRAACTIVE; // average female has BMR of 5,900 kJ per day
    }
    
    cout << "Calculation of the activity level is " << currentActivityLevel;
    return currentActivityLevel;
}