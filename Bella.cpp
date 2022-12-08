#include "HumanSim.h"
using namespace std;
//find the amount of sweat that gets evaporated from the body in a precent

int HumanSim::evaporate(int sweat, int temp) {
    float evap = 0;
    evap = sweat / temp;
    evap = sweat / evap;
    int e = static_cast<int>(evap);
    return e;
}

//human daily activity int time based sections
int HumanSim::activity(int time, int hour, int minute) {
    
    activityChange = currentActivity;
    bool maybeSuit;
    if (hour < 8) {
        //human is sleeping
        currentActivity = 1;
        maybeSuit = false;
    }
    else if ((hour >= 8) && (hour < 9)) {
        //this is waking up and eating breakfast
        currentActivity = 3;
        maybeSuit = false;
    }
    else if ((hour >= 9) || (hour < 12)) {
        //go out and start working
        currentActivity = 8;
        maybeSuit = true;
    }
    else if ((hour == 12) && (minute < 45)) {
        //eating lunch(or break)
        currentActivity = 4;
        maybeSuit = true;
    }
    else if ((hour == 12) && (minute >= 45)) {
        //getting mindset to go back to work (not really working but kinda are)
        currentActivity = 6;
        maybeSuit = true;
    }
    else if ((hour >= 13) || (hour < 17)) {
        //working
        currentActivity = 8;
        maybeSuit = true;
    }
    else if ((hour <= 17) || (hour < 18)) {
        //making dinner
        currentActivity = 7;
        maybeSuit = true;
    }
    else if ((hour >= 18) && (minute <= 35)) {
        //eating
        currentActivity = 4;
        maybeSuit = false;
    }
    else if ((hour >= 19) && (minute <= 45)) {
        //work out
        currentActivity = 9;
        maybeSuit = true;
    }
    else if ((hour >= 20) && (minute > 45)) {
        //get shower (no suit)
        currentActivity = 5;
        maybeSuit = false;
    }
    else if ((hour >= 21) && (minute < 30)) {
        //relaxing
        currentActivity = 2;
        maybeSuit = true;
    }
    else if ((hour >= 22) && (minute >= 30)) {
        //get ready for bed
        currentActivity = 4;
        maybeSuit = false;
    }
    else if (hour >= 23) {
        //sleeping
        currentActivity = 1;
        maybeSuit = false;
    }
    else {
        //mini break
        currentActivity = 3;
        maybeSuit = true;
    }
    //check to see if the activity changed
    if (activityChange != currentActivity) {
        cout << currentActivity << " this is the new activity" << endl;
    }
    HumanLocation(maybeSuit);
    return currentActivity;
}