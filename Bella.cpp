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
    if (hour < 8) {
        //human is sleeping
        int currentActivity = 1;
        return currentActivity;
    }
    else if ((hour <= 8) && (hour < 9)) {
        //this is waking up and eating breakfast
        int currentActivity = 3;
        return currentActivity;
    }
    else if ((hour <= 9) || (hour < 12)) {
        //go out and start working
        int currentActivity = 8;
        return currentActivity;
    }
    else if ((hour == 12) && (minute < 45)) {
        //eating lunch(or break)
        int currentActivity = 4;
        return currentActivity;
    }
    else if ((hour == 12) && (minute >= 45)) {
        //getting mindset to go back to work (not really working but kinda are)
        int currentActivity = 6;
        return currentActivity;
    }
    else if ((hour <= 13) || (hour < 17)) {
        //working
        int currentActivity = 8;
        return currentActivity;
    }
    else if ((hour <= 17) || (hour < 18)) {
        //making dinner
        int currentActivity = 7;
        return currentActivity;
    }
    else if ((hour <= 18) && (minute <= 35)) {
        //eating
        int currentActivity = 4;
        return currentActivity;
    }
    else if ((hour <= 19) && (minute <= 45)) {
        //work out
        int currentActivity = 9;
        return currentActivity;
    }
    else if ((hour <= 20) && (minute > 45)) {
        //get shower (no suit)
        int currentActivity = 5;
        return currentActivity;
    }
    else if ((hour <= 21) && (minute < 30)) {
        //relaxing
        int currentActivity = 2;
        return currentActivity;
    }
    else if ((hour <= 22) && (minute >= 30)) {
        //get ready for bed
        int currentActivity = 4;
        return currentActivity;
    }
    else if (hour >= 23) {
        //sleeping
        int currentActivity = 1;
        return currentActivity;
    }
    else {
        //mini break
        int currentActivity = 3;
        return currentActivity;
    }

}