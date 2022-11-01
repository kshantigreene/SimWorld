#include "StillsuitSim.h"
#include <iostream>
using namespace std;

StillsuitSim::StillsuitSim() {
};

void StillsuitCompoundID()
{
    string water = "This is water.";
    string urea = "This is urea.";
    string chloride = "This is urea.";
    string sodium = "This is sodium.";
    string creatinine = "This is creatinine.";
    string potassium = "This is potassium.";
    string calcium = "This is calcium.";
    string magnesium = "This is magnesium.";
    string error = "This compound is undefined. Please enter a defined compound.";

    string digits;
    cin >> digits;
    size_t index = 0;
    for (char c : digits)
    {
        bool identified = false;
        cout << c << endl;
        if (c == '1')
        {
            identified = true;
            cout << water << endl;
        }
        if (c == '2')
        {
            identified = true;
            cout << urea << endl;
        }
        if (c == '3')
        {
            identified = true;
            cout << chloride << endl;
        }
        if (c == '4')
        {
            identified = true;
            cout << sodium << endl;
        }
        if (c == '5')
        {
            identified = true;
            cout << creatinine << endl;
        }
        if (c == '6')
        {
            identified = true;
            cout << potassium << endl;
        }
        if (c == '7')
        {
            identified = true;
            cout << calcium << endl;
        }
        if (c == '8')
        {
            identified = true;
            cout << magnesium << endl;
        }
        if (!identified)
        {
            cout << error << endl;
        }
        index++;
    }
}

void StillsuitSim::setTime(int time) {
    this->worldTime = time;
}

int StillsuitSim::batteryAlert(int time)
{
    //assigns values to variables
    int batteryLevel = 100;
    int maxBatteryTime = 720;

    //uses worldtime to find how many minuites are left in the battery
     int batteryTimeLeft;
    batteryTimeLeft = maxBatteryTime - worldTime;

    //uses simple math to make a percent of the batter left
    batteryLevel = (batteryTimeLeft / maxBatteryTime) * 100;
    
    //checks the level to see if its critical
    if (batteryLevel < 30)
    {
        return 1;
    }
    else
    {
        return 0;
    }

    //returns the value of the battery level and batter time
    return batteryLevel, batteryTimeLeft;
}