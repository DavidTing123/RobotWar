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

// Add your declarations here
class SeeingRobot : virtual public Robot
{
public:
    using Robot::Robot;
    virtual void look(int dx, int dy) = 0;
};

#endif // SEEING_H