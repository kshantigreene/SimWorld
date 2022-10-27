#include "StillsuitSim.h"
#include <iostream>
using namespace std;

StillsuitSim::StillsuitSim(HumanSim* h) {
	this->human = h;
};

int StillsuitSim::StillsuitCompoundID()
{
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
            cout << "This is water." << endl;
        }
        if (c == '2')
        {
            identified = true;
            cout << "This is urea." << endl;
        }
        if (c == '3')
        {
            identified = true;
            cout << "This is chloride." << endl;
        }
        if (c == '4')
        {
            identified = true;
            cout << "This is sodium." << endl;
        }
        if (c == '5')
        {
            identified = true;
            cout << "This is creatinine." << endl;
        }
        if (c == '6')
        {
            identified = true;
            cout << "This is potassium." << endl;
        }
        if (c == '7')
        {
            identified = true;
            cout << "This is calcium." << endl;
        }
        if (c == '8')
        {
            identified = true;
            cout << "This is magnesium." << endl;
        }
        if (!identified)
        {
            cout << "This compound is undefined. Please enter a defined compound." << endl;
        }
        index++;
    }
}