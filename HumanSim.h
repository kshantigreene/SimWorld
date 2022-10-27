#pragma once
#include <iostream>
#include <string>

using namespace std;

class HumanSim
{
public:
	 HumanSim(string n);
	 void setWorldInfo(int time, int temp);
	 void calculateSweat(int time, int temp, int weight);

private:
	 string name;
	 double worldTemp;

	 // Weight of Human
	 int weight;

};

