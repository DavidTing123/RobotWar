#include "Robots/GenericRobot.h"
#include "Core/Robot.h"
#include "Simulation/Battlefield.h"
#include <vector>

using namespace std;

// Add your declarations here

// #include <iostream>
int main()
{
    Battlefield bf(10, 5);
    GenericRobot g("Jet", 2, 2);

    for (int turn = 1; turn <= 1; ++turn)
    {
        cout << "Turn " << turn << ":\n";
        bf.clear();

        auto [x, y] = g.getPosition();
        bf.placeRobot(x, y, 'G');

        g.think();
        g.act();

        auto [nx, ny] = g.getPosition();
        bf.placeRobot(nx, ny, 'G');

        bf.display();
        cout << "=================\n";
    }

    return 0;
}