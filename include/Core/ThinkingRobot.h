/**********|**********|**********|
Program: main.cpp / ThinkingRobot.h
Course: OOPDS
Trimester: 2510
Name: Bradley Ben Lee, David Ting Zi Xiang, Esvan Rao A/L Perasath Raw
ID: 243UC245SA, 242UC244PE, 243UC245HJ
Lecture Section: TC1L
Tutorial Section: TT1L
Email: BRADLEY.BEN.LEE@student.mmu.edu.my, DAVID.TING.ZI@student.mmu.edu.my, esvan.rao.perasath@student.mmu.edu.my
Phone:  01151799588, 013-352 8910, 0162025996
**********|**********|**********/
#ifndef THINKINGROBOT_H
#define THINKINGROBOT_H
// #include <iostream>
// #include <string>
#include "Robot.h" // Include the base class header

// Add your declarations here
class ThinkingRobot : public virtual Robot
{
public:
    ThinkingRobot(const std::string &name, int x, int y)
        : Robot(name, x, y) {}

    virtual void think() = 0; // Perform logic thinking
};

#endif // THINKINGROBOT_H