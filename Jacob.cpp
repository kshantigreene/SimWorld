#include "HumanSim.h"
#include "StillsuitSim.h"

#include <iostream>
using std::rand;

//
//  These are my code changes below from the HumanSim.cpp file.
//

// Calculates the sweat based on activity, temperature and weight (including suit)
double HumanSim::calculateSweat(double InternalTemp) {

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

    //decompose into components
    //pass to suit
    double sweatComposedOfWater = 0.99;



    return sweat;
}



// Calculates the urine based on activity level and amount to drink.
void HumanSim::calculateUrine(double urine) {

    // Based on activity and amount to drink (you can assume they are getting 
    // water from outside if the suit isn’t providing enough)

    // Compositions of urine variables

    // Percentage of urine composed of water.
    double urineComposedOfWater = 0.95;

    // Percentage of urine composed of urea.
    double urineComposedOfUrea = 0.02;

    // Percentage of urine composed of creatinine.
    double urineComposedOfCreatinine = 0.01;

    // Percentage of urine composed of uric acid.
    double urineComposedOfUricAcid = 0.003;

    this->bladderCapacity;

    this->waterDrank;

    if (currentWL > expectedWL) {
        
        // Release fluids

        // urine in a day.
        urine = currentWL - expectedWL;
        
        double waterAmount = urine * urineComposedOfWater;

        // Divides the parts that are bad in urine.
        double ureaAmount = urine * urineComposedOfUrea;

        double creatinineAmount = urine * urineComposedOfCreatinine;

        double uricAcidAmount = urine * urineComposedOfUricAcid;

        // urine per minute.
        double urinePerMin = urine / 1440;

        // How many times you went to the bathroom in a day.
        double totalNumberOfTimesWentToPee = urinePerMin / bladderCapacity;

        bladderCapacity = urine;

        sendFluidsToSuit(waterAmount, ureaAmount, creatinineAmount, uricAcidAmount);
    }
}

// Need to setup function that sends fluids from urine to the suit.

//void HumanSim::sendFluidsToSuit(double water, uricAcid, creatine, sodium)
//sendFluidsToSuit(waterAmount,uricAcidAmount,creatineAmount, 0,0,0);
//sweat: 

void HumanSim::sendFluidsToSuit(double water, double urea, double creatinine, double uricAcid)
{
    // Declares the character array for decrypting the liquid.
    char decryptLiquid[4];

    int maxLiquidSize = 9;

    int liquidType = rand() % 9;

    this->urine;

    string convertLiquid = "";

    while (urine > 0) 
    {
        for (int i = 0; i < maxLiquidSize && water > 0; i++)
        {
            switch (liquidType) {
                case 0:
                    // Water
                    if (water > 0) 
                    {
                        convertLiquid = convertLiquid + '1';
                        water--;
                        urine--;
                    }
                    break;
                case 1:
                    // Urea
                    if (water > 0) 
                    {
                        convertLiquid = convertLiquid + '2';
                        urea--;
                        urine--;
                    }
                    break;
                case 2:
                    // Creatinine
                    if (water > 0) 
                    {
                        convertLiquid = convertLiquid + '3';
                        creatinine--;
                        urine--;
                    }
                    break;
                case 3:
                    // Uric Acid
                    if (water > 0) 
                    {
                        convertLiquid = convertLiquid + '4';
                        uricAcid--;
                        urine--;
                    }
                    break;

                    // Add sodium or other cases when the time comes.
            }
            urine--;
        }

        int liquidToSuit = 0;

        liquidToSuit = stoi(convertLiquid);

        suit->setLiquid(liquidToSuit);
    }

    // CANNOT GO OVER 9 CASES
    // Get rid of uric acid from urine since it is only found in animals (birds).
    // Add most of the components from fluid simulation & round to thousandths place for each percentage.
    // DO NOT include Calcium and Magnesium
    // 
    // Fix function for send fluids to suit once all use cases are set.
    // 
    // Add a call for the sweat function that sends fluids to suit.
}