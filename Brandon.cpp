#include <iostream>
#include "StillsuitSim.h"
#include "HumanSim.h"
#include <string>
#include <vector>
using namespace std;

double StillsuitSim::batteryLevel(int time, double currentActivityLevel)
{
    while (inSuit == true)
    {


        //assigns values to variables
        int batteryLevel = 100;
        int maxBatteryTime = 720;

        //uses worldtime to find how many minuites are left in the battery
        int batteryTimeLeft;
        batteryTimeLeft = maxBatteryTime - worldTime;

        // every minute called, battery level lowers by 1 minute
        battery = (1 - currentActivityLevel);

        if (battery < 15) {
            cout << "Battery is low." << endl;
        }

        return battery;
    }
}