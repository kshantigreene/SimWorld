#include "HumanSim.h"

void HumanSim::getBattery()
{
    pair<int, int> battery = suit->batteryLevel(time);
    int batLevel = battery.first;
    int batTime = battery.second;
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
        double waterReq = suit->sendWater(neededWater);
        currentWL += waterReq;
        waterDrank = waterReq;
    }
    cout << "The human has drank " << waterDrank << "mLs.";
}