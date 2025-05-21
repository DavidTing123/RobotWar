// g++ -Iinclude -std=c++17 src/main.cpp src/Core_cpp/Robot.cpp src/Robots_cpp/GenericRobot.cpp src/Simulation_cpp/Battlefield.cpp -o RobotWar.exe
//.\RobotWar.exe

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
    GenericRobot g("Jet", 2, 0);

    for (int turn = 1; turn <= 1; ++turn)
    {
        cout << "Turn " << turn << ":\n";
        bf.clear();

        auto [x, y] = g.getPosition();
        bf.placeRobot(x, y, 'J');

        g.think();
        g.act();

        auto [nx, ny] = g.getPosition();
        bf.placeRobot(nx, ny, 'A');

        bf.display();
        cout << "=================\n";
    }

    return 0;
}

// #include "Robots/GenericRobot.h"
// #include "Core/Robot.h"
// #include "Simulation/Battlefield.h"
// #include <vector>
// #include <sstream>
// #include <cstdlib>
// #include <ctime>

// using namespace std;

// vector<GenericRobot> createRobotsFromInput(int width, int height)
// {
//     vector<GenericRobot> robots;
//     string line;

//     // Read battlefield dimensions (already read before calling this function)

//     // Read number of steps (already read)

//     // Read number of robots
//     getline(cin, line);
//     int robotCount;
//     istringstream(line) >> robotCount;

//     for (int i = 0; i < robotCount; ++i)
//     {
//         while (getline(cin, line))
//         {
//             if (line.empty())
//                 continue;

//             istringstream iss(line);
//             string type, name;
//             int x = -1, y = -1;

//             iss >> type >> name;

//             if (type != "GenericRobot")
//             {
//                 continue; // Skip invalid robot types
//             }

//             string pos;
//             iss >> pos;
//             if (pos == "random")
//             {
//                 x = rand() % width;
//                 y = rand() % height;
//             }
//             else
//             {
//                 x = stoi(pos);
//                 iss >> y;
//                 if (y == -1)
//                 { // If only one coordinate was provided
//                     y = rand() % height;
//                 }
//             }

//             robots.emplace_back(name, x, y);
//             break;
//         }
//     }

//     return robots;
// }

// int main()
// {
//     srand(time(0)); // Seed random number generator

//     string line;

//     // Read battlefield dimensions
//     getline(cin, line);
//     int width, height;
//     if (line.find("M by N :") != string::npos)
//     {
//         istringstream iss(line.substr(8));
//         iss >> width >> height;
//     }
//     else
//     {
//         // Default dimensions if not specified
//         width = 40;
//         height = 50;
//     }

//     Battlefield bf(width, height);

//     // Read number of steps
//     getline(cin, line);
//     int steps;
//     if (line.find("steps:") != string::npos)
//     {
//         istringstream iss(line.substr(6));
//         iss >> steps;
//     }
//     else
//     {
//         steps = 100; // Default steps
//     }

//     // Create robots from input
//     vector<GenericRobot> robots = createRobotsFromInput(width, height);

//     // Main simulation loop
//     for (int turn = 1; turn <= steps; ++turn)
//     {
//         cout << "Turn " << turn << ":\n";
//         bf.clear();

//         // Place all robots on battlefield
//         for (auto &robot : robots)
//         {
//             auto [x, y] = robot.getPosition();
//             bf.placeRobot(x, y, robot.getName()[0]); // Use first letter of name

//             robot.think();
//             robot.act();

//             auto [nx, ny] = robot.getPosition();
//             bf.placeRobot(nx, ny, robot.getName()[0]);
//         }

//         bf.display();
//         cout << "=================\n";
//     }

//     return 0;
// }