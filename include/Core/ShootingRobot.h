/**********|**********|**********|
Program: main.cpp / SHOOTING.h
Course: OOPDS
Trimester: 2510
Name: Bradley Ben Lee, David Ting Zi Xiang, Esvan Rao A/L Perasath Raw
ID: 243UC245SA, 242UC244PE, 243UC245HJ
Lecture Section: TC1L
Tutorial Section: TT1L
Email: BRADLEY.BEN.LEE@student.mmu.edu.my, DAVID.TING.ZI@student.mmu.edu.my, esvan.rao.perasath@student.mmu.edu.my
Phone:  01151799588, 013-352 8910, 0162025996
**********|**********|**********/
#ifndef SHOOTING_H
#define SHOOTING_H
// #include <iostream>
// #include <string>
#include "Robot.h" // Include the base class header

// Add your declarations here
class ShootingRobot : public virtual Robot
{
protected:
    int bullet = 10; // Number of bullets available for shooting
public:
    ShootingRobot(const std::string &name, int x, int y)
        : Robot(name, x, y) {}                       // Constructor initializing the base class
    virtual void fire(int targetX, int targetY) = 0; // Pure virtual function for shooting
    bool isBulletAvailable() const
    {
        return bullet > 0; // Check if there are bullets available
    }

    void useBullet()
    {
        if (isBulletAvailable())
        {
            --bullet;
        }
        else
        {
            while (isAlive())
            {
                takeDamage(); // Out of bullets = robot dies
            }
        }
    }
};

#endif // SHOOTING_H