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
    currentWL = currentWL * 1000;   // convert currentWL from L to mL
    expectedWL = currentWL;

}

/// <summary>
/// Subtracts water loss from sweat and urine from current total body water of human
/// </summary>
/// <returns>Human's Total Body Water amount after sweat/urine outtake in liters</returns>
void HumanSim::calculateHydration() {
    double sweatAmnt = sweat;             // in liters (default value assumes Human hasn't begun sweating yet)
    const double SWEAT_WATER = 0.99;    // How much water is lost through sweat

    // Same as above but for urine
    double urineAmnt = bladderCapacity;
    const double URINE_WATER = 0.95;

    // calculates how much water is lost through sweat and urine
    sweatAmnt = sweatAmnt * SWEAT_WATER;
    urineAmnt = urineAmnt * URINE_WATER;
    cout << "current hydration: " << currentWL / expectedWL << endl;
    currentWL = currentWL - sweatAmnt - urineAmnt;
}

// Is the human dead?
bool HumanSim::calculateDeath() {
    bool isDead = false;

    // Calculate death based on hydration percentage (lacking 10% or more total body water brings death)
    double hydrationPercent = currentWL / expectedWL;
    if (hydrationPercent <= 0.9) {
        cout << "I'm so thirsty!!!!";
        isDead = true;
    }

    // Calculate death based on internal temperature (internal temp of 104 degrees fahrenheit brings death)
    if (internalTemp >= 104) {
        cout << "Turn on the AC!";
        isDead = true;
    }
    else if (internalTemp <= 94) {
        cout << "I'm so cold!!";
        isDead = true;
    }

    return isDead;

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

    if (hour == 15 && minute == 44) {
        int x = 0;
    }
    activity(time, hour, minute);
    cout << endl;

    double activityLevel = calculateActivityLevel();
    if (usingSuit) {
        try {

            // Updates the Human's statistics
            cout << "Calculating Human's internal temperature... " << endl;
            double suitTemp = suit->checkTemperature();
            calculateInternalTemp(suitTemp, activityLevel);

            if (internalTemp > 98.6) {
                int x = 8;
            }
            cout << "Calculating Human's sweat production... " << endl;
            calculateSweat(internalTemp);

            cout << "Calculating Human's urine production... " << endl;
            calculateUrine(weight);

            cout << "Calculating Human's current hydration level... " << endl;
            calculateHydration();

            // Logic for when the Human should drink
            // Runs every 10 minutes while the Human is wearinig its Stillsuit
            int check = minute % 10;
            currentWL--;
            if (check == 0) {
                cout << "The Human checks if they are thirsty... " << endl;
                amountDrank();
            }
        }
        catch (exception e) {
            e.what();
        }
    }
}