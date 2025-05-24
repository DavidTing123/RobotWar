/**********|**********|**********|
Program: Robot.cpp / Robot.h
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
// #include <vector>
// using namespace std;

// Add your declarations here
class Robot
{
private:      // private members cannot be accessed outside this class
    int posX; // x-coordinate of the robot
    int posY; // y-coordinate of the robot

protected: // protected members can be accessed by derived classes
    std::string name;
    int health = 3; // health of the robot

public:
    Robot(const std::string &robotName, int x, int y); // Constructor to initialize the robot's name and position
    virtual ~Robot() = default;

    // Movement methods (cannot visit posX, posY)
    void setPosition(int x, int y);          // Updates robot's coordinates
    std::pair<int, int> getPosition() const; // Returns current (x,y) position

    // core methods
    void takeDamage();    // Reduces health when robot is hit
    bool isAlive() const; // Checks if health > 0
                          // void showInfo();  // 顯示資訊

    // Getters
    std::string getName() const;    // Returns robot's name
    int getHealth() const;       // Returns robot's health
    virtual char getSymbol() const;

    void showInfo() const;
};
// void showInfo() const; // Show robot's information