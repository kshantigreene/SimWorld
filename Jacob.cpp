#include "HumanSim.h"
#include "StillsuitSim.h"

#include <vector>
using std::vector;

//
//  These are my code changes below from the HumanSim.cpp file.
//

// Calculates the sweat based on activity, temperature and weight (including suit)
double HumanSim::calculateSweat(int temp, double InternalTemp, int weight) {

    // Normal Temp of Human (98.6 F).
    double normalTemp = 98.6;

    // Curent milliliters for an active male. (Add female sweat in mL).
    const double MAX_SWEAT = 23;

    // Calculates the temperature the human has overheated.
    //
    // This equation looks at the current temperature of the person minus the average body temperature (98.6 F).
    long double tempOverheated = (InternalTemp - normalTemp);

    // Range of active milliliters (ML) equation
    // 
    // This equation rises up graphically where it starts at 0 and gets close but not equal to 25.
    double sweat = (MAX_SWEAT - 1 / log(tempOverheated + 1));

    return sweat;
}



// Calculates the urine based on activity level and amount to drink.
void HumanSim::calculateUrine(int weight) {

    // Based on activity and amount to drink (you can assume they are getting 
    // water from outside if the suit isn�t providing enough)

    // Compositions of urine variables

    // Percentage of urine composed of water.
    double urineComposedOfWater = 0.95;

    // Percentage of urine composed of urea.
    double urineComposedOfUrea = 0.02;

    // Percentage of urine composed of creatinine.
    double urineComposedOfCreatinine = 0.01;

    // Percentage of urine composed of uric acid.
    double urineComposedOfUricAcid = 0.003;

    // The max activity used in urine function. (Human)
    // double activityLevel = 1.0;

    // The max amount of milliliters per kilograms per hour.
    // double maxMLPerKgPerHr = 1.5;

    //vector<double> ;

    // The max amount of urine that can be produced per minute.
    //
    // This equation takes the maxMLPerKgPerHr variable, times the activityLevel, times the weight of the human in kg.
    //
    // Note: Does NOT take into account the percentages of urine above yet.
    //
    // double maxUrineProducedPerMin = (((maxMLPerKgPerHr * activityLevel) * (weight)) * 60);

    this->bladderCapacity;

    this->waterDrank;

    if (currentWL > expectedWL) {
        
        // Release fluids

        // urine in a day.
        double urine = (waterDrank - sweat) * urineComposedOfWater;

        // Divides the parts that are bad in urine.
        double ureaAmount = urine * urineComposedOfUrea;

        double creatinineAmount = urine * urineComposedOfCreatinine;

        double uricAcidAmount = urine * urineComposedOfUricAcid;

        // urine per minute.
        double urinePerMin = urine / 1440;

        // How many times you went to the bathroom in a day.
        double totalNumberOfTimesWentToPee = urinePerMin / bladderCapacity;

        // Create a variable for what's in the bladder currently.
        double currentBladder = 0.0;
    }

    // Calculates the current water level and urine by adding currentWL and the urine composed of Water.
    //double currentWLAndUrine = currentWL * urineComposedOfWater;

    // Adds together the "bad" compositions of urine.
    //double totalUrineComposedOfWaste = urineComposedOfUrea + urineComposedOfCreatinine + urineComposedOfUricAcid;

    // Calculates the total water level with urine and waste by dividing current 
    //double totalWLWithUrineAndWaste = currentWLAndUrine / totalUrineComposedOfWaste;
}

// Need to setup function that sends fluids from urine to the suit.

//void HumanSim::sendFluidsToSuit(double urineAmount, double sweatAmount) 
//{
    // char[] decryptLiquid;

    // 
//}