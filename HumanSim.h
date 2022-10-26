#pragma once
#include <iostream>
#include <string>

using namespace std;

class HumanSim
{
public:
	 HumanSim(string n);
	 void setWorldInfo(int time, int temp);

private:
	 string name;
	 double worldTemp;
};

