#include "HumanSim.h"
#include <random>

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
        double neededWater = expectedWL - currentWL;
        neededWater += rand() % 10;
        double waterReq = suit->sendWater(neededWater);
        waterReq = encryption->decryptMsg(waterReq);
        currentWL += waterReq;
        waterDrank = waterReq;
    }
    cout << "The human has drank " << waterDrank << "mLs." << '\n';
}