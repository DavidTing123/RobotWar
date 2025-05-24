#include "Robots/GenericRobot.h"    // Include the GenericRobot header
#include "Simulation/Battlefield.h" // Include the Battlefield header
#include <iostream>
#include <cstdlib> // for rand() and srand()
using namespace std;

GenericRobot::GenericRobot(const string &name, int x, int y)
    : Robot(name, x, y),
      MovingRobot(name, x, y),
      SeeingRobot(name, x, y),
      ShootingRobot(name, x, y),
      ThinkingRobot(name, x, y) {}

void GenericRobot::move(int dx, int dy)
{
    auto [oldX, oldY] = getPosition();
    int newX = oldX + dx;
    int newY = oldY + dy;
    if (isPositionValid(newX, newY))
    {
        Battlefield::setRobotAt(oldX, oldY, nullptr); // Clear old position
        setPosition(newX, newY);
        Battlefield::setRobotAt(newX, newY, this); // Set new position
        cout << getName() << " moved to (" << newX << ", " << newY << ").\n";
    }
}

vector<vector<char>> GenericRobot::look(int dx, int dy)
{
    // Implement the logic to see in 8 directions
    auto [x, y] = getPosition();
    const int centerX = x + dx;
    const int centerY = y + dy;

    vector<vector<char>> view(3, vector<char>(3, '.')); // 3x3 grid for the view

    // Fill the view with the surrounding area
    for (int i = -1; i <= 1; ++i)
    {
        for (int j = -1; j <= 1; ++j)
        {
            const int targetX = centerX + i;
            const int targetY = centerY + j;

            // Check if the target coordinates are valid
            if (!Battlefield::isValidCoordinates(targetX, targetY))
            {
                view[i + 1][j + 1] = 'X'; // Mark as blocked
            }
            else if (targetX == x && targetY == y)
            {
                view[i + 1][j + 1] = '#'; // Robot itself
            }
            else
            {
                Robot *robot = Battlefield::getRobotAt(targetX, targetY);
                if (robot != nullptr && robot != this)
                {
                    view[i + 1][j + 1] = robot->getSymbol(); // Use robot's symbol
                }
                else
                {
                    view[i + 1][j + 1] = '.'; // empty
                }
            }
        }
    }

    return view;
}

void GenericRobot::fire(int targetX, int targetY)
{
    if (!isBulletAvailable())
    {
        cout << getName() << " has no bullets left!\n";
        return;
    }
    bullet--;
    cout << getName() << " fires at (" << targetX << ", " << targetY << "). Bullets left: " << bullet << "\n";

    // TODO: Implement the logic to check if the target is valid and hit
}

void GenericRobot::think()
{
    auto view = look(0, 0);
    bool foundG = false;
    int targetDx = 0, targetDy = 0;
    for (int i = 0; i < 3 && !foundG; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            if (view[i][j] == 'G')
            {
                targetDx = i - 1;
                targetDy = j - 1;
                foundG = true;
                break;
            }
        }
    }

    if (foundG && isBulletAvailable())
    {
        fire(targetDx, targetDy);
    }
    else
    {
        // Move randomly if no 'G' nearby
        int moveDx = rand() % 3 - 1;
        int moveDy = rand() % 3 - 1;
        move(moveDx, moveDy);
    }

    if (!isBulletAvailable())
    {
        takeDamage();
        cout << "Out of bullets! Taking damage.\n";
    }
}

// Check if the position is valid
bool GenericRobot::isPositionValid(int x, int y)
{
    // Check if the position is within the battlefield boundaries
    return (x >= 0 && x < Battlefield::getWidth() && y >= 0 && y < Battlefield::getHeight());
}
