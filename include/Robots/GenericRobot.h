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
// #include "Core/Robot.h"
// #include "Robots/GenericRobot.h"
// #include <vector>
using namespace std;

// Add your declarations here
class GenericRobot : public MovingRobot, public SeeingRobot, public ShootingRobot, public ThinkingRobot
{
public:
    GenericRobot(const std::string &name, int x, int y);

    // Implement all pure virtual functions
    void move(int dx, int dy) override;
    std::vector<std::vector<char>> look(int dx, int dy) override;
    void fire(int targetX, int targetY) override;
    void think() override;
    
    // Resolve the multiple inheritance ambiguity
    char getSymbol() const override { return 'G'; }  // 'G' for GenericRobot    

private:
    // 简化战场交互（假设由Member 3实现）
    static bool isPositionValid(int x, int y);
};

#endif // SIMULATION_H