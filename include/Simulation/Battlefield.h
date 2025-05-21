/**********|**********|**********|
Program: Battlefield.cpp / Battlefield.h
Course: OOPDS
Trimester: 2510
Name: Bradley Ben Lee, David Ting Zi Xiang, Esvan Rao A/L Perasath Raw
ID: 243UC245SA, 242UC244PE, 243UC245HJ
Lecture Section: TC1L
Tutorial Section: TT1L
Email: BRADLEY.BEN.LEE@student.mmu.edu.my, DAVID.TING.ZI@student.mmu.edu.my, esvan.rao.perasath@student.mmu.edu.my
Phone:  01151799588, 013-352 8910, 0162025996
**********|**********|**********/
#pragma once
#include <vector>
#include <string>
using namespace std;

class Battlefield
{
private:
    int width, height;
    vector<std::vector<char>> grid;

public:
    Battlefield(int w, int h);
    void clear();
    void placeRobot(int x, int y, char symbol);
    void display() const;
};
