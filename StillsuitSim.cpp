#include "StillsuitSim.h"
#include <iostream>
using namespace std;
#include <vector>

StillsuitSim::StillsuitSim() {
};

void StillsuitCompoundID()
{
    string water = "This is water.";
    string urea = "This is urea.";
    string chloride = "This is chloride.";
    string sodium = "This is sodium.";
    string creatinine = "This is creatinine.";
    string potassium = "This is potassium.";
    string calcium = "This is calcium.";
    string magnesium = "This is magnesium.";
    string error = "This compound is undefined. Please enter a defined compound.";

    string digits;
    cin >> digits;
    size_t index = 0;
    for (char c : digits)
    {
        bool identified = false;
        cout << c << endl;
        if (c == '1')
        {
            identified = true;
            cout << water << endl;
        }
        if (c == '2')
        {
            identified = true;
            cout << urea << endl;
        }
        if (c == '3')
        {
            identified = true;
            cout << chloride << endl;
        }
        if (c == '4')
        {
            identified = true;
            cout << sodium << endl;
        }
        if (c == '5')
        {
            identified = true;
            cout << creatinine << endl;
        }
        if (c == '6')
        {
            identified = true;
            cout << potassium << endl;
        }
        if (c == '7')
        {
            identified = true;
            cout << calcium << endl;
        }
        if (c == '8')
        {
            identified = true;
            cout << magnesium << endl;
        }
        if (!identified)
        {
            cout << error << endl;
        }
        index++;
    }
}

vector<int> liquidPurifier(int liquidElem) {
    vector<int> purifiedLiquid;
    purifiedLiquid.push_back(liquidElem);
    return purifiedLiquid;
}

void wip()
{
    int water = 1;
    int urea = 2;
    int chloride = 3;
    int sodium = 4;
    int creatinine = 5;
    int potassium = 6;
    int calcium = 7;
    int magnesium = 8;

    int sweat[5] = { water, sodium, potassium, calcium, magnesium };
    int urine[6] = { water, urea, chloride, sodium, creatinine, potassium };

    vector<int> liquidStorage;

    for (int i = 0; i <= sweat[4]; i++) {
        if (i != water) {
            liquidPurifier(i);
        }
        else {
            liquidStorage.push_back(i);
        }
    }

    for (int j = 0; j <= urine[5]; j++) {
        if (j != 1) {
            liquidPurifier(j);
        }
        else {
            liquidStorage.push_back(j);
        }
    }
}

void StillsuitSim::setTime(int time) {
    this->worldTime = time;
}

void StillsuitSim::seperateFluid() {
    int fluid2[10];
    int fluid = 123456;
    for (int i = 0; i < 10; i++)
    {
        fluid2[i] = fluid % 10; fluid /= 10;
    }
}



//getters and settings for urine
void StillsuitSim::setUrine(int urine)
{
    urineTotal += urine;
}

int StillsuitSim::getUrine()
{
    return urineTotal;
}
//getters and settings for sweat
void StillsuitSim::setSweat(int sweat)
{
    sweatTotal += sweat;
}

int StillsuitSim::getSweat()
{
    return sweatTotal;
}

//start heating process - not sure on amount to increase
void StillsuitSim::startHeat(int temp)
{
    temp += 2;
}

//start cooling process - not sure on amount to decrease
void StillsuitSim::startAirCon(int temp)
{
    temp -= 2;
}

//checking current internal temp to see if heat or cooling is needed, then calling needed function
void StillsuitSim::checkTemperature(int temp)
{
    if (temp < 60) 
    {
        startHeat(temp);
    }

    if (temp > 80) 
    {
        startAirCon(temp);
    }

}

// Returns gcd of a and b
int gcd(int a, int h)
{
    int temp;
    while (1) {
        temp = a % h;
        if (temp == 0)
            return h;
        a = h;
        h = temp;
    }
}
long encrypt(long msg)
{
    // Two random prime numbers
    srand((unsigned)time(0));
    long p = (rand() % 8) + 1;
    bool is_prime = true;

    if (p == 0 || p == 1) {
        is_prime = false;
    }

    for (int i = 2; i <= p / 2; ++i)
    {
        if (p % i == 0) {
            is_prime = false;
            break;
        }
    }

    while (is_prime == false)
    {
        is_prime = true;
        p = (rand() % 8) + 1;
        if (p == 0 || p == 1)
        {
            is_prime = false;
        }
        for (int i = 2; i <= p / 2; ++i)
        {
            if (p % i == 0)
            {
                is_prime = false;
                break;
            }
        }
    }
    cout << p;

    long q = (rand() % 8) + 1;

    if (q == 0 || q == 1) {
        is_prime = false;
    }

    for (int i = 2; i <= q / 2; ++i)
    {
        if (q % i == 0) {
            is_prime = false;
            break;
        }
    }

    while (is_prime == false)
    {
        is_prime = true;
        q = (rand() % 8) + 1;
        if (q == 0 || q == 1)
        {
            is_prime = false;
        }
        for (int i = 2; i <= q / 2; ++i)
        {
            if (q % i == 0)
            {
                is_prime = false;
                break;
            }
        }
    }
    cout << q;

    // First part of public key:
    long n = p * q;

    // Finding other part of public key.
    // e stands for encrypt
    long e = 2;
    long phi = (p - 1) * (q - 1);
    while (e < phi) {
        // e must be co-prime to phi and
        // smaller than phi.
        if (gcd(e, phi) == 1)
            break;
        else
            e++;
    }
    // Encryption c = (msg ^ e) % n
    long c = pow(msg, e);
    c = fmod(c, n);
    //printf("\nEncrypted data = %lf", c);
    cout << c << endl;

}
int StillsuitSim::batteryAlert(int time)
{
    //assigns values to variables
    int batteryLevel = 100;
    int maxBatteryTime = 720;

    //uses worldtime to find how many minuites are left in the battery
     int batteryTimeLeft;
    batteryTimeLeft = maxBatteryTime - worldTime;

    //uses simple math to make a percent of the batter left
    batteryLevel = (batteryTimeLeft / maxBatteryTime) * 100;
    
    //checks the level to see if its critical
    if (batteryLevel < 30)
    {
        return 1;
    }
    else
    {
        return 0;
    }

    //returns the value of the battery level and batter time
    return batteryLevel, batteryTimeLeft;
}