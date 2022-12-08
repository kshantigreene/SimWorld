#include "HumanSim.h"
#include "StillsuitSim.h"

#include <iostream>
using std::rand;

// Declares the const characters of the liquids that will be sent to the suit.
const char WATER = '1';
const char UREA = '2';
const char CHLORIDE = '3';
const char SODIUM = '4';
const char CREATININE = '5';
const char POTASSIUM = '6';

//
//  These are my code changes below from the HumanSim.cpp file.
//

// Calculates the sweat based on activity, temperature and weight (including suit)
double HumanSim::calculateSweat(double InternalTemp) {

    // Percentage of Water in sweat
    double sweatComposedOfWater = 0.99;

    // Percentage of Sodium in sweat
    double sweatComposedOfSodium = 0.009;

    // Percentage of Potassium in sweat
    double sweatComposedOfPotassium = 0.002;

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

    // Creates the amounts composed in sweat.
    double waterAmount = sweat * sweatComposedOfWater;

    double sodiumAmount = sweat * sweatComposedOfSodium;

    double potassiumAmount = sweat * sweatComposedOfPotassium;

    sendFluidsToSuit(sweat, waterAmount, 0, 0, sodiumAmount, 0, potassiumAmount);

    return sweat;
}



// Calculates the urine based on activity level and amount to drink.
void HumanSim::calculateUrine(double urine) {

    // Based on activity and amount to drink (you can assume they are getting 
    // water from outside if the suit isn�t providing enough)

    // Percentage of water composed in urine.
    double urineComposedOfWater = 0.95;

    // Percentage of urea composed in urine.
    double urineComposedOfUrea = 0.093;

    // Percentage of chloride composed in urine.
    double urineComposedOfChloride = 0.019;

    // Percentage of sodium composed in urine.
    double urineComposedOfSodium = 0.018;
    
    // Percentage of creatinine composed in urine.
    double urineComposedOfCreatinine = 0.007;

    // Percentage of potassium composed in urine.
    double urineComposedOfPotassium = 0.008;

    this->bladderCapacity;

    this->waterDrank;

    if (currentWL > expectedWL) {
        
        // Release fluids

        // urine in a day.
        urine = currentWL - expectedWL;
        
        // Creates the amounts composed in urine.
        double waterAmount = urine * urineComposedOfWater;

        double ureaAmount = urine * urineComposedOfUrea;

        double chlorideAmount = urine * urineComposedOfChloride;

        double sodiumAmount = urine * urineComposedOfSodium;

        double creatinineAmount = urine * urineComposedOfCreatinine;

        double potassiumAmount = urine * urineComposedOfPotassium;

        // urine per minute.
        double urinePerMin = urine / 1440;

        // How many times you went to the bathroom in a day.
        double totalNumberOfTimesWentToPee = urinePerMin / bladderCapacity;

        bladderCapacity = urine;

        sendFluidsToSuit(bladderCapacity, waterAmount, ureaAmount, chlorideAmount, sodiumAmount, creatinineAmount, potassiumAmount);
    }
}

// This function sends fluids from urine & sweat to the suit.
void HumanSim::sendFluidsToSuit(double totalLiquid, double water, double urea, double chloride, double sodium, double creatinine, double potassium)
{
    // Declares the character array for encrypting the liquid.
    char encryptLiquid[4];

    int maxLiquidSize = 5;

    string convertLiquid = "";

    while (totalLiquid > 0) 
    {
        int liquidType = rand() % 6;

        for (int i = 0; i < maxLiquidSize && water > 0; i++)
        {
            switch (liquidType) {
                case 0:
                    // Water
                    if (water > 0) 
                    {
                        convertLiquid = convertLiquid + WATER;
                        water--;
                        urine--;
                    }
                    break;
                case 1:
                    // Urea
                    if (water > 0) 
                    {
                        convertLiquid = convertLiquid + UREA;
                        urea--;
                        urine--;
                    }
                    break;
                case 2:
                    // Chloride
                    if (water > 0) 
                    {
                        convertLiquid = convertLiquid + CHLORIDE;
                        chloride--;
                        urine--;
                    }
                    break;
                case 3:
                    // Sodium
                    if (water > 0) 
                    {
                        convertLiquid = convertLiquid + SODIUM;
                        sodium--;
                        urine--;
                    }
                    break;
                case 4:
                    // Creatinine
                    if (water > 0)
                    {
                        convertLiquid = convertLiquid + CREATININE;
                        creatinine--;
                        urine--;
                    }
                    break;
                case 5:
                    // Potassium
                    if (water > 0)
                    {
                        convertLiquid = convertLiquid + POTASSIUM;
                        potassium--;
                        urine--;
                    }
                    break;
            }
            urine--;
        }

        int liquidToSuit = 0;

        liquidToSuit = stoi(convertLiquid);

        suit->StillsuitCompoundID(liquidToSuit);
    }

    // CANNOT GO OVER 9 CASES
    // Fix function for send fluids to suit once all use cases are set.
}