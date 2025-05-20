#include "Robots/GenericRobot.h" // Include the GenericRobot header
#include "Core/Robot.h"          // Include the Robot header
#include <iostream>
using namespace std;

GenericRobot::GenericRobot(const std::string &name, int x, int y)
    : Robot(name, x, y) {}

void GenericRobot::think()
{
    cout << name << " is thinking...\n";
}

void GenericRobot::act()
{
    move();
    look(0, 0);
    fire(1, 0);
}

void GenericRobot::move()
{
    cout << name << " moves to (" << posX + 1 << ", " << posY << ")\n";
    posX += 1;
}

void GenericRobot::look(int dx, int dy)
{
    cout << name << " looks at (" << posX + dx << ", " << posY + dy << ")\n";
}

void GenericRobot::fire(int dx, int dy)
{
    cout << name << " fires at (" << posX + dx << ", " << posY + dy << ")\n";
}

void GenericRobot::makeDecision()
{
    cout << name << " is making a decision...\n";
}
