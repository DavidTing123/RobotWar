/**********|**********|**********|
Program: Robot.cpp / SeeingRobot.h
Course: OOPDS
Trimester: 2510
Name: Bradley Ben Lee, David Ting Zi Xiang, Esvan Rao A/L Perasath Raw
ID: 243UC245SA, 242UC244PE, 243UC245HJ
Lecture Section: TC1L
Tutorial Section: TT1L
Email: BRADLEY.BEN.LEE@student.mmu.edu.my, DAVID.TING.ZI@student.mmu.edu.my, esvan.rao.perasath@student.mmu.edu.my
Phone:  01151799588, 013-352 8910, 0162025996
**********|**********|**********/
#ifndef SEEINGROBOT_H
#define SEEINGROBOT_H
// #include <iostream>
// #include <string>
#include "Robot.h" // Include the base class header
#include <vector>
using namespace std;

// Add your declarations here
class SeeingRobot : public virtual Robot
{
public:
    SeeingRobot(const string &name, int x, int y)
        : Robot(name, x, y) {}                             // Constructor initializing the base class
    virtual vector<vector<char>> look(int dx, int dy) = 0; // Pure virtual function for seeing 8 directions
};

#endif // SEEING_H