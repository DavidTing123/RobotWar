/**********|**********|**********|
Program: main.cpp / Robot.h
Course: OOPDS
Trimester: 2510
Name: Bradley Ben Lee, David Ting Zi Xiang, Esvan Rao A/L Perasath Raw
ID: 243UC245SA, 242UC244PE, 243UC245HJ
Lecture Section: TC1L
Tutorial Section: TT1L
Email: BRADLEY.BEN.LEE@student.mmu.edu.my, DAVID.TING.ZI@student.mmu.edu.my, esvan.rao.perasath@student.mmu.edu.my
Phone:  01151799588, 013-352 8910, 0162025996
**********|**********|**********/

#pragma once // can replace #ifndef ROBOT_H, #define ROBOT_H
#include <iostream>
#include <string>  //robot name
#include <utility> //utility for pair
using namespace std;

// Add your declarations here
class Robot
{
protected: // protected members can be accessed by derived classes
    string name;
    int posX, posY; // current position of the coordinate
    int health = 3; // health of the robot

public:
    Robot(const string &robotName, int x, int y);
    virtual ~Robot() = default;

    // Pure virtual functions
    virtual void think() = 0; // Decision-making logic (where to move, whether to attack)
    virtual void act() = 0;   // Action logic (move, attack, defend)

    // core methods
    void takeDamage();                  // Reduces health when robot is hit
    bool isAlive() const;               // Checks if health > 0
    void setPosition(int x, int y);     // Updates robot's coordinates
    pair<int, int> getPosition() const; // Returns current (x,y) position
};
