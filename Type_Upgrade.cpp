#include <iostream>
#include <string>
using namespace std;

class GenericRobot{
private:
    std::string name;
    int health, damage, range;
    int positionX = 0;
    int positionY = 0;

public:
    GenericRobot(std::string name, int health, int damage, int range) : name(name), health(health), damage(damage), range(range){}

    void move(int x, int y){
        positionX += x;
        positionY += y;
    }

    void fire(int fired){
        health -= fired;
    }

    void taken_damage(int take_damage){
        health -= take_damage;
    }

    void robot_upgrade(int choice){
        switch (choice)
        {
        case 1:
            health += 25;
            cout<<"** TankBot: Upgrade your Bot to take more DAMAGE **"<<endl;
            cout<<"Your Bot's Health will increase to : "<<health<<endl;
            break;
        case 2:
            damage += 15;
            cout<<"** ExecutionerBot: Upgrade your Bot to deal more DAMAGE **"<<endl;
            cout<<"Your Bot's Damage will increase to : "<<damage<<endl;
            break;
        case 3:
            range += 1;
            cout<<"** SniperBot: Upgrade your Bot to its shooting RANGE **"<<endl;
            cout<<"Your Bot's Range will increate to : "<<range<<endl;
            break;
        default:
            break;
        }
    }
};

int main(){
    std::string name;
    GenericRobot (name, 100, 100, 2);


    return 0;
}