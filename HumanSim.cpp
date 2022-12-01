#include "HumanSim.h"
#include "StillsuitSim.h"
#include <cmath>
using std::log;



HumanSim::HumanSim(string n, StillsuitSim* suit) {
	this->name = name;
    this->suit = suit;
    this->currentActivity = MODERATEACTIVE; // FOR NOW
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








