/**********|**********|**********|
Program: main.cpp / MovingRobot.h
Course: OOPDS
Trimester: 2510
Name: Bradley Ben Lee, David Ting Zi Xiang, Esvan Rao A/L Perasath Raw
ID: 243UC245SA, 242UC244PE, 243UC245HJ
Lecture Section: TC1L
Tutorial Section: TT1L
Email: BRADLEY.BEN.LEE@student.mmu.edu.my, DAVID.TING.ZI@student.mmu.edu.my, esvan.rao.perasath@student.mmu.edu.my
Phone:  01151799588, 013-352 8910, 0162025996
**********|**********|**********/
#ifndef MOVINGROBOT_H
#define MOVINGROBOT_H
#include <iostream>
#include <string>
using namespace std;

// Add your declarations here
class MovingRobot
{
public:
    // Constructor
    MovingRobot(string name, int speed);

    // Destructor
    ~MovingRobot();

    // Method to move the robot
    void move(int distance);

    // Method to stop the robot
    void stop();

private:
    string name;   // Name of the robot
    int speed;     // Speed of the robot
    bool isMoving; // Flag to check if the robot is moving
};

class Animal
{
public:
    void eat();
};

#endif // MOVING_H