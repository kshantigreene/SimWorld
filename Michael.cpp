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
    srand(std::time(0));
    if (maybeSuit == true) // if this is true will randomize whether they are using the suit or not 
    {
        
        int r = rand() % 10;
        // they are in the suit 
        if (r > 3)
        {

            usingSuit = true;
            
        }

        // they are not in the suit 
        if (r <= 3)
        {
            usingSuit = false;
         


        }
    }
    // ends the first argument seeing if usingsuit or not 
    else
    {
        usingSuit = false;
     

    }
   // checks if its not equal but the suit is still being used itll show
    if (test != usingSuit)
    {
        // test is true the suit is bing used 
        if (usingSuit == true)
        {
            cout << "suit is being used";
        }
        // checks to see if usingsuit is being used or not 
        else if (usingSuit == false)
        {
            cout << " suit is not being used";

        }
        
    }
    return usingSuit;
    
}
