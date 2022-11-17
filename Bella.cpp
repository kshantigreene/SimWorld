#include "HumanSim.h"
using namespace std;
//find the amount of sweat that gets evaporated from the body in a precent

int HumanSim::evaporate(int sweat, int temp) {
    float evap = 0;
    evap = sweat / temp;
    evap = sweat / evap;
    int e = static_cast<int>(evap);
    return e;
}