// CS1300 Spring 2020
// Author: Sorbarikor Inene and Christian Glatz
// Recitation: 123 – Richard Tillquist
// Project 3
#ifndef CHARACTER_H
#define CHARACTER_H
#include <iostream>
#include "Item.h"
using namespace std;

class Character
{
    private:
        string type;
        string description;
        int health;
        int hitChance;
        int numItem;
        //index of item equipped max 5
        int equipped;
        //can have up to 5 items
        Item arrayItems[5];
    public:
        Character();
        Character(string t, string d, int h, int hc);
        string getType();
        string getDescription();
        int getHealth();
        int getHitChance();
        int getEquipped();
        int getNumItem();
        //given index - accesses arrayItems
        Item getItem(int);
        void setType(string);
        void setDescription(string);
        void setHealth(int);
        void setEquipped(int s);
        void setHitChance(int);
        void setNumItem(int);
        void replaceItem(int p, Item item1);
        //add equipped item from arrayItem array
        void pickUpItem(Item item1);
};

#endif

