#include <iostrean>
using namespace std;

class GenericRobot(){
private:
    int moving = 0;
    int shooting = 0;
    int seeing = 0;
public:
    
}

class Jumpbot : public GenericRobot(){
public:
    void movement() override{
        moving += 3;
        cout<<"** You are now upgraded to JUMPBOT! **"<<endl;
    }
}

class LongShotBot : public GenericRobot(){
public:
    //void shooting +=
}

class ScoutBot : public GenericRobot(){
public:
    void seeing += 100;
}

int main(){


    return 0;
}
