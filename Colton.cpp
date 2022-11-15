#include "StillsuitSim.h"
#include <iostream>
#include <string>
using namespace std;

void StillsuitSim::liquidPurifier(char liquidElem) {
    if (liquidElem == '2') {
        if (waterStg + 0.95 <= MAX_waterStg) {
            cout << "Urine purified." << endl;
            waterStg += 0.95;
        }
    }
    if (liquidElem == '3') {
        if (waterStg + 0.99 <= MAX_waterStg) {
            cout << "Sweat purified." << endl;
            waterStg += 0.99;
        }
    }
    else {
        cout << "The given character ID is invalid." << endl;
    }
}

void StillsuitSim::StillsuitCompoundID()
{
    // Converts incoming liquid integer to a string and stores it in a new string variable
    string strLiquid = to_string(incomingLiquid);

    // Declaration of FOR loop and index for the purpose of iterating through liquid string
    size_t index = 0;
    for (char c : strLiquid)
    {
        bool identified = false;

        // If string char is 1, then add 1 to water storage variable
        if (c == '1')
        {
            identified = true;
            waterStg = +1;
        }

        // If string char isn't 1, then call liquidPurifier function and pass c variable to it
        else {
            identified = true;
            liquidPurifier(c);
        }
        index++;
    }
}