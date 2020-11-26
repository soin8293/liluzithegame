// CS1300 Spring 2020
// Author: Sorbarikor Inene and Christian Glatz
// Recitation: 123 – Richard Tillquist
// Project 3
#include <iostream>
#include <fstream>
#include "Planet.h"
#include "Character.h"
#include "Item.h"

using namespace std;

Planet::Planet()
{
    name="";
    description="";
    int currentWeather=0;
    weather=0;
    numMonsters=0;
    Character character1;
    for(int i=0; i<10; i++)
    {
        inhabitants[i]=character1;
    }
}

Planet::Planet(string n, string f, int w, int nm)
{
    name=n;
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
    int currentWeather=0;
    weather=w;
    numMonsters=nm;
    Character character1;
    for(int i=0; i<10; i++)
    {
        inhabitants[i]=character1;
    }
}

string Planet::getName()
{
    return name;
}

string Planet::getDescription()
{
    return description;
}

int Planet::getWeather()
{
    return weather;
}

//this function will use a randome number generator to find the current weather which will deviate from the weather integer to a certain degree.

void Planet::setCurrentWeather(int n)
{
    currentWeather=n;
}

int Planet::getCurrentWeather()
{
    return currentWeather;
}

int Planet::getNumMonsters()
{
    return numMonsters;
}

Character Planet::getCharacter(int p)
{
    return inhabitants[p];
}

void Planet::addCharacterAt(Character character1, int p)
{
    inhabitants[p]=character1;
    //cout<<"Character added @ inhabitants["<<p<<"]"<<endl;
}

void Planet::loseCharacterAt(int p)
{
    Character character1;
    inhabitants[p]=character1;
}

void Planet::setName(string n)
{
    name=n;
}

void Planet::setDescription(string f)
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

void Planet::setWeather(int w)
{
    weather=w;
}

int Planet::setNumMonsters(int nm)
{
    numMonsters=nm;
}


