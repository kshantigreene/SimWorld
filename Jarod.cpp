#include "StillsuitSim.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

double StillsuitSim::getAvailableWater() {
    return waterStg;
}

// Sends the water to the human to drink
double StillsuitSim::sendWater(double amountRequested) {
    double waterToSend;
    if (amountRequested > waterStg) {
        waterToSend = waterStg;
        cout << "Amount of water requested is larger than the amount in storage. Sending " << waterToSend << "ml of water." << endl;
        waterStg = 0;
        cout << "There is " << waterStg << "ml of water remaining." << endl;
        return waterToSend;
    }
    else {
        waterToSend = amountRequested;
        waterStg = waterStg - waterToSend;
        cout << "Sending " << waterToSend << "ml of water." << endl << "There is " << waterStg << "ml of water remaining." << endl;
        return waterToSend;
    }
}

// Calculates the suit's weight and returns its weight in kilograms
double StillsuitSim::calculateSuitWeight() {
    double waterWeight = waterStg / 1000;
    double suitWeight = emptySuitWeight + waterWeight;

    return suitWeight;
}