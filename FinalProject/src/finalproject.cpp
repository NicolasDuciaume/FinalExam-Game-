/************************************************

Nicolas Duciaume
December 15, 2017

This file contains the function descriptions for the class Power and it's subclasses
, Player, Villains and it's subclasses, StarLabs and it's subclasses

Power is used to save data on the user's powers
Player saves data on the player
Villains saves data on the villains in the game
StarLabs saves data on the rooms to visit.
*************************************************/


#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <ctime>
#include <algorithm>
#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "finalproject.h"


#define INITIAL_ENERGY 100
#define INITIAL_DAMAGE 10
#define INVISIBILTY  1
#define SPEED 		 2
#define LAUGHTER 	 3
#define WATER 		 4

using namespace cv;
using namespace std;



void Power::setName(string newName)
{
name = newName;
} // sets the power name

string Power::getName()
{
return name;
} // gets the power name

int Power::getStrength()
{
return strength;
} // gets the powers strength

void Power::setStrength(int newStrength)
{
strength = newStrength;
} // sets the powers strength

Power::Power()
{
name = "UNKNOWN";
strength = INITIAL_DAMAGE;
} // default constructor of power



int Invisibility::getDamage()
{
int dam = Power::getDamage();

if((rand() % 10) == 0)
{
dam = Power::getDamage() * 2;
cout << "Invisibility inflicts "<< dam << " additional damage points" << endl;
}
return dam;
} // virtual function get damage for invisibility which has a 10% chance of doubling the normal amount of damage



int Speed::getDamage()
{
int dam = (Power::getDamage() + Power::getDamage());
cout << "Speed inflicts "<< dam << " additional damage points" << endl;
return dam;
} // virtual function get damage for speed which always allow the player to attack twice



int Laughter::getDamage()
{
int dam = Power::getDamage();

if((rand() % 20) == 0)
{
int y = 50;
dam = Power::getDamage() + y;
cout << "Laughter inflicts "<< y << " additional damage points" << endl;
}
return dam;
} // virtual function get damage for laughter which has a 5% chance to add an additional 50 damage points



int Water::getDamage()
{
int dam = Power::getDamage();

if((rand() % 2) == 0)
{
int wat = 5;
dam = Power::getDamage() + wat;
cout << "Water inflicts "<< wat << " additional damage points" << endl;
}
return dam;
}// virtual function get damage for water which has a 50% chance to inflict 5 additional damage points


Player::Player()
{
energy = INITIAL_ENERGY;
items.push_back("Key");
name = "UNKNOWN";
setPlay(imread("player.jpg"));
}// default constructor for player

void Player::setName(string t)
{
name = t;
}// sets player name

string Player::getName()
{
return name;
}// gets player's name

int Player::getEnergy()
{
return energy;
}// gets player's energy

void Player::setEnergy(int p)
{
energy = p;
} //sets player's energy

int Player::getDamage()
{
return (power->getDamage());
} // virtual function which gets the default get damage function of power

void Player::setPower(Power* pp)
{
power = pp;
} //sets the player's power

Power* Player::getPower()
{
return power;
}// gets the player's power

void Player::selectPower(int o)
{
switch(o){
	case INVISIBILTY:
		setPower(new Invisibility);
		break;
	case Speed:
		setPower(new Speed);
		break;
	case LAUGHTER:
		setPower(new Laughter);
		break;
	case WATER:
		setPower(new Water);
		break;
	default:
		break;
}

}// allows the user to select what power he/she wants

void Player::setItem(string i)
{
items.push_back(i);

} //gives an item to the player

vector <string> Player::getItems()
{
return items;
} // return items that the player has

bool Player::hasItem(string f)
{
bool ans = false;
if(std::find(items.begin(), items.end(), f) != items.end())
{
ans = true;
}
else
{
ans = false;
}
return ans;
} // function that checks to see if the player has a specific item

Villains::Villains()
{
energy = INITIAL_ENERGY;
strength = INITIAL_DAMAGE;
name = "UNKNOWN";
} // Villains default constructor

string Villains::getName()
{
return name;
} // gets the villain's name

void Villains::setName(string w)
{
name = w;
}// sets the villain's name

int Villains::getStrength()
{
return strength;
} //gets the villain's strength

void Villains::setStrength(int x)
{
strength = x;
} // sets the villain's strength

int Villains::getEnergy()
{
return energy;
} // gets the villains energy

void Villains::setEnergy(int y)
{
energy = y;
} // sets the villains energy



int Kadabra::getDamage()
{
int dam = Villains::getDamage();

if((rand() % 10) == 0)
{
dam = 30;
cout << "Kadabra attack inflicts "<< dam << " additional damage points" << endl;
}
return dam;
} // virtual get damage function for kadabra which has a 10% chances of inflicting 30 damage points



int Grodd::getDamage()
{
int dam = 0;
int damage = Villains::getDamage();

if((rand() % 20) == 0)
{
dam = damage*2;
cout << "Grodd attack inflicts "<< dam << " additional damage points" << endl;
}
return dam + damage;
}// virtual get damage function for grodd which has a 5% chance to triple the normal amount of damage


int Devo::getDamage()
{
int dam = 0;
int damage = Villains::getDamage();

if((rand() % 10) == 0)
{
dam = ((rand() % getStrength()) +1);
cout << "Devo attack inflicts "<< dam << " additional damage points" << endl;
}
return dam + damage;
}// virtual get damage function for devo which has a 10% chance of doubling the normal amount of damage



int Reverse_Flash::getDamage()
{
int dam = 0;
int damage = Villains::getDamage();

if((rand() % 20) == 0)
{
dam = 2*((rand() % getStrength()) +1);
cout << "Reverse-Flash attack inflicts "<< dam << " additional damage points" << endl;
}
return dam + damage;
}// virtual get damage function for reverse flash which has a 5% chance of letting him attack 3 times.


void StarLabs::setVillains(Villains* boop)
{
villains = boop;
} // sets a villain pointer

Villains* StarLabs::getVillains()
{
return villains;
} // return a villain pointer

void StarLabs::setItem(string gg)
{
item = gg;
} // sets the items you receive

string StarLabs::getItem()
{
return item;
} // gets the items you receive

void StarLabs::setName(string damn)
{
name = damn;
} // sets the name of the villain in that room

string StarLabs::getName()
{
return name;
} // gets the name of the villain in the room

void StarLabs::setRequiredItem(string yolo)
{
requiredItem = yolo;
} // sets required item to enter x room

string StarLabs::getRequiredItem()
{
return requiredItem;
} // returns required item to enter x room

Laboratory::Laboratory()
{
setVillains(new Devo);
setName("Devo");
setNeedItm(imread("item1.jpg"));
setRequiredItem("Key");
setItem("Password");
setItm(imread("item2.jpg"));
} // default constructor for laboratory

TestingChamber::TestingChamber()
{
setVillains(new Kadabra);
setName("Kadabra");
setNeedItm(imread("item2.jpg"));
setRequiredItem("Password");
setItem("ID");
setItm(imread("item3.jpg"));
}// default constructor for the testing chamber

Prison::Prison()
{
setVillains(new Grodd);
setName("Grodd");
setNeedItm(imread("item3.jpg"));
setRequiredItem("ID");
setItem("Switch");
setItm(imread("item4.jpg"));
}// default constructor for the prison

Collider::Collider()
{
setVillains(new Reverse_Flash);
setName("Reverse-Flash");
setNeedItm(imread("item4.jpg"));
setRequiredItem("Switch");
setItem("PowerRing");
setItm(imread("item5.jpg"));
} // default constructor for the collider.
