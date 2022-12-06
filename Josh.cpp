#include "StillsuitSim.h"
#include <iostream>
#include <string>
using namespace std;




//start heating process - not sure on amount to increase
auto StillsuitSim::startHeat()
{
    if (battery > 15)
    {
        
        outsideTemp +=  2;
        return outsideTemp;
    }
}

//start cooling process - not sure on amount to decrease
auto StillsuitSim::startAirCon()
{
    if (battery > 15) 
    {
        outsideTemp -= 2;
        return outsideTemp;
    }
}

//checking current internal temp to see if heat or cooling is needed, then calling needed function
auto StillsuitSim::checkTemperature()
{
    if (outsideTemp < 60)
    {
        return startHeat();
    }

    if (outsideTemp > 80)
    {
       
       return startAirCon();
    }

}