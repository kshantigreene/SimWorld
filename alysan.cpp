#include "HumanSim.h"

/*

HumanSim::HumanSim(string n, StillsuitSim* suit) {
    this->name = name;
    this->suit = suit;
    this->currentActivity = MODERATEACTIVE; // FOR NOW (ADDED THIS)
};

*/

// Calculates the level of activity as a percentage (double) based on weight, height, age
double HumanSim::calculateActivityLevel() {
    double bmrM = 66 + (13.7 * weight) + (5 * height) - (6.8 * age); // Harris-Benedict Formula
    double bmrF = 655 + (9.6 * weight) + (1.8 * height) - (4.7 * age);

    double currentActivityLevel = bmrM * currentActivity / bmrM * EXTRAACTIVE;
    return currentActivityLevel;
}

/* 
    HumanSim.h includes the:
    public:
    - double calculateActivityLevel();
    private:
    - int age;
    - double currentActivity;
    - double activityLevel
*/

// sending activity level and in/out of suit to suit