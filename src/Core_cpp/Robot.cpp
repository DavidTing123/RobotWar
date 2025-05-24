// #include <iostream>
// #include <string>
// #include <utility> //utility for pair
#include "Core/Robot.h"
// #include "include//Core//MovingRobot.h"
// #include "include//Core//ShootingRobot.h"
// #include "include//Core//ThinkingRobot.h"
// #include "include//Core//SeeingRobot.h"
using namespace std;

// Constructor
Robot::Robot(const string &robotName, int x, int y)
    : name(robotName), posX(x), posY(y) {}

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
    // return {posX, posY}; // C++11 style
}

// Take damage
void Robot::takeDamage()
{
    if (health > 0)
        --health;
}

// Health check
bool Robot::isAlive() const
{
    return health > 0;
}

string Robot::getName() const
{
    return name;
}

int Robot::getHealth() const
{
    return health;
}

char Robot::getSymbol() const
{
    // return name.empty() ? '?' : name[0]; // Return the first character of the robot's name as its symbol
    //  return name[0];
    return 'R'; // Default symbol for the robot
}

void Robot::showInfo() const
{
    cout << "[" << name << "] at position (" << posX << ", " << posY << "), Health: " << health << endl;
}
