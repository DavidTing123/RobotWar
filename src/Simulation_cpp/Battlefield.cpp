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
#include "Simulation/Battlefield.h"
#include <iostream>
using namespace std;

Battlefield::Battlefield(int w, int h) : width(w), height(h)
{
    grid.resize(height, vector<char>(width, '.'));
}

void Battlefield::clear()
{
    for (auto &row : grid)
        fill(row.begin(), row.end(), '.');
}

void Battlefield::placeRobot(int x, int y, char symbol)
{
    if (x >= 0 && x < width && y >= 0 && y < height)
        grid[y][x] = symbol;
}

void Battlefield::display() const
{
    for (const auto &row : grid)
    {
        for (char c : row)
            cout << c;
        cout << '\n';
    }
}
