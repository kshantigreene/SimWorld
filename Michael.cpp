#include "HumanSim.h"
#include "StillsuitSim.h"
#include <iostream>
#include "StillsuitSim.h"
#include <string>
#include <cstdlib>
using namespace std;
#include <vector>

bool HumanSim::HumanLocation(bool maybeSuit)

 
{
    if (maybeSuit == true) // if this is true will randomize whether they are using the suit or not 
    {

        int r = rand() % 10;
        // they are in the suit 
        if (r > 5)
        {
            
           usingSuit = true;
           return usingSuit;
        }
        
// they are not in the suit 
        if (r < 5)
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
}

