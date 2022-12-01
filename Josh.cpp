#include "StillsuitSim.h"
#include <iostream>
#include <string>
using namespace std;
#include <vector>



//start heating process - not sure on amount to increase
void StillsuitSim::startHeat(int temp)
{
    temp += 2;
}

//start cooling process - not sure on amount to decrease
void StillsuitSim::startAirCon(int temp)
{
    temp -= 2;
}

//checking current internal temp to see if heat or cooling is needed, then calling needed function
void StillsuitSim::checkTemperature(int temp)
{
    if (temp < 60)
    {
        startHeat(temp);
    }

    if (temp > 80)
    {
        startAirCon(temp);
    }

}