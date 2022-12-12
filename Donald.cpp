#include "HumanSim.h"

void HumanSim::getBattery()
{
    double battery = suit->batteryLevel(time, currentActivity);
}

void HumanSim::getAvailWater()
{
    double water = suit->getAvailableWater();
}

void HumanSim::getWater()
{
    double newWater = suit->sendWater(1.0);
}

int HumanSim::getSuitWeight()
{
    int sWeight = suit->calculateSuitWeight();
    return sWeight;
}

void HumanSim::amountDrank()
{
    if (currentWL < expectedWL)
    {
        double avialWater = suit->getAvailableWater();
        double randAmount = (rand() % 100)/10.0;
        
        double neededWater = expectedWL - currentWL+randAmount;
        double waterReq = suit->sendWater(neededWater);
        currentWL += waterReq;
        waterDrank = waterReq;
    }
    cout << "The human has drank " << waterDrank << "mLs." << " Current water level: "<< currentWL << '\n';
}