#include <iostream>
#include "StillsuitSim.h"
#include <string>
using namespace std;
#include <vector>
pair<int, int> StillsuitSim::batteryLevel(int time)
{
    //assigns values to variables
    int batteryLevel = 100;
    int maxBatteryTime = 720;

    //uses worldtime to find how many minuites are left in the battery
    int batteryTimeLeft;
    batteryTimeLeft = maxBatteryTime - worldTime;

    //uses simple math to make a percent of the batter left
    batteryLevel = (batteryTimeLeft / maxBatteryTime) * 100;

    //returns the value of the battery level and batter time
    return std::make_pair(batteryLevel, batteryTimeLeft);
}