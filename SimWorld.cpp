// SimWorld.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "StillsuitSim.h"
#include "HumanSim.h"
#include <thread>
#include <atomic>
#include <time.h>
#include <math.h>
#include <random>

#include "RSAEncryption.h"

const int MIN_PER_DAY = 1440;
const int MIN_TEMP = 50;
const int MAX_TEMP = 100;
const int SLEEP_TIME = 10;
const double PI = 3.14159265359;
bool stop = false;


void sendToSims(HumanSim* human, StillsuitSim* suit, int time, int temp) {
    
    cout << "The world temp is: " << temp << endl;
    suit->updateSuit(time, temp);
    human->updateHuman(time,temp);

    
}


int main()
{
    srand(time(NULL));
    
    RSAEncryption* encryption = new RSAEncryption();
    std::cout << "Hello World!\n";
    StillsuitSim* suit = new StillsuitSim( encryption);
    HumanSim* human = new HumanSim("Dave", suit, 3.0, 25, 72, 81, true, encryption);
    int initTemp= MIN_TEMP+rand() % 10 + 1; //within 10 degrees of min
    double width = 7.5;
    double a = -1.0/(MIN_PER_DAY*width);
    double b = MIN_PER_DAY/ (MIN_PER_DAY * width);
    double c = 0;
    //send time and temp
    for (int i = 1; i <= MIN_PER_DAY; i++) {
        //use quadratic formula to make the temp rise gradually til mid day and then
        //start decreasing again.
        double tempDiff = i*i*a + b*i+ c;
        //randomly adjust tempDiff up or down by a small amount
        double r = rand() % 4-2.0;
        int temp = tempDiff+r+initTemp;
        //create thread so human can deal with it independent of this thread
        thread tempThread(sendToSims,human, suit, i, temp);
        tempThread.detach();
        sendToSims(human, suit, i, temp);
        this_thread::sleep_for(chrono::milliseconds(SLEEP_TIME));

        if (human->calculateDeath()) {
            cout << "You killed the human!!";
            delete human;
            break;
        }
    }
    
}
