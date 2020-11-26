#ifndef ITEM_H
#define ITEM_H

// CS1300 Spring 2020
// Author: Sorbarikor Inene and Christian Glatz
// Recitation: 123 – Richard Tillquist
// Project 3
#include <iostream>

using namespace std;

class Item
{
    private:
        string name;
        string description;
        int damage;
    public:
        Item();
        Item(string n, string f, int d);
        string getName();
        string getDescription();
        int getDamage();
        void setName(string n);
        void setDescription(string f);
        void setDamage(int d);
};

#endif


