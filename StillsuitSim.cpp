#include "StillsuitSim.h"
#include <iostream>
using namespace std;

StillsuitSim::StillsuitSim() {
};

void StillsuitCompoundID()
{
    string water = "This is water.";
    string urea = "This is urea.";
    string chloride = "This is chloride.";
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

