#include "HumanSim.h"

/// <summary>
/// Uses the Hume-Weyers formula for initializing human's Total Body Water (only called once)
/// </summary>
void HumanSim::setTotalBodyWater() {

    // Variables
    double heightConst;
    double weightConst;
    double sexConst;

    // Constants depending on sex of human
    if (sex == 0) {
        heightConst = 0.34454;
        weightConst = 0.183809;
        sexConst = 35.270121;
    }
    else {
        heightConst = 0.194786;
        weightConst = 0.296785;
        sexConst = 14.012934;
    }

    currentWL = (heightConst * height) + (weightConst * weight) + (sexConst * sex);  // Hume-Weyers Formula
    expectedWL = currentWL;

}

/// <summary>
/// Subtracts water loss from sweat and urine from current total body water of human
/// </summary>
/// <returns>Human's Total Body Water amount after sweat/urine outtake in liters</returns>
void HumanSim::calculateHydration() {
    double sweatAmnt = 0.0;             // in liters (default value assumes Human hasn't begun sweating yet)
    const double SWEAT_WATER = 0.99;    // How much water is lost through sweat

    // Same as above but for urine
    double urineAmnt = 0.0;

    const double URINE_WATER = 0.95;

    // calculates how much water is lost through sweat and urine
    sweatAmnt += sweat;
    sweatAmnt = sweatAmnt * SWEAT_WATER;
    // urineAmnt += urine;                                      Waiting until urine function is ready
    urineAmnt = urineAmnt * URINE_WATER;

    currentWL = currentWL - sweatAmnt - urineAmnt;
}

void HumanSim::updateHuman(int time, int temp) {
    this->worldTemp = temp;
    this->time = time;
    this->usingSuit = true;
    int hour = (int)time / 60;
    int minute = time;
    if (hour > 0) {
        minute = time - hour * 60;
    }
    printf("Current time is: %02d:%02d, %dF\n", hour, minute, temp);

    // Updates the Human's statistics
    cout << "Calculating Human's internal temperature... " << endl;
    calculateInternalTemp(temp, internalTemp);
    cout << "Calculating Human's current activity level... " << endl;
    activity(time, hour, minute);


    

    cout << "Calculating Human's current location... " << endl;
    HumanLocation();

    cout << "Calculating Human's sweat production... " << endl;
    calculateSweat(internalTemp);

    cout << "Calculating Human's urine production... " << endl;
    calculateUrine(weight);

    cout << "Calculating Human's current hydration level... " << endl;
    calculateHydration();

    // Logic for when the Human should drink
    // Runs every 10 minutes while the Human is wearinig its Stillsuit
    int check = minute % 10;
    usingSuit = true;
    currentWL--;
    if (usingSuit && check == 0) {
        cout << "The Human checks if they are thirsty... " << endl;
        amountDrank();
    }
}