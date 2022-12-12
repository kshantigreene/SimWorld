#include "HumanSim.h"
#include "StillsuitSim.h"
#include <iostream>
#include "StillsuitSim.h"
#include <string>
#include <cstdlib>
using namespace std;
#include <vector>
#include <random>
#include <time.h>

bool HumanSim::HumanLocation(bool maybeSuit)
{
    bool test = usingSuit;
    if (maybeSuit) // if this is true will randomize whether they are using the suit or not 
    {

        int r = rand() % 10;
        // they are in the suit 
        if (r > 3)
        {

            usingSuit = true;
            return usingSuit;

        }

        // they are not in the suit 
        if (r <= 3)
        {
            usingSuit = false;
            return usingSuit;


        }
    }
    else
    {
        usingSuit = false;
        return usingSuit;

    }
    if (test != usingSuit)
    {
        if (usingSuit == true)
        {
            cout << "suit is being used";
        }
        else if (usingSuit == false)
        {
            cout << " suit is not being used";
        }
    }
    
}
