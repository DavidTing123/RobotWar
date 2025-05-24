#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>  // Added for time()
#include <vector>

using namespace std;

const int MAP_WIDTH = 80;
const int MAP_HEIGHT = 50;

class GenericRobot {
protected:
    string name;
    int lives, range, fire, bullets, move, vision;
    int positionX = rand() % MAP_WIDTH;
    int positionY = rand() % MAP_HEIGHT;
    vector<string> AddedUpgrades;

public:
    GenericRobot(string name, int lives, int range, int fire, int bullets, int move, int vision) 
        : name(name), lives(lives), range(range), fire(fire), bullets(bullets), move(move), vision(vision) {}

    virtual ~GenericRobot() {}

    //testing
    bool hasUpgrade(const string& category) const {
        for (const auto& upgrade : AddedUpgrades) {
            if (upgrade == category) return true;
        }
        return false;
    }
    
    void addUpgrade(const string& category) {
        AddedUpgrades.push_back(category);
    }

//Used Deepseek to test code
    virtual void printStats() {
        cout << "Name: " << name << "\nLives: " << lives << "\nRange: " << range << "\nFire rate: " << fire << "\nBullets: " << bullets
             << "\nMove: " << move << "\nVision: " << vision << "\nPosition: (" << positionX << ", " << positionY << ")\n";
            cout << "Upgrades: ";
        for (const auto& upgrade : AddedUpgrades) {
            cout << upgrade << " ";
        }
        cout << endl;
    }
    

    void look() {
        int half = vision / 2;
        cout << name << " sees:\n";
        for (int y = positionY - half; y <= positionY + half; ++y) {
            for (int x = positionX - half; x <= positionX + half; ++x) {
                if (x < 0 || x >= MAP_WIDTH || y < 0 || y >= MAP_HEIGHT)
                    cout << "X";
                else if (x == positionX && y == positionY)
                    cout << "R";
                else
                    cout << ".";
            }
            cout << endl;
        }
    }
};

//Moving type Upgrades (HideBot, jumpBot, FastBot)
namespace Moving {
    class HideBot : public GenericRobot {
    public:
        int Hide = 3;
        bool Invi = false;

        HideBot(GenericRobot* base) : GenericRobot(*base) {
            cout << "** Upgraded to HIDE-BOT! **"<<endl;
            cout << "| Can now hide from enemies |"<<endl;
            addUpgrade("Moving");
        }

        void Hidden() {
            if (Hide > 0) {
                Hide--;
                Invi = true;
                cout << "HideBot is hiding and can't be detected by other bots... Hides left: " << Hide << endl;
            } else {
                cout << "HideBot has used up all its 'Hides'..." << endl;
            }
        }
    };

    class JumpBot : public GenericRobot {
    public:
        int Jumps = 3;

        JumpBot(GenericRobot* base) : GenericRobot(*base) {
            cout<<"** Upgraded to JUMP-BOT! **"<<endl;
            cout<<"| Can now jump to anywhere in the map |"<<endl;
            
            addUpgrade("Moving");
        }

        void jump() {
            if (Jumps > 0) {
                Jumps--;
                positionX = rand() % MAP_WIDTH;
                positionY = rand() % MAP_HEIGHT;
                cout << "Jumpbot used 'Jump' and landed somewhere in the map... Jumps left: " << Jumps << endl;
            } else {
                cout << "Jumpbot has ran out of 'Jumps'..." << endl;
            }
        }
    };

    class FastBot : public GenericRobot {
    public:
        int movement = 3;

        FastBot(GenericRobot* base) : GenericRobot(*base) {
            cout<<"** Upgraded to FAST-BOT! **"<<endl;
            cout<<"| Can now move 3 block ahead in one move |"<<endl;
            addUpgrade("Moving");
        }

        void FastMove() {
            if (movement > 0) {
                movement--;
                move = 3;
                cout << "Fastbot used 'Fast Move' and quickly moved ahead... Fast Moves left: " << movement << endl;
            } else {
                cout << "Fastbot ran out of 'Fast Moves'... " << endl;
            }
        }
    };
}

//Shooting type Upgrades (LongShot, SemiAutoBot, BomberBot)
namespace Shooting {
    class LongShotBot : public GenericRobot {
    public:
        LongShotBot(GenericRobot* base) : GenericRobot(*base) {
            range = 3;
            bullets = 13;
            cout << "** You are now upgraded to LONGSHOT-BOT! **" << endl;
            cout << "| EXTRA BULLETS ACQUIRED |" << endl;
            addUpgrade("Shooting");
        }
    };

    class SemiAutoBot : public GenericRobot {
    public:
        SemiAutoBot(GenericRobot* base) : GenericRobot(*base) {
            fire = 3;
            bullets = 13;
            cout << "** You are now upgraded to SEMI-AUTO-BOT! **" << endl;
            cout << "| You can now shoot 3 bullets at once |" << endl;
            cout << "| EXTRA BULLETS ACQUIRED |" << endl;
            addUpgrade("Shooting");
        }
    };

    class BomberBot : public GenericRobot {
    public:
        int Bombs = 3;
        int bullets = 13;
        BomberBot(GenericRobot* base) : GenericRobot(*base) {
            cout << "** Upgraded to BOMBER-BOT! **" << endl;
            cout << "| EXTRA BULLETS ACQUIRED |" << endl;
            cout << "| Can now deal area damage bomb anywhere in the map |" << endl;
            addUpgrade("Shooting");
        }

        void Bombing() {
            if (Bombs > 0) {
                Bombs--;
                cout << "BomberBot has dropped a bomb somewhere in the map... Bombs left: " << Bombs << endl;
            } else {
                cout << "BomberBot ran out of Bombs..." << endl;
            }
        }
    };
}

//Seeing type Upgrades (ScoutBot, TrackBot, VisionBot)
namespace Seeing {
    class ScoutBot : public GenericRobot {
    public:
        int scans = 3;
        bool Battlefield = false;

        ScoutBot(GenericRobot* base) : GenericRobot(*base) {
            cout << "** Upgraded to SCOUT-BOT! **" << endl;
            cout << "| Can now Scan the whole map |" << endl;
            addUpgrade("Seeing");
        }

        void Scan_Battlefield() {
            if (scans > 0) {
                scans--;
                Battlefield = true;
                cout << "ScoutBot uses 'Scan' to reveal battlefield... Scans left: " << scans << endl;
            } else {
                cout << "Scoutbot has used up all 'Scans'..." << endl;
            }
        }
    };

    class TrackBot : public GenericRobot {
    public: 
        int trackers = 3;
        
        TrackBot(GenericRobot* base) : GenericRobot(*base) {
            cout << "** Upgraded to TRACK-BOT! **" << endl;
            cout << "| Can now Track enemies in the map |" << endl;
            addUpgrade("Seeing");
        }

        void Track_Bots() {
            if (trackers > 0) {
                trackers--;
                cout << "TrackBot planted a tracker on an Enemy... Trackers left: " << trackers << endl;
            } else {
                cout << "TrackBot ran out of 'trackers'..." << endl;
            }
        }
    };

    class VisionBot : public GenericRobot {
    public:
        VisionBot(GenericRobot* base) : GenericRobot(*base) {
            vision += 2;
            cout << "** You are now upgraded to VISION-BOT! **" << endl;
            cout << "| Vision has been increased |" << endl;
            addUpgrade("Seeing");
        }
    };
}

//GenericRobot Upgrades
GenericRobot* Upgrade(GenericRobot* Bot, const string& category) {
    int RandUpgrades = rand() % 3;
    GenericRobot* upgradedBot = Bot;

    if (category == "Moving") {
        switch(RandUpgrades) {
            case 0: upgradedBot = new Moving::HideBot(Bot); break;
            case 1: upgradedBot = new Moving::JumpBot(Bot); break;
            case 2: upgradedBot = new Moving::FastBot(Bot); break;
        }
    }
    else if (category == "Shooting") {
        switch(RandUpgrades) {
            case 0: upgradedBot = new Shooting::LongShotBot(Bot); break;
            case 1: upgradedBot = new Shooting::SemiAutoBot(Bot); break;
            case 2: upgradedBot = new Shooting::BomberBot(Bot); break;
        }
    }
    else if (category == "Seeing") {
        switch (RandUpgrades) {
            case 0: upgradedBot = new Seeing::ScoutBot(Bot); break;
            case 1: upgradedBot = new Seeing::TrackBot(Bot); break;
            case 2: upgradedBot = new Seeing::VisionBot(Bot); break;
        }
    }
    if (upgradedBot != Bot){
        delete Bot;
    }
    return upgradedBot;  
}

int main() {
//Used Deepseek to test code
    srand(time(0));
    GenericRobot* bot = new GenericRobot("Bot", 3, 1, 1, 10, 1, 3);

    cout << "--- BEFORE UPGRADES ---\n";
    bot->printStats();
    bot->look();

    bot = Upgrade(bot, "Moving");
    bot = Upgrade(bot, "Shooting");
    bot = Upgrade(bot, "Seeing");

    cout << "\n--- AFTER SEEING UPGRADE ---\n";
    bot->printStats();
    bot->look();

    delete bot;
    return 0;
}