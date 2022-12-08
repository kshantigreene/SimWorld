#include "StillsuitSim.h"
#include <iostream>
#include <string>
using namespace std;
#include <vector>
#include "RSAEncryption.h"

StillsuitSim::StillsuitSim(RSAEncryption * encrypt) {
    this->encryption = encrypt;
};

void StillsuitSim::updateSuit(int time, double temp) {
    this->worldTime = time;
    this->outsideTemp = temp;
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
    StillsuitCompoundID(incomingLiquid);
    incomingLiquid = 0;
}
