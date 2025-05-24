// // main.cpp
// #include "Robots/GenericRobot.h"
// #include <iostream>
// #include <memory>
// using namespace std;

// int main()
// {
//      // 创建两个机器人
//      auto robot1 = make_unique<GenericRobot>("Alpha", 10, 20);
//      auto robot2 = make_unique<GenericRobot>("Beta", 30, 40);

//      // 验证基础功能
//      std::cout << "=== Initial State ===" << std::endl;
//      std::cout << robot1->getName() << " position: ("
//                << robot1->getPosition().first << ", "
//                << robot1->getPosition().second << ")\n";
//      std::cout << robot2->getName() << " bullet: "
//                << (robot2->isBulletAvailable() ? "Available" : "Empty") << "\n";

//      // 模拟一次行动
//      std::cout << "\n=== Action Simulation ===" << std::endl;
//      robot1->think();
//      robot2->fire(0, 0);

//      // 验证行动结果
//      cout << robot1->getName() << " new position: ("
//           << robot1->getPosition().first << ", "
//           << robot1->getPosition().second << ")\n";
//      cout << robot2->getName() << " remaining bullet: "
//           << (robot2->isBulletAvailable() ? "Available" : "Empty") << "\n";

//      // 验证封装性（以下代码若取消注释应编译失败）
//      // robot1->posX = 100;  // Error: 'posX' is private

//      return 0;
// }

// main.cpp
#include "Robots/GenericRobot.h"
#include <iostream>
#include <memory>
using namespace std;

void printRobotState(const GenericRobot& robot) {
    std::cout << robot.getName() << " position: ("
              << robot.getPosition().first << ", "
              << robot.getPosition().second << ")\n";
    std::cout << robot.getName() << " bullet: "
              << (robot.isBulletAvailable() ? "Available" : "Empty") << "\n";
}

int main()
{
    cout << "[DEBUG] Program started\n";
    // Create multiple robots
    auto robot1 = make_unique<GenericRobot>("Alpha", 10, 20);
    auto robot2 = make_unique<GenericRobot>("Beta", 30, 40);
    cout << "[DEBUG] Robots created\n";

    // Print initial states of all robots
    std::cout << "=== Initial States ===" << std::endl;
    printRobotState(*robot1);
    printRobotState(*robot2);
    cout << "[DEBUG] Printed initial states\n";

    // Simulate actions for both robots
    std::cout << "\n=== Action Simulation ===" << std::endl;
    
    // Robot 1's turn
    std::cout << "\nRobot 1's turn:" << std::endl;
    robot1->think();
    cout << "[DEBUG] robot1->think() called\n";
    printRobotState(*robot1);

    // Robot 2's turn
    std::cout << "\nRobot 2's turn:" << std::endl;
    robot2->think();
    robot2->fire(robot1->getPosition().first, robot1->getPosition().second);
    cout << "[DEBUG] robot2->think() and fire() called\n";
    printRobotState(*robot2);

    // Print final states
    std::cout << "\n=== Final States ===" << std::endl;
    printRobotState(*robot1);
    printRobotState(*robot2);
    cout << "[DEBUG] Printed final states\n";

    // 验证封装性（以下代码若取消注释应编译失败）
    // robot1->posX = 100;  // Error: 'posX' is private

    cout << "[DEBUG] Program ending\n";
    return 0;
}