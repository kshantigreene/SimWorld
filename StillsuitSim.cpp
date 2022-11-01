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

void StillsuitSim::seperateFluid() {
    int fluid2[10];
    int fluid = 123456;
    for (int i = 0; i < 10; i++)
    {
        fluid2[i] = fluid % 10; fluid /= 10;
    }
}


int urineAmount;
int sweatAmount;
//getters and settings for urine
void setUrine(int urine)
{
    int urineAmount = urineAmount + urine;
}

int getUrine()
{
    return urineAmount;
}
//getters and settings for sweat
void setSweat(int sweat)
{
    int sweatAmount = sweatAmount + sweat;
}

int getSweat()
{
    return sweatAmount;
}

//start heating process - not sure on amount to increase
void startHeat(int temp) 
{
    temp += 2;
}

//start cooling process - not sure on amount to decrease
void startAirCon(int temp) 
{
    temp -= 2;
}

//checking current internal temp to see if heat or cooling is needed, then calling needed function
void checkTemperature(int temp) 
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

