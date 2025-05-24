#ifndef BATTLEFIELD_H
#define BATTLEFIELD_H

#include "Core/Robot.h"
#include <array>

namespace Battlefield {
    constexpr int WIDTH = 100;
    constexpr int HEIGHT = 100;

    // Store pointers to robots on the grid (nullptr if empty)
    extern Robot* grid[WIDTH][HEIGHT];

    bool isValidCoordinates(int x, int y);
    int getWidth();
    int getHeight();
    Robot* getRobotAt(int x, int y);
    void setRobotAt(int x, int y, Robot* robot);
}

#endif // BATTLEFIELD_H 