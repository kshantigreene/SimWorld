#include "HumanSim.h"

HumanSim::HumanSim(string n) {
	this->name = name;
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