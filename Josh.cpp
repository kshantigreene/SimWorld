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