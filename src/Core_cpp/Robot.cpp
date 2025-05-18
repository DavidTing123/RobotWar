#include <iostream>
#include <string>
#include <utility> //utility for pair
#include "include//Core//Robot.h"
#include "include//Core//MovingRobot.h"
#include "include//Core//ShootingRobot.h"
#include "include//Core//ThinkingRobot.h"
#include "include//Core//SeeingRobot.h"
using namespace std;

// Constructor
Robot::Robot(const string &robotName, int x, int y)
    : name(robotName), posX(x), posY(y), health(3) {}

// Health check
bool Robot::isAlive() const
{
    return health > 0;
}

// Set coordinates
void Robot::setPosition(int x, int y)
{
    posX = x;
    posY = y;
}

// Set coordinates
pair<int, int> Robot::getPosition() const
{
    return make_pair(posX, posY); // Return the current (x,y) position
}

int main()
{
    // your code here
    return 0;
}
