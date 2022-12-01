#include "HumanSim.h"
#include "StillsuitSim.h"
#include <iostream>
#include "StillsuitSim.h"
#include <string>
using namespace std;
#include <vector>

bool HumanSim::HumanLocation()

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

