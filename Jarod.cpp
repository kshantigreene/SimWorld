#include "StillsuitSim.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

double StillsuitSim::getAvailableWater() {
    return waterStg;
}

// Sends the water to the human to drink
int StillsuitSim::sendWater(double amountRequested) {
    int waterToSend;
    if (amountRequested > waterStg) {
        waterToSend = int (waterStg);
        cout << "Amount of water requested is larger than the amount in storage. Sending " << waterToSend << "ml of water." << endl;
        waterStg = 0;
        cout << "There is " << waterStg << "ml of water remaining." << endl;
        waterToSend = encryption->encryptMsg(waterToSend);
        return waterToSend;
    }
    else {
        waterToSend = int (amountRequested);
        waterStg = waterStg - waterToSend;
        cout << "Sending " << waterToSend << "ml of water." << endl << "There is " << waterStg << "ml of water remaining." << endl;
        waterToSend = encryption->encryptMsg(waterToSend);
        return waterToSend;
    }
}

// Calculates the suit's weight and returns its weight in kilograms
double StillsuitSim::calculateSuitWeight() {
    double waterWeight = waterStg / 1000;
    double suitWeight = emptySuitWeight + waterWeight;

    return suitWeight;
}

// Sets the humanInSuit bool variable to the inSuit argument
void StillsuitSim::setInSuit(bool inSuit) {
    this->inSuit = inSuit;
}