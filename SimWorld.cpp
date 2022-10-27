// SimWorld.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "StillsuitSim.h"
#include "HumanSim.h"
#include <thread>
#include <atomic>
#include <time.h>

const int MIN_PER_DAY = 1440;
const int MIN_TEMP = 50;
const int MAX_TEMP = 100;
const int SLEEP_TIME = 100;


void sendToHuman(HumanSim* human, int time, int temp) {
    
    human->setWorldInfo(time,temp);

}


int main()
{
    srand(time(NULL));
    std::cout << "Hello World!\n";
    StillsuitSim* suit = new StillsuitSim();
    HumanSim* human = new HumanSim("Dave",suit);
    //send time and temp
    for (int i = 1; i <= MIN_PER_DAY; i++) {
        int temp = rand() % MIN_TEMP + 1 + (MAX_TEMP - MIN_TEMP);
        thread tempThread(sendToHuman,human, i, temp);
        tempThread.detach();
        suit->setTime(i);
        this_thread::sleep_for(chrono::milliseconds(100));
    }

}
