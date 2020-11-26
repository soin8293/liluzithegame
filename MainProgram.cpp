// CS1300 Spring 2020
// Author: Sorbarikor Inene and Christian Glatz
// Recitation: 123 – Richard Tillquist
// Project 3
#include <iostream>
#include <fstream>
#include <time.h>
#include "Planet.h"
using namespace std;

Planet arrayOfPlanets[9];
Item arrayOfWeapons[9];
int currentPlanetIndex = 0;
Planet currentPlanet;
string currentPlanetName;
int numberOfPlanets = 9;

int findWeather(Planet planet1)
{
    srand(time(NULL));
    //Ranges from 0(Unfathomably terrible weather) to 100(Perfect)
    int weather=planet1.getWeather();
    //The current weather can vary anywhere from +/- 10 the average degree
    int currentWeather=(weather-10)+(rand()%21);
    return currentWeather;
}

//With calculate whether or not weapon hit depending on the weather(0-100) and hit chance(0-100) of current weapon
bool hit(int currentWeather,int hc)
{
    srand(time(NULL));
    int total=currentWeather+hc;
    int hit = rand()%201;
    if(total<hit)
    {
        return false;
    }
    else
    {
        return true;
    }
}


int runMenu1(){
    int option;
    cout<<"### Please select an option. ###"<<endl;
    cout<<"1. Start New Game"<<endl;
    cout<<"2. Read game description"<<endl;
    cout<<"3. Quit"<<endl;
    cin>>option;
    cin.clear();
    cin.ignore();
    switch(option){
        case 1:
            return 1;
            break;
        case 2:
            cout<<"This is a turn based RPG coded in C++ created for a CS project at the University of Colorado Boulder.\n This game was completed 4-23-20 in the midst of the boredom and terror of the COVID-19 pandemic."<<endl;
            runMenu1();
            break;
        case 3:
            cout<<"Good-bye!"<<endl;
            return 3;
            break;
        default:
            cout<<"### Select a valid option -.- ###"<<endl;
            runMenu1();
            break;
    }
}

int continueGame(){
    char chars;
    int option;
//    cout<<"got: "<<option<<endl;
    cout<<"### Continue? Y/N ###"<<endl;
    cin>>chars;
    option = chars;
    cin.clear();
 //   cout<<"ping out: "<<option<<endl;;
    switch(option){
    case 89:
        return 1;
        break;
    case 121:
        return 1;
        break;
    case 78:
        continueGame();
        break;
    case 110:
        continueGame();
        break;
    default:
        cout<<"### Select a valid option -.- ###"<<endl;
        continueGame();
        break;
    }
    return option;
}


int main(){
    string line1;
    fstream logo;
    logo.open("logo.txt");
    while(getline(logo,line1))
    {
        cout<<line1<<endl;
    }
    //Read planets info
    Planet Mercury("Mercury","planets.txt",70,1);
    Planet Venus("Venus","planets.txt",50,7);
    Planet Earth("Earth","planets.txt",10,2);
    Planet Mars("Mars","planets.txt",30,3);
    Planet Jupiter("Jupiter","planets.txt",75,3);
    Planet Saturn("Saturn","planets.txt",85,5);
    Planet Uranus("Uranus","planets.txt",90,2);
    Planet Neptune("Neptune","planets.txt",60,5);
    Planet Pluto("Pluto","planets.txt",10,1);
    
    //Load up enemies and equips their weapons
    Item famas("Fire Lizard Famas","items.txt",20);
    Item ar("Fire Ant AR","items.txt",15);
    Item sniper("Space Inavder Sniper","items.txt",35);
    Item snw("Space Inavder Smith & Wesson","items.txt",20);
    Item jet("Kardashian JacuzziJet","items.txt",15);
    Item teeth("gnarly teeth","items.txt",40);
    Item paws("massive paws","items.txt",45);
    Item wns("Space Inavder Wesson & Smith","items.txt",25);
    Item bigUzi("Big Uzi","items.txt",49);

    Character lizard("monster","hostile fire lizard", 75, 85);
    lizard.pickUpItem(famas);
    Mercury.addCharacterAt(lizard, 1);
    Mercury.setCurrentWeather(findWeather(Mercury));
    arrayOfPlanets[0] = Mercury;
    
    Character ant1("monster","hostile mutant fire ant", 20, 70);
    Venus.addCharacterAt(ant1, 1);
    Character ant2("monster","hostile mutant fire ant", 20, 70);
    Venus.addCharacterAt(ant2, 2);
    Character ant3("monster","hostile mutant fire ant", 20, 70);
    Venus.addCharacterAt(ant3, 3);
    Character ant4("monster","hostile mutant fire ant", 20, 70);
    Venus.addCharacterAt(ant4, 4);
    Character ant5("monster","hostile mutant fire ant", 20, 70);
    Venus.addCharacterAt(ant5, 5);
    Character ant6("monster","hostile mutant fire ant", 20, 70);
    Venus.addCharacterAt(ant6, 6);
    Character ant7("monster","hostile mutant fire ant", 20, 70);
    Venus.addCharacterAt(ant7, 7);
    for(int i=1;i<8;i++)
    {
        for(int j=0;j<5;j++)
        {
            Venus.getCharacter(i).pickUpItem(ar);
        }
    }
    arrayOfPlanets[1] = Venus;
    

    Character SI1("monster","Space Invader soldier",120,80);
    Earth.addCharacterAt(SI1,1);
    Character SI2("monster","Space Invader soldier",120,80);
    Earth.addCharacterAt(SI2,2);
    for(int i=1;i<3;i++)
    {
        for(int j=0;j<5;j++)
        {
            Earth.getCharacter(i).pickUpItem(sniper);
        }
    }
    arrayOfPlanets[2] = Earth;

    Character SI3("monster","Space Invader soldier",120,80);
    Mars.addCharacterAt(SI3,1);
    Character SI4("monster","Space Invader soldier",120,80);
    Mars.addCharacterAt(SI4,2);
    Character SI5("monster","Space Invader soldier",120,80);
    Mars.addCharacterAt(SI5,3);
    for(int i=1;i<4;i++)
    {
        for(int j=0;j<5;j++)
        {
            Mars.getCharacter(i).pickUpItem(snw);
        }
    }
    arrayOfPlanets[3] = Mars;
    
    
    Character Kardashian1("monster","hostile Kardashian",200,50);
    Jupiter.addCharacterAt(Kardashian1,1);
    Character Kardashian2("monster","hostile Kardashian",200,50);
    Jupiter.addCharacterAt(Kardashian2,2);
    Character Kardashian3("monster","hostile Kardashian",200,50);
    Jupiter.addCharacterAt(Kardashian3,3);
    for(int i=1;i<4;i++)
    {
        for(int j=0;j<5;j++)
        {
            Jupiter.getCharacter(i).pickUpItem(jet);
        }
    }
    arrayOfPlanets[4] = Jupiter;
    
    Character Dolfinbat1("monster","hostile Dolfinbat",25,80);
    Saturn.addCharacterAt(Dolfinbat1,1);
    Character Dolfinbat2("monster","hostile Dolfinbat",25,80);
    Saturn.addCharacterAt(Dolfinbat2,2);
    Character Dolfinbat3("monster","hostile Dolfinbat",25,80);
    Saturn.addCharacterAt(Dolfinbat3,3);
    Character Dolfinbat4("monster","hostile Dolfinbat",25,80);
    Saturn.addCharacterAt(Dolfinbat4,4);
    Character Dolfinbat5("monster","hostile Dolfinbat",25,80);
    Saturn.addCharacterAt(Dolfinbat5,5);
    for(int i=1;i<6;i++)
    {
        for(int j=0;j<5;j++)
        {
            Saturn.getCharacter(i).pickUpItem(teeth);
        }
    }
    arrayOfPlanets[5] = Saturn;

    Character Icee1("monster","hostile Icee Bear",200,20);
    Uranus.addCharacterAt(Icee1,1);
    Character Icee2("monster","hostile Icee Bear",200,20);
    Uranus.addCharacterAt(Icee2,2);
    for(int i=1;i<3;i++)
    {
        for(int j=0;j<5;j++)
        {
            Uranus.getCharacter(i).pickUpItem(paws);
        }
    }
    arrayOfPlanets[6] = Uranus;
    
    Character SI6("monster","Space Invader soldier",120,80);
    Neptune.addCharacterAt(SI6,1);
    Character SI7("monster","Space Invader soldier",120,80);
    Neptune.addCharacterAt(SI7,2);
    Character SI8("monster","Space Invader soldier",120,80);
    Neptune.addCharacterAt(SI8,3);
    Character SI9("monster","Space Invader soldier",120,80);
    Neptune.addCharacterAt(SI9,4);
    Character SI10("monster","Space Invader soldier",120,80);
    Neptune.addCharacterAt(SI10,5);
    for(int i=1;i<6;i++)
    {
        for(int j=0;j<5;j++)
        {
            Neptune.getCharacter(i).pickUpItem(wns);
        }
    }
    arrayOfPlanets[7] = Neptune;
    
    Character Uzi("boss","Lil Uzi Vert",500,100);
    Pluto.addCharacterAt(Uzi,1);
    Uzi.pickUpItem(bigUzi);
    arrayOfPlanets[8] = Pluto;

    //Loads up player weapons
    Item Glock18("Glock-18","items.txt",25);
    arrayOfWeapons[0] = Glock18;
    Item Mac11("Mac-11","items.txt",30);
    arrayOfWeapons[1] = Mac11;
    Item AlienPistol("M-3 Predator","items.txt",36);
    arrayOfWeapons[2] = AlienPistol;
    Item AlienAssualtRifle("DL-44 Blaster","items.txt",45);
    arrayOfWeapons[3] = AlienAssualtRifle;
    Item AK47("AK-47","items.txt",40);
    arrayOfWeapons[4] = AK47;
    Item Flamethower("Flamethrower","items.txt",43);
    arrayOfWeapons[5] =Flamethower;
    Item RayGun("Ray Gun","items.txt",75);
    arrayOfWeapons[6] = RayGun;
    Item MiniGun("M134 Mini Gun","items.txt",80);
    arrayOfWeapons[7] = MiniGun;
    Item Helicopter("AH-64 Apache Helicopter","items.txt",99);
    arrayOfWeapons[8] = Helicopter;
    
    
    //Loads up player
    Character player;
    player.setHitChance(90);
    
    //Initializes need variables
    int meds = 3;
    int currentEnemyHealth;
    
    cout<<"==========Main Menu=========="<<endl;
    int option1;
    option1 = runMenu1();
    if(option1 == 3)
        return 0;
    cout<<"==========SPACE INVADERS: VERTICAL UPRISE=========="<<endl;
    cout<<"A lone soldier wakes up from their 21 year journey. \n";
    fstream playerInfo;
    playerInfo.open ("player.txt");
    string des1;
    cout<<"###Enter your character Description(Name)###\n";
    //cin>>des1;
    getline(cin,des1);
    playerInfo << des1;
    cin.clear();
    player.setDescription(des1);
    cout<<"The "<<player.getDescription()<<" opens their eyes for the first time in 21 years. \n";
    cout<<"A newly developed technology has given this person the compiled \n";
    cout<<"information of all human knowledge. This person is an expert in \n";
    cout<<"quantum mechanics, but still has no circumstantial knowledge. Only \n";
    cout<<"one piece of human knowledge was taken from this person’s mind: the \n";
    cout<<"history of humanity’s old home. They read the following message: \n";
    cout<<"“You are a human sent by humans to explore our old home. \n";
    cout<<"Us humans originated in a remote solar system in the Milky Way galaxy.\n";
    cout<<"We had colonized this solar system for many centuries, but in the year\n";
    cout<<"10578 AD, a mysterious force came to take our solar system. We know them\n";
    cout<<"as the Space Invaders. We don’t know their species or origin, only their intent.\n";
    continueGame();
    cout<<"A war with the Space Invaders began, and after decades of war, we desperate \n";
    cout<<"humans had found a potential new solar system that was untouched by alien forces \n";
    cout<<"that could harbor a new beginning for mankind. In a final destructive effort,\n";
    cout<<"humans detonated 7 bombs, one on each continent to distract the Space Invaders as \n";
    cout<<"we escaped. This killed 98% of all non-human life in the solar system. At this\n";
    cout<<"point in time humans left never to return to the solar system until now. Your mission \n";
    cout<<"is to scout the solar system. You have direct orders to kill any and all threatening \n";
    cout<<"life. There are several threats that you will encounter. Radiation still plagues the \n";
    cout<<"planet and it is likely that life in this solar system has mutated due to \n";
    cout<<"radiation. Space Invaders and other life in the solar system might still pose a threat\n";
    cout<<"to your presence. It is also very likely that the nuclear extinction attracted other \n";
    cout<<"alien life forms that want to take their share of this solar system.\n";
    cout<<"Before you land on each planet, your spacecraft will be able to collect stored\n";
    cout<<"information on each planet and give you a summary of what to expect when you land. Once\n";
    cout<<"you have completed your mission, press the red button in the spacecraft and human\n";
    cout<<"reinforcements will arrive.\n";
    continueGame();
    cout<<"On each planet you will have allocated three healing devices. When flying to the next planet, you will be able to fully heal.\n";
    cout<<"There will be five left over on Pluto. You will likely find weapons as this solar system\n";
    cout<<"was an ancient battleground. However, once you leave a weapon behind, it will likely be taken by rogue scavengers.\n";
    cout<<"You can hold five weapons at a time.\n";
    cout<<"The radiation has created extreme weather on every planet. It will be hard to land all of your shots.\n";
    cout<<"The weather will be rated out of 100 at each planet.\n";
    cout<<"Invade the Space Invaders!"<<endl;
    continueGame();
    
    /////////////////////////////LEVEL 1/////////////////////////////

    //add character to planet
    arrayOfPlanets[currentPlanetIndex].addCharacterAt(player, arrayOfPlanets[currentPlanetIndex].getNumMonsters());
    player.setHealth(100);
    player.setType("Soldier");
    player.pickUpItem(Glock18);
    //variable starts timing the time it takes to finish the game
    time_t start_s=time(0);
    cout<<"==========Welcome to "<<arrayOfPlanets[currentPlanetIndex].getName()<<"========== \n";
    cout<<"***Planet Description***: "<<arrayOfPlanets[currentPlanetIndex].getDescription()<<"\n"<<endl;
    cout<<"Current weather: "<<Mercury.getCurrentWeather()<<endl;
    cout<<"You arrive on Mercury and bionic scans reveal there is one fire lizard within your field of view."<<endl;
    cout<<"You currently have your "<<player.getItem(player.getEquipped()).getName()<<" equipped."<<endl;
    while(player.getHealth()>0 && lizard.getHealth()>0)
    {
        Item equippedItem=player.getItem(player.getEquipped());
              int move;
        cout<<"Do you...?\n1)Take cover and heal\n2)Shoot\n3)Take cover and change weapons"<<endl;
        cin>>move;
        cin.clear();
        switch (move)
        {
            case 1:
                if(meds>0)
                {
                    cout<<"You eat one slice of roast beef."<<endl;
                    player.setHealth(player.getHealth()+30);
                    meds--;
                }
                else
                {
                    cout<<"You are out of roast beef."<<endl;
                }
                break;
            case 2:
                if(hit(Mercury.getCurrentWeather(),lizard.getHitChance()))
                {
                    player.setHealth(player.getHealth()-famas.getDamage());
                    cout<<"You took "<<famas.getDamage()<<" damage."<<endl;
                }
                else
                {
                    cout<<"The lizard missed his shot."<<endl;
                }
                if(hit(Mercury.getCurrentWeather(),player.getHitChance()))
                {
                    lizard.setHealth(lizard.getHealth()-equippedItem.getDamage());
                    cout<<"The lizard took "<<equippedItem.getDamage()<<" damage."<<endl;
                }
                else
                {
                    cout<<"You missed your shot"<<endl;
                }
                break;
            case 3:
                int choice;
                cout<<"Which weapon do you want to equip?\n1)"<<player.getItem(0).getName()<<"\n2)"<<player.getItem(1).getName()<<"\n3)"<<player.getItem(2).getName()<<"\n4)"<<player.getItem(3).getName()<<"\n5)"<<player.getItem(4).getName()<<endl;
                cin>>choice;
                cin.clear();
                switch (choice)
                {
                    case 1:
                        player.setEquipped(0);
                        break;
                    case 2:
                        player.setEquipped(1);
                        break;
                    case 3:
                        player.setEquipped(2);
                        break;
                    case 4:
                        player.setEquipped(3);
                        break;
                    case 5:
                        player.setEquipped(4);
                        break;
                    default:
                        cout<<"Invalid Input"<<endl;
                        break;
                }
                break;
            default:
                cout<<"Incorrect Input"<<endl;
                break;
        }
        cout<<"Your health: "<<player.getHealth()<<"\nEnemies total health: "<<lizard.getHealth()<<endl;
    }
    if(player.getHealth()==0)
    {
        cout<<"Game Over."<<endl;
        return 0;
        //return to main menu
    }
    else
    {
        cout<<"You killed all enemies."<<endl;
    }
    int move;
    while(move!=4)
    {
        cout<<"Do you...?\n1)Explore\n2)Pick up weapon\n3)Replace weapon\n4)Leave planet"<<endl;
        cin>>move;
        cin.clear();
        switch (move)
        {
            case 1:
                cout<<"You find the "<<famas.getName()<<endl;
                break;
            case 2:
                player.pickUpItem(famas);
                break;
            case 3:
                int choice;
                cout<<"Which item would you like to replace?\n1)"<<player.getItem(0).getName()<<"\n2)"<<player.getItem(1).getName()<<"\n3)"<<player.getItem(2).getName()<<"\n4)"<<player.getItem(3).getName()<<"\n5)"<<player.getItem(4).getName()<<endl;
                cin>>choice;
                switch (choice)
                {
                    case 1:
                        player.replaceItem(0,famas);
                        break;
                    case 2:
                        player.replaceItem(1,famas);
                        break;
                    case 3:
                        player.replaceItem(2,famas);
                        break;
                    case 4:
                        player.replaceItem(3,famas);
                        break;
                    case 5:
                        player.replaceItem(4,famas);
                        break;
                    default:
                        cout<<"Incorrect Input"<<endl;
                        break;
                }
                break;
            case 4:
                break;
            default:
                cout<<"Incorrect Input"<<endl;
                break;
        }
    }
    currentPlanetIndex++;
    
    /////////////////////////////LEVEL 2/////////////////////////////

    currentPlanet = arrayOfPlanets[currentPlanetIndex];
    currentPlanetName = arrayOfPlanets[currentPlanetIndex].getName();
    meds=3;
    player.setHealth(150);
    int numOfEnemies = currentPlanet.getNumMonsters();
    
    currentPlanet.setCurrentWeather(findWeather(currentPlanet));
    
    cout<<"==========Welcome to "<<currentPlanet.getName()<<"========== \n";
    cout<<"***Planet Description***: "<<arrayOfPlanets[currentPlanetIndex].getDescription()<<"\n"<<endl;
    cout<<"Current weather: "<<currentPlanet.getCurrentWeather()<<endl;
    cout<<"NOTICE!: A old Mac-11 is dicovered in the dirt. Do you...? \n1)Take it\n2)Replace it with a gun in your inventory\n3)Leave it\n";
    cin>>move;
    cin.clear();
    switch(move){
        case 1:
            player.pickUpItem(Mac11);
            break;
        case 2:
                int choice;
                cout<<"Which item would you like to replace?\n1)"<<player.getItem(0).getName()<<"\n2)"<<player.getItem(1).getName()<<"\n3)"<<player.getItem(2).getName()<<"\n4)"<<player.getItem(3).getName()<<"\n5)"<<player.getItem(4).getName()<<endl;
                cin>>choice;
                switch (choice)
                {
                    case 1:
                        player.replaceItem(0,Mac11);
                        break;
                    case 2:
                        player.replaceItem(1,Mac11);
                        break;
                    case 3:
                        player.replaceItem(2,Mac11);
                        break;
                    case 4:
                        player.replaceItem(3,Mac11);
                        break;
                    case 5:
                        player.replaceItem(4,Mac11);
                        break;
                    default:
                        cout<<"Incorrect Input"<<endl;
                        break;
                }
                break;
        case 3:
            cout<<"Your loss. \n";
            break;
        default:
            cout<<"It's yes or no son. \n";
            break;
    }
    
    cout<<"You arrive on "<<currentPlanetName<<" and bionic scans reveal there is "<<currentPlanet.getNumMonsters()<<" fire ants within your field of view."<<endl;
    cout<<"You currently have your "<<player.getItem(player.getEquipped()).getName()<<" equipped."<<endl;
    currentEnemyHealth = currentPlanet.getCharacter(numOfEnemies).getHealth();
    while(player.getHealth() > 0 && numOfEnemies > 0)
    {
        Item equippedItem = player.getItem(player.getEquipped());
        cout<<"Do you...?\n1)Take cover and heal\n2)Shoot\n3)Take cover and change weapons"<<endl;
        cin>>move;
        cin.clear();
        switch (move)
        {
            case 1:
                //you heal yourself
                if(meds>0)
                {
                    cout<<"You eat one ant leg."<<endl;
                    player.setHealth(player.getHealth()+40);
                    meds--;
                }
                else
                {
                    cout<<"You are out of ant legs."<<endl;
                }
                break;
            case 2:
                //Player attacks
                currentEnemyHealth = currentPlanet.getCharacter(numOfEnemies).getHealth();
                if(hit(currentPlanet.getCurrentWeather(),player.getHitChance()))
                {
                    //applies damage
                    Character attacked = currentPlanet.getCharacter(numOfEnemies);
                    attacked.setHealth(currentEnemyHealth-equippedItem.getDamage());
                    currentEnemyHealth=currentEnemyHealth-equippedItem.getDamage();
                    currentPlanet.addCharacterAt(attacked,numOfEnemies);
                   
                   //Displays What just happened
                    cout<<"The "<<currentPlanet.getCharacter(numOfEnemies).getDescription()<<" took "<<equippedItem.getDamage()<<" damage."<<endl;
                    
                    //if enemy is dead    
                    if(currentEnemyHealth <= 0)
                    {
                        attacked.setHealth(0);
                        currentEnemyHealth=0;
                        numOfEnemies--;
                        cout<<"This enemy was eliminated! There are: "<<numOfEnemies<<" attacking!"<<endl;
                    }
                }
                else
                {
                    cout<<"You missed your shot."<<endl;
                }
                
                //Enemy attacks
                if(hit(currentPlanet.getCurrentWeather(),ant1.getHitChance()))
                {
                    player.setHealth(player.getHealth()-ar.getDamage());
                    cout<<"You took "<<ar.getDamage()<<" damage."<<endl;
                }
                else
                {
                    cout<<"The ant missed his shot."<<endl;
                }
                break;
            case 3:
                int choice;
                cout<<"Which weapon do you want to equip?\n1)"<<player.getItem(0).getName()<<"\n2)"<<player.getItem(1).getName()<<"\n3)"<<player.getItem(2).getName()<<"\n4)"<<player.getItem(3).getName()<<"\n5)"<<player.getItem(4).getName()<<endl;
                cin>>choice;
                cin.clear();
                switch (choice)
                {
                    case 1:
                        player.setEquipped(0);
                        break;
                    case 2:
                        player.setEquipped(1);
                        break;
                    case 3:
                        player.setEquipped(2);
                        break;
                    case 4:
                        player.setEquipped(3);
                        break;
                    case 5:
                        player.setEquipped(4);
                        break;
                    default:
                        cout<<"Incorrect Input"<<endl;
                        break;
                }
                break;
            default:
                cout<<"Incorrect Input"<<endl;
                break;
        }
        cout<<"===STATUS REPORT=== \nYour health: "<<player.getHealth()<<"\nEnemy health: "<<currentEnemyHealth<<endl;
    }
    
    //Did you die?
    if(player.getHealth()<=0)
    {
        cout<<"Game Over."<<endl;
        return 0;
    }
    
    //Did you defeat all the enemies?
    if(numOfEnemies == 0)
        cout<<"### You killed all enemies. ###"<<endl;
    
    //Next scene
    while(move!=4)
    {
        cout<<"Do you...?\n1)Explore\n2)Pick up weapon\n3)Replace weapon\n4)Leave planet"<<endl;
        cin>>move;
        cin.clear();
        switch (move)
        {
            case 1:
                cout<<"You find the "<<ar.getName()<<endl;
                break;
            case 2:
                player.pickUpItem(ar);
                break;
            case 3:
                int choice;
                cout<<"Which item would you like to replace?\n1)"<<player.getItem(0).getName()<<"\n2)"<<player.getItem(1).getName()<<"\n3)"<<player.getItem(2).getName()<<"\n4)"<<player.getItem(3).getName()<<"\n5)"<<player.getItem(4).getName()<<endl;
                cin>>choice;
                switch (choice)
                {
                    case 1:
                        player.replaceItem(0,ar);
                        break;
                    case 2:
                        player.replaceItem(1,ar);
                        break;
                    case 3:
                        player.replaceItem(2,ar);
                        break;
                    case 4:
                        player.replaceItem(3,ar);
                        break;
                    case 5:
                        player.replaceItem(4,ar);
                        break;
                    default:
                        cout<<"Incorrect Input"<<endl;
                        break;
                }
                break;
            case 4:
                break;
            default:
                cout<<"Incorrect Input"<<endl;
                break;
        }
    }
    currentPlanetIndex++;
     /////////////////////////////LEVEL 3/////////////////////////////
    
    currentPlanet = arrayOfPlanets[currentPlanetIndex];
    currentPlanetName = arrayOfPlanets[currentPlanetIndex].getName();
    meds=3;
    player.setHealth(150);
    numOfEnemies = currentPlanet.getNumMonsters();

    currentPlanet.setCurrentWeather(findWeather(currentPlanet));
    
    cout<<"==========Welcome to "<<currentPlanet.getName()<<"========== \n";
    cout<<"***Planet Description***: "<<arrayOfPlanets[currentPlanetIndex].getDescription()<<"\n"<<endl;
    cout<<"Current weather: "<<currentPlanet.getCurrentWeather()<<endl;
    cout<<"NOTICE!: You found a M-3 Predator Alien Blaster in you laundry bin in your room on the ship. Do you...? \n1)Take it\n2)Replace it with a gun in your inventory\n3)Leave it\n";
    cin>>move;
    cin.clear();
    switch(move){
        case 1:
            player.pickUpItem(AlienPistol);
            break;
        case 2:
                int choice;
                cout<<"Which item would you like to replace?\n1)"<<player.getItem(0).getName()<<"\n2)"<<player.getItem(1).getName()<<"\n3)"<<player.getItem(2).getName()<<"\n4)"<<player.getItem(3).getName()<<"\n5)"<<player.getItem(4).getName()<<endl;
                cin>>choice;
                switch (choice)
                {
                    case 1:
                        player.replaceItem(0,AlienPistol);
                        break;
                    case 2:
                        player.replaceItem(1,AlienPistol);
                        break;
                    case 3:
                        player.replaceItem(2,AlienPistol);
                        break;
                    case 4:
                        player.replaceItem(3,AlienPistol);
                        break;
                    case 5:
                        player.replaceItem(4,AlienPistol);
                        break;
                    default:
                        cout<<"Incorrect Input"<<endl;
                        break;
                }
                break;
        case 3:
            cout<<"Your loss. \n";
            break;
        default:
            cout<<"Si o no senior por favor. \n";
            break;
    }
    
    cout<<"You arrive on "<<currentPlanetName<<" and bionic scans reveal there are...OH GOD! "<<currentPlanet.getNumMonsters()<<" SPACE INVADERS SOLDIERS within your field of view."<<endl;
    cout<<"You currently have your "<<player.getItem(player.getEquipped()).getName()<<" equipped."<<endl;
    currentEnemyHealth = currentPlanet.getCharacter(numOfEnemies).getHealth();
    while(player.getHealth() > 0 && numOfEnemies > 0)
    {
        Item equippedItem = player.getItem(player.getEquipped());
        cout<<"Do you...?\n1)Take cover and heal\n2)Shoot\n3)Take cover and change weapons"<<endl;
        cin>>move;
        cin.clear();
        switch (move)
        {
            case 1:
                //you heal yourself
                if(meds>0)
                {
                    cout<<"You eat one Space Invader shoe."<<endl;
                    player.setHealth(player.getHealth()+50);
                    meds--;
                }
                else
                {
                    cout<<"You are out of Space Invader shoe."<<endl;
                }
                break;
            case 2:
                //Player attacks
                currentEnemyHealth = currentPlanet.getCharacter(numOfEnemies).getHealth();
                if(hit(currentPlanet.getCurrentWeather(),player.getHitChance()))
                {
                    //applies damage
                    Character attacked = currentPlanet.getCharacter(numOfEnemies);
                    attacked.setHealth(currentEnemyHealth-equippedItem.getDamage());
                    currentEnemyHealth=currentEnemyHealth-equippedItem.getDamage();
                    currentPlanet.addCharacterAt(attacked,numOfEnemies);
                   
                   //Displays What just happened
                    cout<<"The "<<currentPlanet.getCharacter(numOfEnemies).getDescription()<<" took "<<equippedItem.getDamage()<<" damage."<<endl;
                    
                    //if enemy is dead    
                    if(currentEnemyHealth <= 0)
                    {
                        attacked.setHealth(0);
                        currentEnemyHealth=0;
                        numOfEnemies--;
                        cout<<"This enemy was eliminated! There are: "<<numOfEnemies<<" attacking!"<<endl;
                    }
                }
                else
                {
                    cout<<"You missed your shot."<<endl;
                }
                
                //Enemy attacks
                if(hit(currentPlanet.getCurrentWeather(),SI4.getHitChance()))
                {
                    player.setHealth(player.getHealth()-sniper.getDamage());
                    cout<<"You took "<<sniper.getDamage()<<" damage."<<endl;
                }
                else
                {
                    cout<<"The Space Invader soldier missed his shot."<<endl;
                }
                
                break;
            case 3:
                int choice;
                cout<<"Which weapon do you want to equip?\n1)"<<player.getItem(0).getName()<<"\n2)"<<player.getItem(1).getName()<<"\n3)"<<player.getItem(2).getName()<<"\n4)"<<player.getItem(3).getName()<<"\n5)"<<player.getItem(4).getName()<<endl;
                cin>>choice;
                cin.clear();
                switch (choice)
                {
                    case 1:
                        player.setEquipped(0);
                        break;
                    case 2:
                        player.setEquipped(1);
                        break;
                    case 3:
                        player.setEquipped(2);
                        break;
                    case 4:
                        player.setEquipped(3);
                        break;
                    case 5:
                        player.setEquipped(4);
                        break;
                    default:
                        cout<<"Incorrect Input"<<endl;
                        break;
                }
                break;
            default:
                cout<<"Incorrect Input"<<endl;
                break;
        }
        cout<<"===STATUS REPORT=== \nYour health: "<<player.getHealth()<<"\nEnemy health: "<<currentEnemyHealth<<endl;
    }
    
    //Did you die?
    if(player.getHealth()<=0)
    {
        cout<<"Game Over."<<endl;
        return 0;
    }
    
    //Did you defeat all the enemies?
    if(numOfEnemies == 0)
        cout<<"### You killed all enemies. ###"<<endl;
    
    //Next scene
    while(move!=4)
    {
        cout<<"Do you...?\n1)Explore\n2)Pick up weapon\n3)Replace weapon\n4)Leave planet"<<endl;
        cin>>move;
        cin.clear();
        switch (move)
        {
            case 1:
                cout<<"You find the "<<sniper.getName()<<endl;
                break;
            case 2:
                player.pickUpItem(sniper);
                break;
            case 3:
                int choice;
                cout<<"Which item would you like to replace?\n1)"<<player.getItem(0).getName()<<"\n2)"<<player.getItem(1).getName()<<"\n3)"<<player.getItem(2).getName()<<"\n4)"<<player.getItem(3).getName()<<"\n5)"<<player.getItem(4).getName()<<endl;
                cin>>choice;
                switch (choice)
                {
                    case 1:
                        player.replaceItem(0,sniper);
                        break;
                    case 2:
                        player.replaceItem(1,sniper);
                        break;
                    case 3:
                        player.replaceItem(2,sniper);
                        break;
                    case 4:
                        player.replaceItem(3,sniper);
                        break;
                    case 5:
                        player.replaceItem(4,sniper);
                        break;
                    default:
                        cout<<"Incorrect Input"<<endl;
                        break;
                }
                break;
            case 4:
                break;
            default:
                cout<<"Incorrect Input"<<endl;
                break;
        }
    }
    currentPlanetIndex++;
    /////////////////////////////LEVEL 4/////////////////////////////
    
    currentPlanet = arrayOfPlanets[currentPlanetIndex];
    currentPlanetName = arrayOfPlanets[currentPlanetIndex].getName();
    meds=3;
    player.setHealth(150);
    numOfEnemies = currentPlanet.getNumMonsters();
    
    currentPlanet.setCurrentWeather(findWeather(currentPlanet));
    
    cout<<"==========Welcome to "<<currentPlanet.getName()<<"========== \n";
    cout<<"***Planet Description***: "<<arrayOfPlanets[currentPlanetIndex].getDescription()<<"\n"<<endl;
    cout<<"Current weather: "<<currentPlanet.getCurrentWeather()<<endl;
    cout<<"NOTICE!: A cloacked merchant hands you a DL-44 blaster Alien Assualt Rifle. Do you...? \n1)Take it\n2)Replace it with a gun in your inventory\n3)Leave it\n";
    cin>>move;
    cin.clear();
    switch(move){
        case 1:
            player.pickUpItem(AlienAssualtRifle);
            break;
        case 2:
                int choice;
                cout<<"Which item would you like to replace?\n1)"<<player.getItem(0).getName()<<"\n2)"<<player.getItem(1).getName()<<"\n3)"<<player.getItem(2).getName()<<"\n4)"<<player.getItem(3).getName()<<"\n5)"<<player.getItem(4).getName()<<endl;
                cin>>choice;
                switch (choice)
                {
                    case 1:
                        player.replaceItem(0,AlienAssualtRifle);
                        break;
                    case 2:
                        player.replaceItem(1,AlienAssualtRifle);
                        break;
                    case 3:
                        player.replaceItem(2,AlienAssualtRifle);
                        break;
                    case 4:
                        player.replaceItem(3,AlienAssualtRifle);
                        break;
                    case 5:
                        player.replaceItem(4,AlienAssualtRifle);
                        break;
                    default:
                        cout<<"Incorrect Input"<<endl;
                        break;
                }
                break;
        case 3:
            cout<<"Your loss. \n";
            break;
        default:
            cout<<"It's yes or not son. \n";
            break;
    }
    
    cout<<"You arrive on "<<currentPlanetName<<" and bionic scans reveal there is...oh come on..."<<currentPlanet.getNumMonsters()<<" Space Invader soldiers within your field of view."<<endl;
    cout<<"You currently have your "<<player.getItem(player.getEquipped()).getName()<<" equipped."<<endl;
    currentEnemyHealth = currentPlanet.getCharacter(numOfEnemies).getHealth();
    while(player.getHealth() > 0 && numOfEnemies > 0)
    {
        Item equippedItem = player.getItem(player.getEquipped());
        cout<<"Do you...?\n1)Take cover and heal\n2)Shoot\n3)Take cover and change weapons"<<endl;
        cin>>move;
        cin.clear();
        switch (move)
        {
            case 1:
                //you heal yourself
                if(meds>0)
                {
                    cout<<"You apply 1 layer of sun screen."<<endl;
                    player.setHealth(player.getHealth()+50);
                    meds--;
                }
                else
                {
                    cout<<"You are out of sun  screen."<<endl;
                }
                break;
            case 2:
                //Player attacks
                currentEnemyHealth = currentPlanet.getCharacter(numOfEnemies).getHealth();
                if(hit(currentPlanet.getCurrentWeather(),player.getHitChance()))
                {
                    //applies damage
                    Character attacked = currentPlanet.getCharacter(numOfEnemies);
                    attacked.setHealth(currentEnemyHealth-equippedItem.getDamage());
                    currentEnemyHealth=currentEnemyHealth-equippedItem.getDamage();
                    currentPlanet.addCharacterAt(attacked,numOfEnemies);
                   
                   //Displays What just happened
                    cout<<"The "<<currentPlanet.getCharacter(numOfEnemies).getDescription()<<" took "<<equippedItem.getDamage()<<" damage."<<endl;
                    
                    //if enemy is dead    
                    if(currentEnemyHealth <= 0)
                    {
                        attacked.setHealth(0);
                        currentEnemyHealth=0;
                        numOfEnemies--;
                        cout<<"This enemy was eliminated! There are: "<<numOfEnemies<<" attacking!"<<endl;
                    }
                }
                else
                {
                    cout<<"You missed your shot."<<endl;
                }
                
                //Enemy attacks
                if(hit(currentPlanet.getCurrentWeather(),SI4.getHitChance()))
                {
                    player.setHealth(player.getHealth()-snw.getDamage());
                    cout<<"You took "<<snw.getDamage()<<" damage."<<endl;
                }
                else
                {
                    cout<<"The soldier missed his shot."<<endl;
                }
                
                break;
            case 3:
                int choice;
                cout<<"Which weapon do you want to equip?\n1)"<<player.getItem(0).getName()<<"\n2)"<<player.getItem(1).getName()<<"\n3)"<<player.getItem(2).getName()<<"\n4)"<<player.getItem(3).getName()<<"\n5)"<<player.getItem(4).getName()<<endl;
                cin>>choice;
                cin.clear();
                switch (choice)
                {
                    case 1:
                        player.setEquipped(0);
                        break;
                    case 2:
                        player.setEquipped(1);
                        break;
                    case 3:
                        player.setEquipped(2);
                        break;
                    case 4:
                        player.setEquipped(3);
                        break;
                    case 5:
                        player.setEquipped(4);
                        break;
                    default:
                        cout<<"Incorrect Input"<<endl;
                        break;
                }
                break;
            default:
                cout<<"Incorrect Input"<<endl;
                break;
        }
        cout<<"===STATUS REPORT=== \nYour health: "<<player.getHealth()<<"\nEnemy health: "<<currentEnemyHealth<<endl;
    }
    
    //Did you die?
    if(player.getHealth()<=0)
    {
        cout<<"Game Over."<<endl;
        return 0;
    }
    
    //Did you defeat all the enemies?
    if(numOfEnemies == 0)
        cout<<"### You killed all enemies. ###"<<endl;
    
    //Next scene
    while(move!=4)
    {
        cout<<"Do you...?\n1)Explore\n2)Pick up weapon\n3)Replace weapon\n4)Leave planet"<<endl;
        cin>>move;
        cin.clear();
        switch (move)
        {
            case 1:
                cout<<"You find the "<<snw.getName()<<endl;
                break;
            case 2:
                player.pickUpItem(snw);
                break;
            case 3:
                int choice;
                cout<<"Which item would you like to replace?\n1)"<<player.getItem(0).getName()<<"\n2)"<<player.getItem(1).getName()<<"\n3)"<<player.getItem(2).getName()<<"\n4)"<<player.getItem(3).getName()<<"\n5)"<<player.getItem(4).getName()<<endl;
                cin>>choice;
                switch (choice)
                {
                    case 1:
                        player.replaceItem(0,snw);
                        break;
                    case 2:
                        player.replaceItem(1,snw);
                        break;
                    case 3:
                        player.replaceItem(2,snw);
                        break;
                    case 4:
                        player.replaceItem(3,snw);
                        break;
                    case 5:
                        player.replaceItem(4,snw);
                        break;
                    default:
                        cout<<"Incorrect Input"<<endl;
                        break;
                }
                break;
            case 4:
                break;
            default:
                cout<<"Incorrect Input"<<endl;
                break;
        }
    }
    currentPlanetIndex++;
    /////////////////////////////LEVEL 5/////////////////////////////
    
    currentPlanet = arrayOfPlanets[currentPlanetIndex];
    currentPlanetName = arrayOfPlanets[currentPlanetIndex].getName();
    meds=3;
    player.setHealth(150);
    numOfEnemies = currentPlanet.getNumMonsters();
    
    currentPlanet.setCurrentWeather(findWeather(currentPlanet));
    
    cout<<"==========Welcome to "<<currentPlanet.getName()<<"========== \n";
    cout<<"***Planet Description***: "<<arrayOfPlanets[currentPlanetIndex].getDescription()<<"\n"<<endl;
    cout<<"Current weather: "<<currentPlanet.getCurrentWeather()<<endl;
    cout<<"NOTICE!: You see a Ak-47 floating in the rings of Jupiter. Do you...? \n1)Take it\n2)Replace it with a gun in your inventory\n3)Leave it\n";
    cin>>move;
    cin.clear();
    switch(move){
        case 1:
            player.pickUpItem(AK47);
            break;
        case 2:
                int choice;
                cout<<"Which item would you like to replace?\n1)"<<player.getItem(0).getName()<<"\n2)"<<player.getItem(1).getName()<<"\n3)"<<player.getItem(2).getName()<<"\n4)"<<player.getItem(3).getName()<<"\n5)"<<player.getItem(4).getName()<<endl;
                cin>>choice;
                switch (choice)
                {
                    case 1:
                        player.replaceItem(0,AK47);
                        break;
                    case 2:
                        player.replaceItem(1,AK47);
                        break;
                    case 3:
                        player.replaceItem(2,AK47);
                        break;
                    case 4:
                        player.replaceItem(3,AK47);
                        break;
                    case 5:
                        player.replaceItem(4,AK47);
                        break;
                    default:
                        cout<<"Incorrect Input"<<endl;
                        break;
                }
                break;
        case 3:
            cout<<"Your loss. \n";
            break;
        default:
            cout<<"We've been through this. \n";
            break;
    }
    
    cout<<"You arrive on "<<currentPlanetName<<" and bionic scans reveal there are "<<currentPlanet.getNumMonsters()<<" hostile Kardashians within your field of view."<<endl;
    cout<<"You currently have your "<<player.getItem(player.getEquipped()).getName()<<" equipped."<<endl;
    currentEnemyHealth = currentPlanet.getCharacter(numOfEnemies).getHealth();
    while(player.getHealth() > 0 && numOfEnemies > 0)
    {
        Item equippedItem = player.getItem(player.getEquipped());
        cout<<"Do you...?\n1)Take cover and heal\n2)Shoot\n3)Take cover and change weapons"<<endl;
        cin>>move;
        cin.clear();
        switch (move)
        {
            case 1:
                //you heal yourself
                if(meds>0)
                {
                    cout<<"You release a rap album."<<endl;
                    player.setHealth(player.getHealth()+40);
                    meds--;
                }
                else
                {
                    cout<<"You're all out of albums to drop."<<endl;
                }
                break;
            case 2:
                //Player attacks
                currentEnemyHealth = currentPlanet.getCharacter(numOfEnemies).getHealth();
                if(hit(currentPlanet.getCurrentWeather(),player.getHitChance()))
                {
                    //applies damage
                    Character attacked = currentPlanet.getCharacter(numOfEnemies);
                    attacked.setHealth(currentEnemyHealth-equippedItem.getDamage());
                    currentEnemyHealth=currentEnemyHealth-equippedItem.getDamage();
                    currentPlanet.addCharacterAt(attacked,numOfEnemies);
                   
                   //Displays What just happened
                    cout<<"The "<<currentPlanet.getCharacter(numOfEnemies).getDescription()<<" took "<<equippedItem.getDamage()<<" damage."<<endl;
                    
                    //if enemy is dead    
                    if(currentEnemyHealth <= 0)
                    {
                        attacked.setHealth(0);
                        currentEnemyHealth=0;
                        numOfEnemies--;
                        cout<<"This enemy was eliminated! There are: "<<numOfEnemies<<" attacking!"<<endl;
                    }
                }
                else
                {
                    cout<<"You missed your shot."<<endl;
                }
                
                //Enemy attacks
                if(hit(currentPlanet.getCurrentWeather(),Kardashian1.getHitChance()))
                {
                    player.setHealth(player.getHealth()-jet.getDamage());
                    cout<<"You took "<<jet.getDamage()<<" damage."<<endl;
                }
                else
                {
                    cout<<"The Kardashian jet missed you."<<endl;
                }
                
                break;
            case 3:
                int choice;
                cout<<"Which weapon do you want to equip?\n1)"<<player.getItem(0).getName()<<"\n2)"<<player.getItem(1).getName()<<"\n3)"<<player.getItem(2).getName()<<"\n4)"<<player.getItem(3).getName()<<"\n5)"<<player.getItem(4).getName()<<endl;
                cin>>choice;
                cin.clear();
                switch (choice)
                {
                    case 1:
                        player.setEquipped(0);
                        break;
                    case 2:
                        player.setEquipped(1);
                        break;
                    case 3:
                        player.setEquipped(2);
                        break;
                    case 4:
                        player.setEquipped(3);
                        break;
                    case 5:
                        player.setEquipped(4);
                        break;
                    default:
                        cout<<"Incorrect Input"<<endl;
                        break;
                }
                break;
            default:
                cout<<"Incorrect Input"<<endl;
                break;
        }
        cout<<"===STATUS REPORT=== \nYour health: "<<player.getHealth()<<"\nEnemy health: "<<currentEnemyHealth<<endl;
    }
    
    //Did you die?
    if(player.getHealth()<=0)
    {
        cout<<"Game Over."<<endl;
        return 0;
    }
    
    //Did you defeat all the enemies?
    if(numOfEnemies == 0)
        cout<<"### You killed all enemies. ###"<<endl;
    
    //Next scene
    while(move!=4)
    {
        cout<<"Do you...?\n1)Explore\n2)Pick up weapon\n3)Replace weapon\n4)Leave planet"<<endl;
        cin>>move;
        cin.clear();
        switch (move)
        {
            case 1:
                cout<<"You find the "<<jet.getName()<<endl;
                break;
            case 2:
                player.pickUpItem(jet);
                break;
            case 3:
                int choice;
                cout<<"Which item would you like to replace?\n1)"<<player.getItem(0).getName()<<"\n2)"<<player.getItem(1).getName()<<"\n3)"<<player.getItem(2).getName()<<"\n4)"<<player.getItem(3).getName()<<"\n5)"<<player.getItem(4).getName()<<endl;
                cin>>choice;
                switch (choice)
                {
                    case 1:
                        player.replaceItem(0,jet);
                        break;
                    case 2:
                        player.replaceItem(1,jet);
                        break;
                    case 3:
                        player.replaceItem(2,jet);
                        break;
                    case 4:
                        player.replaceItem(3,jet);
                        break;
                    case 5:
                        player.replaceItem(4,jet);
                        break;
                    default:
                        cout<<"Incorrect Input"<<endl;
                        break;
                }
                break;
            case 4:
                break;
            default:
                cout<<"Incorrect Input"<<endl;
                break;
        }
    }
    currentPlanetIndex++;
    /////////////////////////////LEVEL 6/////////////////////////////
    
    currentPlanet = arrayOfPlanets[currentPlanetIndex];
    currentPlanetName = arrayOfPlanets[currentPlanetIndex].getName();
    meds=3;
    player.setHealth(150);
    numOfEnemies = currentPlanet.getNumMonsters();
    
    currentPlanet.setCurrentWeather(findWeather(currentPlanet));
    
    cout<<"==========Welcome to "<<currentPlanet.getName()<<"========== \n";
    cout<<"***Planet Description***: "<<arrayOfPlanets[currentPlanetIndex].getDescription()<<"\n"<<endl;
    cout<<"Current weather: "<<currentPlanet.getCurrentWeather()<<endl;
    cout<<"NOTICE!: A Flamethrower is frozen, floating in the atmosphere of Saturn. Do you...? \n1)Take it\n2)Replace it with a gun in your inventory\n3)Leave it\n";
    cin>>move;
    cin.clear();
    switch(move){
        case 1:
            player.pickUpItem(Flamethower);
            break;
        case 2:
                int choice;
                cout<<"Which item would you like to replace?\n1)"<<player.getItem(0).getName()<<"\n2)"<<player.getItem(1).getName()<<"\n3)"<<player.getItem(2).getName()<<"\n4)"<<player.getItem(3).getName()<<"\n5)"<<player.getItem(4).getName()<<endl;
                cin>>choice;
                switch (choice)
                {
                    case 1:
                        player.replaceItem(0,Flamethower);
                        break;
                    case 2:
                        player.replaceItem(1,Flamethower);
                        break;
                    case 3:
                        player.replaceItem(2,Flamethower);
                        break;
                    case 4:
                        player.replaceItem(3,Flamethower);
                        break;
                    case 5:
                        player.replaceItem(4,Flamethower);
                        break;
                    default:
                        cout<<"Incorrect Input"<<endl;
                        break;
                }
                break;
        case 3:
            cout<<"Your loss. \n";
            break;
        default:
            cout<<"It's yes or not son. \n";
            break;
    }
    
    cout<<"You arrive on "<<currentPlanetName<<" and bionic scans reveal there is "<<currentPlanet.getNumMonsters()<<" Dolfinbats within your field of view."<<endl;
    cout<<"You currently have your "<<player.getItem(player.getEquipped()).getName()<<" equipped."<<endl;
    currentEnemyHealth = currentPlanet.getCharacter(numOfEnemies).getHealth();
    while(player.getHealth() > 0 && numOfEnemies > 0)
    {
        Item equippedItem = player.getItem(player.getEquipped());
        cout<<"Do you...?\n1)Take cover and heal\n2)Shoot\n3)Take cover and change weapons"<<endl;
        cin>>move;
        cin.clear();
        switch (move)
        {
            case 1:
                //you heal yourself
                if(meds>0)
                {
                    cout<<"You eat one dolfinbat fin."<<endl;
                    player.setHealth(player.getHealth()+40);
                    meds--;
                }
                else
                {
                    cout<<"You accidentally eat a bat wing and contract COVID-19 and lose 10 health."<<endl;
                    player.setHealth(player.getHealth()-10);
                }
                break;
            case 2:
                //Player attacks
                currentEnemyHealth = currentPlanet.getCharacter(numOfEnemies).getHealth();
                if(hit(currentPlanet.getCurrentWeather(),player.getHitChance()))
                {
                    //applies damage
                    Character attacked = currentPlanet.getCharacter(numOfEnemies);
                    attacked.setHealth(currentEnemyHealth-equippedItem.getDamage());
                    currentEnemyHealth=currentEnemyHealth-equippedItem.getDamage();
                    currentPlanet.addCharacterAt(attacked,numOfEnemies);
                   
                   //Displays What just happened
                    cout<<"The "<<currentPlanet.getCharacter(numOfEnemies).getDescription()<<" took "<<equippedItem.getDamage()<<" damage."<<endl;
                    
                    //if enemy is dead    
                    if(currentEnemyHealth <= 0)
                    {
                        attacked.setHealth(0);
                        currentEnemyHealth=0;
                        numOfEnemies--;
                        cout<<"This enemy was eliminated! There are: "<<numOfEnemies<<" attacking!"<<endl;
                    }
                }
                else
                {
                    cout<<"You missed your shot."<<endl;
                }
                
                //Enemy attacks
                if(hit(currentPlanet.getCurrentWeather(),Dolfinbat1.getHitChance()))
                {
                    player.setHealth(player.getHealth()-teeth.getDamage());
                    cout<<"The Dolfinbat bit you and you took "<<teeth.getDamage()<<" damage."<<endl;
                }
                else
                {
                    cout<<"The Dolfinbat missed your body."<<endl;
                }
                
                break;
            case 3:
                int choice;
                cout<<"Which weapon do you want to equip?\n1)"<<player.getItem(0).getName()<<"\n2)"<<player.getItem(1).getName()<<"\n3)"<<player.getItem(2).getName()<<"\n4)"<<player.getItem(3).getName()<<"\n5)"<<player.getItem(4).getName()<<endl;
                cin>>choice;
                cin.clear();
                switch (choice)
                {
                    case 1:
                        player.setEquipped(0);
                        break;
                    case 2:
                        player.setEquipped(1);
                        break;
                    case 3:
                        player.setEquipped(2);
                        break;
                    case 4:
                        player.setEquipped(3);
                        break;
                    case 5:
                        player.setEquipped(4);
                        break;
                    default:
                        cout<<"Incorrect Input"<<endl;
                        break;
                }
                break;
            default:
                cout<<"Incorrect Input"<<endl;
                break;
        }
        cout<<"===STATUS REPORT=== \nYour health: "<<player.getHealth()<<"\nEnemy health: "<<currentEnemyHealth<<endl;
    }
    
    //Did you die?
    if(player.getHealth()<=0)
    {
        cout<<"Game Over."<<endl;
        return 0;
    }
    
    //Did you defeat all the enemies?
    if(numOfEnemies == 0)
        cout<<"### You killed all enemies. ###"<<endl;
    move=0;
    //Next scene
    while(move!=2)
    {
        cout<<"Do you...?\n1)Explore\n2)Leave planet"<<endl;
        cin>>move;
        cin.clear();
        switch (move)
        {
            case 1:
                cout<<"You find nothing. You try to examine the bodies of the Dolfinbats, but without life, they quickly freeze and turn into dust."<<endl;
                break;
            case 2:
                break;
            default:
                cout<<"Incorrect Input"<<endl;
                break;
        }
    }
    currentPlanetIndex++;
    /////////////////////////////LEVEL 7/////////////////////////////
    
    currentPlanet = arrayOfPlanets[currentPlanetIndex];
    currentPlanetName = arrayOfPlanets[currentPlanetIndex].getName();
    meds=3;
    player.setHealth(150);
    numOfEnemies = currentPlanet.getNumMonsters();
    
    currentPlanet.setCurrentWeather(findWeather(currentPlanet));
    
    cout<<"==========Welcome to "<<currentPlanet.getName()<<"========== \n";
    cout<<"***Planet Description***: "<<arrayOfPlanets[currentPlanetIndex].getDescription()<<"\n"<<endl;
    cout<<"Current weather: "<<currentPlanet.getCurrentWeather()<<endl;
    cout<<"NOTICE!: You have enough change to buy a RayGun off the wall. Do you...? \n1)Take it\n2)Replace it with a gun in your inventory\n3)Leave it\n";
    cin>>move;
    cin.clear();
    switch(move){
        case 1:
            player.pickUpItem(RayGun);
            break;
        case 2:
                int choice;
                cout<<"Which item would you like to replace?\n1)"<<player.getItem(0).getName()<<"\n2)"<<player.getItem(1).getName()<<"\n3)"<<player.getItem(2).getName()<<"\n4)"<<player.getItem(3).getName()<<"\n5)"<<player.getItem(4).getName()<<endl;
                cin>>choice;
                switch (choice)
                {
                    case 1:
                        player.replaceItem(0,RayGun);
                        break;
                    case 2:
                        player.replaceItem(1,RayGun);
                        break;
                    case 3:
                        player.replaceItem(2,RayGun);
                        break;
                    case 4:
                        player.replaceItem(3,RayGun);
                        break;
                    case 5:
                        player.replaceItem(4,RayGun);
                        break;
                    default:
                        cout<<"Incorrect Input"<<endl;
                        break;
                }
                break;
        case 3:
            cout<<"Your loss. \n";
            break;
        default:
            cout<<"It's yes or not son. \n";
            break;
    }
    
    cout<<"You arrive on "<<currentPlanetName<<" and bionic scans reveal there is "<<currentPlanet.getNumMonsters()<<" Icee Bears within your field of view."<<endl;
    cout<<"You currently have your "<<player.getItem(player.getEquipped()).getName()<<" equipped."<<endl;
    currentEnemyHealth = currentPlanet.getCharacter(numOfEnemies).getHealth();
    while(player.getHealth() > 0 && numOfEnemies > 0)
    {
        Item equippedItem = player.getItem(player.getEquipped());
        cout<<"Do you...?\n1)Take cover and heal\n2)Shoot\n3)Take cover and change weapons"<<endl;
        cin>>move;
        cin.clear();
        switch (move)
        {
            case 1:
                //you heal yourself
                if(meds>0)
                {
                    cout<<"You down a 7/11 Slurpee."<<endl;
                    player.setHealth(player.getHealth()+40);
                    meds--;
                }
                else
                {
                    cout<<"You get brainfreeze."<<endl;
                    player.setHealth(player.getHealth()-1);
                }
                break;
            case 2:
                //Player attacks
                currentEnemyHealth = currentPlanet.getCharacter(numOfEnemies).getHealth();
                if(hit(currentPlanet.getCurrentWeather(),player.getHitChance()))
                {
                    //applies damage
                    Character attacked = currentPlanet.getCharacter(numOfEnemies);
                    attacked.setHealth(currentEnemyHealth-equippedItem.getDamage());
                    currentEnemyHealth=currentEnemyHealth-equippedItem.getDamage();
                    currentPlanet.addCharacterAt(attacked,numOfEnemies);
                   
                   //Displays What just happened
                    cout<<"The "<<currentPlanet.getCharacter(numOfEnemies).getDescription()<<" took "<<equippedItem.getDamage()<<" damage."<<endl;
                    
                    //if enemy is dead    
                    if(currentEnemyHealth <= 0)
                    {
                        attacked.setHealth(0);
                        currentEnemyHealth=0;
                        numOfEnemies--;
                        cout<<"This enemy was eliminated! There are: "<<numOfEnemies<<" attacking!"<<endl;
                    }
                }
                else
                {
                    cout<<"You missed your shot."<<endl;
                }
                
                //Enemy attacks
                if(hit(currentPlanet.getCurrentWeather(),Icee1.getHitChance()))
                {
                    player.setHealth(player.getHealth()-paws.getDamage());
                    cout<<"You took "<<paws.getDamage()<<" damage."<<endl;
                }
                else
                {
                    cout<<"The Icee Bear missed your body."<<endl;
                }
                
                break;
            case 3:
                int choice;
                cout<<"Which weapon do you want to equip?\n1)"<<player.getItem(0).getName()<<"\n2)"<<player.getItem(1).getName()<<"\n3)"<<player.getItem(2).getName()<<"\n4)"<<player.getItem(3).getName()<<"\n5)"<<player.getItem(4).getName()<<endl;
                cin>>choice;
                cin.clear();
                switch (choice)
                {
                    case 1:
                        player.setEquipped(0);
                        break;
                    case 2:
                        player.setEquipped(1);
                        break;
                    case 3:
                        player.setEquipped(2);
                        break;
                    case 4:
                        player.setEquipped(3);
                        break;
                    case 5:
                        player.setEquipped(4);
                        break;
                    default:
                        cout<<"Incorrect Input"<<endl;
                        break;
                }
                break;
            default:
                cout<<"Incorrect Input"<<endl;
                break;
        }
        cout<<"===STATUS REPORT=== \nYour health: "<<player.getHealth()<<"\nEnemy health: "<<currentEnemyHealth<<endl;
    }
    
    //Did you die?
    if(player.getHealth()<=0)
    {
        cout<<"Game Over."<<endl;
        return 0;
    }
    
    //Did you defeat all the enemies?
    if(numOfEnemies == 0)
        cout<<"### You killed all enemies. ###"<<endl;
    
    //Next scene
    while(move!=4)
    {
        cout<<"Do you...?\n1)Explore\n2)Pick up weapon\n3)Replace weapon\n4)Leave planet"<<endl;
        cin>>move;
        cin.clear();
        switch (move)
        {
            case 1:
                cout<<"You find the "<<paws.getName()<<"."<<endl;
                break;
            case 2:
                player.pickUpItem(paws);
                break;
            case 3:
                int choice;
                cout<<"Which item would you like to replace?\n1)"<<player.getItem(0).getName()<<"\n2)"<<player.getItem(1).getName()<<"\n3)"<<player.getItem(2).getName()<<"\n4)"<<player.getItem(3).getName()<<"\n5)"<<player.getItem(4).getName()<<endl;
                cin>>choice;
                switch (choice)
                {
                    case 1:
                        player.replaceItem(0,paws);
                        break;
                    case 2:
                        player.replaceItem(1,paws);
                        break;
                    case 3:
                        player.replaceItem(2,paws);
                        break;
                    case 4:
                        player.replaceItem(3,paws);
                        break;
                    case 5:
                        player.replaceItem(4,paws);
                        break;
                    default:
                        cout<<"Incorrect Input"<<endl;
                        break;
                }
                break;
            case 4:
                break;
            default:
                cout<<"Incorrect Input"<<endl;
                break;
        }
    }
    currentPlanetIndex++;
    /////////////////////////////LEVEL 8////////////////////////////
    
    currentPlanet = arrayOfPlanets[currentPlanetIndex];
    currentPlanetName = arrayOfPlanets[currentPlanetIndex].getName();
    meds=3;
    player.setHealth(150);
    numOfEnemies = currentPlanet.getNumMonsters();
    
    currentPlanet.setCurrentWeather(findWeather(currentPlanet));
    
    cout<<"==========Welcome to "<<currentPlanet.getName()<<"========== \n";
    cout<<"***Planet Description***: "<<arrayOfPlanets[currentPlanetIndex].getDescription()<<"\n"<<endl;
    cout<<"Current weather: "<<currentPlanet.getCurrentWeather()<<endl;
    cout<<"NOTICE!: A MiniGun is discovered in the captain console of the ship. Do you...? \n1)Take it\n2)Replace it with a gun in your inventory\n3)Leave it\n";
    cin>>move;
    cin.clear();
    switch(move){
        case 1:
            player.pickUpItem(MiniGun);
            break;
        case 2:
                int choice;
                cout<<"Which item would you like to replace?\n1)"<<player.getItem(0).getName()<<"\n2)"<<player.getItem(1).getName()<<"\n3)"<<player.getItem(2).getName()<<"\n4)"<<player.getItem(3).getName()<<"\n5)"<<player.getItem(4).getName()<<endl;
                cin>>choice;
                switch (choice)
                {
                    case 1:
                        player.replaceItem(0,MiniGun);
                        break;
                    case 2:
                        player.replaceItem(1,MiniGun);
                        break;
                    case 3:
                        player.replaceItem(2,MiniGun);
                        break;
                    case 4:
                        player.replaceItem(3,MiniGun);
                        break;
                    case 5:
                        player.replaceItem(4,MiniGun);
                        break;
                    default:
                        cout<<"Incorrect Input"<<endl;
                        break;
                }
                break;
        case 3:
            cout<<"Your loss. \n";
            break;
        default:
            cout<<"It's yes or not son. \n";
            break;
    }
    
    cout<<"You arrive on "<<currentPlanetName<<" and bionic scans reveal there is "<<currentPlanet.getNumMonsters()<<" Space Inavder soldiers within your field of view."<<endl;
    cout<<"You currently have your "<<player.getItem(player.getEquipped()).getName()<<" equipped."<<endl;
    currentEnemyHealth = currentPlanet.getCharacter(numOfEnemies).getHealth();
    while(player.getHealth() > 0 && numOfEnemies > 0)
    {
        Item equippedItem = player.getItem(player.getEquipped());
        cout<<"Do you...?\n1)Take cover and heal\n2)Shoot\n3)Take cover and change weapons"<<endl;
        cin>>move;
        cin.clear();
        switch (move)
        {
            case 1:
                //you heal yourself
                if(meds>0)
                {
                    cout<<"You put on a bandage like a normal human being."<<endl;
                    player.setHealth(player.getHealth()+40);
                    meds--;
                }
                else
                {
                    cout<<"You are out of bandages."<<endl;
                }
                break;
            case 2:
                //Player attacks
                currentEnemyHealth = currentPlanet.getCharacter(numOfEnemies).getHealth();
                if(hit(currentPlanet.getCurrentWeather(),player.getHitChance()))
                {
                    //applies damage
                    Character attacked = currentPlanet.getCharacter(numOfEnemies);
                    attacked.setHealth(currentEnemyHealth-equippedItem.getDamage());
                    currentEnemyHealth=currentEnemyHealth-equippedItem.getDamage();
                    currentPlanet.addCharacterAt(attacked,numOfEnemies);
                   
                   //Displays What just happened
                    cout<<"The "<<currentPlanet.getCharacter(numOfEnemies).getDescription()<<" took "<<equippedItem.getDamage()<<" damage."<<endl;
                    
                    //if enemy is dead    
                    if(currentEnemyHealth <= 0)
                    {
                        attacked.setHealth(0);
                        currentEnemyHealth=0;
                        numOfEnemies--;
                        cout<<"This enemy was eliminated! There are: "<<numOfEnemies<<" attacking!"<<endl;
                    }
                }
                else
                {
                    cout<<"You missed your shot."<<endl;
                }
                
                //Enemy attacks
                if(hit(currentPlanet.getCurrentWeather(),SI10.getHitChance()))
                {
                    player.setHealth(player.getHealth()-wns.getDamage());
                    cout<<"You took "<<wns.getDamage()<<" damage."<<endl;
                }
                else
                {
                    cout<<"The Space Invader soldiers missed his shot."<<endl;
                }
                
                break;
            case 3:
                int choice;
                cout<<"Which weapon do you want to equip?\n1)"<<player.getItem(0).getName()<<"\n2)"<<player.getItem(1).getName()<<"\n3)"<<player.getItem(2).getName()<<"\n4)"<<player.getItem(3).getName()<<"\n5)"<<player.getItem(4).getName()<<endl;
                cin>>choice;
                cin.clear();
                switch (choice)
                {
                    case 1:
                        player.setEquipped(0);
                        break;
                    case 2:
                        player.setEquipped(1);
                        break;
                    case 3:
                        player.setEquipped(2);
                        break;
                    case 4:
                        player.setEquipped(3);
                        break;
                    case 5:
                        player.setEquipped(4);
                        break;
                    default:
                        cout<<"Incorrect Input"<<endl;
                        break;
                }
                break;
            default:
                cout<<"Incorrect Input"<<endl;
                break;
        }
        cout<<"===STATUS REPORT=== \nYour health: "<<player.getHealth()<<"\nEnemy health: "<<currentEnemyHealth<<endl;
    }
    
    //Did you die?
    if(player.getHealth()<=0)
    {
        cout<<"Game Over."<<endl;
        return 0;
    }
    
    //Did you defeat all the enemies?
    if(numOfEnemies == 0)
        cout<<"### You killed all enemies. ###"<<endl;
    
    //Next scene
    while(move!=4)
    {
        cout<<"Do you...?\n1)Explore\n2)Pick up weapon\n3)Replace weapon\n4)Leave planet"<<endl;
        cin>>move;
        cin.clear();
        switch (move)
        {
            case 1:
                cout<<"You find the "<<wns.getName()<<endl;
                break;
            case 2:
                player.pickUpItem(wns);
                break;
            case 3:
                int choice;
                cout<<"Which item would you like to replace?\n1)"<<player.getItem(0).getName()<<"\n2)"<<player.getItem(1).getName()<<"\n3)"<<player.getItem(2).getName()<<"\n4)"<<player.getItem(3).getName()<<"\n5)"<<player.getItem(4).getName()<<endl;
                cin>>choice;
                switch (choice)
                {
                    case 1:
                        player.replaceItem(0,wns);
                        break;
                    case 2:
                        player.replaceItem(1,wns);
                        break;
                    case 3:
                        player.replaceItem(2,wns);
                        break;
                    case 4:
                        player.replaceItem(3,wns);
                        break;
                    case 5:
                        player.replaceItem(4,wns);
                        break;
                    default:
                        cout<<"Incorrect Input"<<endl;
                        break;
                }
                break;
            case 4:
                break;
            default:
                cout<<"Incorrect Input"<<endl;
                break;
        }
    }
    currentPlanetIndex++;
    /////////////////////////////LEVEL 9/////////////////////////////
    
    currentPlanet = arrayOfPlanets[currentPlanetIndex];
    currentPlanetName = arrayOfPlanets[currentPlanetIndex].getName();
    meds=5;
    player.setHealth(150);
    numOfEnemies = currentPlanet.getNumMonsters();
    
    currentPlanet.setCurrentWeather(findWeather(currentPlanet));
    
    cout<<"==========Welcome to "<<currentPlanet.getName()<<"========== \n";
    cout<<"***Planet Description***: "<<arrayOfPlanets[currentPlanetIndex].getDescription()<<"\n"<<endl;
    cout<<"Current weather: "<<currentPlanet.getCurrentWeather()<<endl;
    cout<<"NOTICE!: Rich the Man appears on Pluto. He says..."<<endl;
    continueGame();
    cout<<"I knew where you journey would end."<<endl;
    continueGame();
    cout<<"And I knew I wasn't gonna let some else finish my work without me."<<endl;
    continueGame();
    cout<<"Take this AH-64 Apache Helicopter. You're gonna need it."<<endl;
    continueGame();
    cout<<"Do you...? \n1)Take it\n2)Replace it with a gun in your inventory\n3)Leave it\n";
    cin>>move;
    cin.clear();
    switch(move){
        case 1:
            player.pickUpItem(Helicopter);
            break;
        case 2:
                int choice;
                cout<<"Which item would you like to replace?\n1)"<<player.getItem(0).getName()<<"\n2)"<<player.getItem(1).getName()<<"\n3)"<<player.getItem(2).getName()<<"\n4)"<<player.getItem(3).getName()<<"\n5)"<<player.getItem(4).getName()<<endl;
                cin>>choice;
                switch (choice)
                {
                    case 1:
                        player.replaceItem(0,Helicopter);
                        break;
                    case 2:
                        player.replaceItem(1,Helicopter);
                        break;
                    case 3:
                        player.replaceItem(2,Helicopter);
                        break;
                    case 4:
                        player.replaceItem(3,Helicopter);
                        break;
                    case 5:
                        player.replaceItem(4,Helicopter);
                        break;
                    default:
                        cout<<"Incorrect Input"<<endl;
                        break;
                }
                break;
        case 3:
            cout<<"Your loss. \n";
            break;
        default:
            cout<<"It's yes or not son. \n";
            break;
    }
    
    cout<<"You arrive on "<<currentPlanetName<<" and bionic scans reveal there is only one life form present......"<<endl;
    continueGame();
    cout<<"In the distance you see a black shadow and it screams..\"AP, MUELLER MY ROLLIE\". *BabyPluto plays in the background.*"<<endl;
    string line2;
    fstream lil;
    lil.open("lilUzi.txt");
    while(getline(lil,line2))
    {
        cout<<line2<<endl;
    }
    cout<<"Rich the Man:\"IT'S LIL UZIIIIIIII\""<<endl;
    
    continueGame();
    cout<<"You currently have your "<<player.getItem(player.getEquipped()).getName()<<" equipped"<<endl;
    currentEnemyHealth = currentPlanet.getCharacter(numOfEnemies).getHealth();
    while(player.getHealth() > 0 && numOfEnemies > 0)
    {
        Item equippedItem = player.getItem(player.getEquipped());
        cout<<"Do you...?\n1)Take cover and heal\n2)Shoot\n3)Take cover and change weapons"<<endl;
        cin>>move;
        cin.clear();
        switch (move)
        {
            case 1:
                //you heal yourself
                if(meds>0)
                {
                    cout<<"You play a Playboi snippet."<<endl;
                    player.setHealth(player.getHealth()+40);
                    meds--;
                }
                else
                {
                    cout<<"You are out of Playboi snippets."<<endl;
                }
                break;
            case 2:
                //Player attacks
                currentEnemyHealth = currentPlanet.getCharacter(numOfEnemies).getHealth();
                if(hit(currentPlanet.getCurrentWeather(),player.getHitChance()))
                {
                    //applies damage
                    Character attacked = currentPlanet.getCharacter(numOfEnemies);
                    attacked.setHealth(currentEnemyHealth-equippedItem.getDamage());
                    currentEnemyHealth=currentEnemyHealth-equippedItem.getDamage();
                    currentPlanet.addCharacterAt(attacked,numOfEnemies);
                   
                   //Displays What just happened
                    cout<<"The "<<currentPlanet.getCharacter(numOfEnemies).getDescription()<<" took "<<equippedItem.getDamage()<<" damage. He slowly shrinks."<<endl;
                    
                    //if enemy is dead    
                    if(currentEnemyHealth <= 0)
                    {
                        attacked.setHealth(0);
                        currentEnemyHealth=0;
                        numOfEnemies--;
                        cout<<"Lil Uzi was defeated. He now stands at 5'4\""<<endl;
                    }
                }
                else
                {
                    cout<<"The rocket deflects off Lil Uzi's chains."<<endl;
                }
                
                //Enemy attacks
                if(hit(currentPlanet.getCurrentWeather(),Uzi.getHitChance()))
                {
                    player.setHealth(player.getHealth()-bigUzi.getDamage());
                    cout<<"You took "<<bigUzi.getDamage()<<" damage."<<endl;
                }
                else
                {
                    cout<<"Lil Uzi missed his shot."<<endl;
                }
                
                break;
            case 3:
                int choice;
                cout<<"Which weapon do you want to equip?\n1)"<<player.getItem(0).getName()<<"\n2)"<<player.getItem(1).getName()<<"\n3)"<<player.getItem(2).getName()<<"\n4)"<<player.getItem(3).getName()<<"\n5)"<<player.getItem(4).getName()<<endl;
                cin>>choice;
                cin.clear();
                switch (choice)
                {
                    case 1:
                        player.setEquipped(0);
                        break;
                    case 2:
                        player.setEquipped(1);
                        break;
                    case 3:
                        player.setEquipped(2);
                        break;
                    case 4:
                        player.setEquipped(3);
                        break;
                    case 5:
                        player.setEquipped(4);
                        break;
                    default:
                        cout<<"Incorrect Input"<<endl;
                        break;
                }
                break;
            default:
                cout<<"Incorrect Input"<<endl;
                break;
        }
        cout<<"===STATUS REPORT=== \nYour health: "<<player.getHealth()<<"\nEnemy health: "<<currentEnemyHealth<<endl;
    }
    
    //Did you die?
    if(player.getHealth()<=0)
    {
        cout<<"Game Over."<<endl;
        return 0;
    }
    
    //Did you defeat all the enemies?
    if(numOfEnemies == 0)
        cout<<"### You killed all enemies. ###"<<endl;
    
    
    cout<<"WAIT...YOU WON???"<<endl;
    continueGame();
    cout<<"Lil Uzi is 5'4 now and the solar system belongs to humanity once again!"<<endl;
    continueGame();
    cout<<"*Rich the man walks up from behind to greet you.*"<<endl;
    cout<<"Rich the Man: You actually did it. Impressive. But now you have to make a choice...."<<endl;

    
    
    cout<<"Now, do you press the red button to call in the human reinforcements?\n1)Yes\n2)No"<<endl;
    cin >> move;
    if(move==1)
    {
        cout<<"You press the red button. Soon fleets of enormous ships arrive. One stops at Pluto to come and greet you. One comes to you and says..."<<endl;
        continueGame();
        cout<<"We have just woken up and were given our mission. We were told that two things could happen."<<endl;
        continueGame();
        cout<<"That you might fail your mission and we wake up at the heart of human civilization at the age of forty, or we colonize a new solar system after 21 years of sleep for the betterment of humanity."<<endl;
        continueGame();
        cout<<"I'm glad you made it."<<endl;
        cout<<"The Box by Roddy Rich plays in the background."<<endl;
    }
    else if(move==2)
    {
        cout<<"Rich the Man comes to you and says..."<<endl;
        continueGame();
        cout<<"I'm lowkey glad you didn't do that."<<endl;
        continueGame();
        cout<<"We fought for this solar system since day 1. They ran once shots started poppin off."<<endl;
        continueGame();
        cout<<"We deserve to keep it for ourselves."<<endl;
        continueGame();
        cout<<"And if the other humans come, you got our back right?"<<endl;
        cout<<"Bezerk by Eminem plays in the background."<<endl;
    }
    else
    {
        cout<<"Invalid Input"<<endl;
    }
    
    continueGame();
    cout<<"Made and produced by OreoCookie Programs (copyright 2020)\nSorbarikor Inene\nChristian Glatz"<<endl;
    cout<<"Your stats have been sorted in a text file if you wanna check them out."<<endl;
    continueGame();
    double endtime=difftime(time(0),start_s);
    playerInfo << "\n Total Kills: 32 \n Total Damage Done: 3140 \n Solar Systems reclaimed for Humanity: 1\n"<< "Total Game Time: "<<endtime<<" sec(s)"<<endl;
    playerInfo.close();
    playerInfo.open("player.txt");
    string line;
    while(getline(playerInfo,line))
    {
        cout<<line<<endl;
    }
}


