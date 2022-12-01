#include "HumanSim.h"
#include "StillsuitSim.h"
#include <cmath>
using std::log;

HumanSim::HumanSim(string n, StillsuitSim* suit) {
    this->name = name;
    this->suit = suit;
    this->currentActivity = MODERATEACTIVE; // FOR NOW (ADDED THIS)
    setInternalTemp(98.6);
    setTotalBodyWater();                    // Will remove this entire constructor once implementation added for the other (full) constructor in simworld
};

HumanSim::HumanSim(string n, StillsuitSim* suit, double currentActivity, int age, int height, int weight, bool sex) {
	this->name = name;
    this->suit = suit;
    this->currentActivity = currentActivity;
    this->age = age;
    this->height = height;
    this->weight = weight;
    this->sex = sex;
    setInternalTemp(98.6);
    setTotalBodyWater();
};







