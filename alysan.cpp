#include "HumanSim.h"

// Calculates the level of activity as a percentage (double) based on weight, height, age
double HumanSim::calculateActivityLevel() {
    double bmrM = 66 + (13.7 * weight) + (5 * height) - (6.8 * age); // Harris-Benedict Formula
    double bmrF = 655 + (9.6 * weight) + (1.8 * height) - (4.7 * age);

    double currentActivityLevel = 1;

    if (sex == true)
    {
        currentActivityLevel = bmrM * currentActivity / bmrM * EXTRAACTIVE;
    }
    else
    {
        currentActivityLevel = bmrF * currentActivity / bmrF * EXTRAACTIVE;
    }
    
    cout << "Calculation of the activity level is " << currentActivityLevel;
    return currentActivityLevel;
}

/* sending activity level and in/out of suit to suit */
