// CS1300 Spring 2020
// Author: Sorbarikor Inene and Christian Glatz
// Recitation: 123 – Richard Tillquist
// Project 3
#include <iostream>
#include "Character.h"

using namespace std;

Character::Character()
{
    type = "Unknown";
    description = "Unknown";
    health = 0;
    hitChance = 0;
    numItem = 0;
    for(int i=0;i<5;i++)
    {
        Item empty("Empty","items.txt",0);
        arrayItems[i]=empty;
    }
}

Character::Character(string t, string d, int h, int hc)
{
    type = t;
    description  = d;
    health = h;
    hitChance = hc;
    numItem=0;
    for(int i=0;i<5;i++)
    {
        Item empty("Empty","items.txt",0);
        arrayItems[i]=empty;
    }
}

string Character::getType()
{
    return type;
}

string Character::getDescription()
{
    return description;
}

int Character::getHealth()
{
    return health;
}

int Character::getHitChance()
{
    return hitChance;
}

int Character::getNumItem()
{
    return numItem;
}

void Character::setEquipped(int s)
{
    equipped=s;
}

int Character::getEquipped()
{
    return equipped;
}

//returns item in arrayItem given index
Item Character::getItem(int s)
{
    if(s >= 0 && s < 6)
        return arrayItems[s];
    else
        cout<<"You're arrayItem index is wrong/out of bounds!"<<endl;
}

void Character::setType(string s)
{
    type = s;
}

void Character::setDescription(string s)
{
    description = s;
}

void Character::setHealth(int s)
{
    health = s;
//    cout<<"Entered: "<<s<<" Health is now: "<<health<<"? \n";
}

void Character::setHitChance(int s)
{
    hitChance = s;
}

void Character::setNumItem(int s)
{
    numItem = s;
}

//removes equipped item from arrayItem array
void Character::replaceItem(int p, Item item2)
{
    arrayItems[p]=item2;
}

//add item to arrayItem array
void Character::pickUpItem(Item item1)
{
    if(numItem>=5)
    {
        cout<<"Your inventory is full."<<endl;
        return;
    }
    else
    {
        arrayItems[numItem]=item1;
        //cout<<item1.getName()<<" has been added to the inventory"<<endl;
        numItem++;
        return;
    }
}


