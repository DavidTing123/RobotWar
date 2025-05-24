/**********|**********|**********|
Program: MovingRobot.cpp / MovingRobot.h
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

#include <string>  // For std::string
#include <utility> // For std::pair
#include "Robot.h" // Base class

class MovingRobot : public virtual Robot
{
public:
    MovingRobot(const std::string &name, int dx, int dy)
        : Robot(name, dx, dy) {}

    virtual void move(int dx, int dy) = 0;

    inline static std::pair<int, int> directionToDelta(const std::string &direction)
    {
        if (direction == "right")
            return {1, 0};
        if (direction == "left")
            return {-1, 0};
        if (direction == "up")
            return {0, -1};
        if (direction == "down")
            return {0, 1};
        if (direction == "up-right")
            return {1, -1};
        if (direction == "up-left")
            return {-1, -1};
        if (direction == "down-right")
            return {1, 1};
        if (direction == "down-left")
            return {-1, 1};
        return {0, 0};
    }
};

#endif // MOVINGROBOT_H