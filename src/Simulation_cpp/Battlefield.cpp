#include "Simulation/Battlefield.h"

namespace Battlefield {
    Robot* grid[WIDTH][HEIGHT] = {nullptr};

    bool isValidCoordinates(int x, int y) {
        return x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT;
    }

    int getWidth() { return WIDTH; }
    int getHeight() { return HEIGHT; }

    Robot* getRobotAt(int x, int y) {
        if (!isValidCoordinates(x, y)) return nullptr;
        return grid[x][y];
    }

    void setRobotAt(int x, int y, Robot* robot) {
        if (!isValidCoordinates(x, y)) return;
        grid[x][y] = robot;
    }
} 