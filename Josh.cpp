#include "StillsuitSim.h"
#include <iostream>
#include <string>
using namespace std;




//start heating process - not sure on amount to increase
auto StillsuitSim::startHeat()
{
    if (battery > 15)
    {

        double suitTemp = outsideTemp + 2;
        return suitTemp;
    }
    else return outsideTemp;
}

//start cooling process - not sure on amount to decrease
auto StillsuitSim::startAirCon()
{
    if (battery > 15) 
    {
        double suitTemp = outsideTemp - 2;
        return suitTemp;
    }
    else return outsideTemp;
}

//checking current internal temp to see if heat or cooling is needed, then calling needed function
double StillsuitSim::checkTemperature()
{
    if (outsideTemp < 60)
    {
        return startHeat();
    }

    else if (outsideTemp > 80)
    {
       
       return startAirCon();
    }
    else 
    {
        return outsideTemp;
    }

}