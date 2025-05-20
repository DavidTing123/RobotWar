/**********|**********|**********|
Program: GenericRobot.cpp / GenericRobot.h
Course: OOPDS
Trimester: 2510
Name: Bradley Ben Lee, David Ting Zi Xiang, Esvan Rao A/L Perasath Raw
ID: 243UC245SA, 242UC244PE, 243UC245HJ
Lecture Section: TC1L
Tutorial Section: TT1L
Email: BRADLEY.BEN.LEE@student.mmu.edu.my, DAVID.TING.ZI@student.mmu.edu.my, esvan.rao.perasath@student.mmu.edu.my
Phone:  01151799588, 013-352 8910, 0162025996
**********|**********|**********/
#ifndef GENERICROBOT_H
#define GENERICROBOT_H
// #include <iostream>
// #include <string>

#include "Core/MovingRobot.h"
#include "Core/ShootingRobot.h"
#include "Core/ThinkingRobot.h"
#include "Core/SeeingRobot.h"
#include "Core/Robot.h"
#include "Robots/GenericRobot.h"

// Add your declarations here
class GenericRobot : public MovingRobot, public SeeingRobot, public ShootingRobot, public ThinkingRobot
{
public:
    GenericRobot(const std::string &name, int x, int y);
    void think() override;
    void act() override;

    void move() override;
    void look(int dx, int dy);
    void fire(int dx, int dy);
    void makeDecision() override;
};

#endif // SIMULATION_H