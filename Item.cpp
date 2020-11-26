// CS1300 Spring 2020
// Author: Sorbarikor Inene and Christian Glatz
// Recitation: 123 – Richard Tillquist
// Project 3
#include <iostream>
#include <fstream>
#include "Item.h"

using namespace std;

Item::Item()
{
    name="";
    description="";
    damage=0;
}

Item::Item(string n, string f, int d)
{
    name=n;
    damage=d;
    ifstream text;
    text.open(f);
    if(text.fail())
    {
        description="";
        return;
    }
    string line;
    while(getline(text, line))
    {
        int pos;
        pos=line.find(':',0);
        if(name==line.substr(0,pos))
        {
            description=line.substr(pos+2);
        }
    }
}

string Item::getName()
{
    return name;
}

string Item::getDescription()
{
    return description;
}

int Item::getDamage()
{
    return damage;
}

void Item::setName(string n)
{
    name=n;
}

void Item::setDescription(string f)
{
    ifstream text;
    text.open(f);
    if(text.fail())
    {
        description="";
        return;
    }
    string line;
    while(getline(text, line))
    {
        int pos;
        pos=line.find(':',0);
        if(name==line.substr(0,pos))
        {
            description=line.substr(pos+2);
        }
    }
}

void Item::setDamage(int d)
{
    damage=d;
}


