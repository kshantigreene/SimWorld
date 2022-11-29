#include "StillsuitSim.h"
#include <iostream>
#include <string>
using namespace std;
#include <vector>

StillsuitSim::StillsuitSim() {
};

void StillsuitSim::updateSuit(int time) {
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

//setter for all liquids
void StillsuitSim::setLiquid(int liquid) {
    incomingLiquid = liquid;
    StillsuitCompoundID();
    incomingLiquid = 0;
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
    return c;
}

