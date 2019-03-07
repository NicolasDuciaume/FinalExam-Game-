/************************************************

Nicolas Duciaume
December 15, 2017

This file contains class Power and it's subclasses
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

using namespace cv;
using namespace std;

#define INITIAL_ENERGY 100
#define INITIAL_DAMAGE 10
#define INVISIBILTY  1
#define SPEED 		 2
#define LAUGHTER 	 3
#define WATER 		 4



#ifndef FINALPROJECT_H
#define FINALPROJECT_H

class Power //class declaration for class Power
{
private:
	string name;
	int strength; // how much damage we can inflict
public:
	Power();
	virtual ~Power(){}
	void setName(string newName);
	string getName();
	int getStrength();
	void setStrength(int newStrength);
	virtual int getDamage() {return (rand() % getStrength() + 1);} // Returns amount of base damage inflicted in one round of combat
};

class Invisibility : public Power //class declaration for Invisibility, derived class of Power
{
public:
	Invisibility(){}
	int getDamage();  // Returns amount of damage inflicted in one round of combat
};

class Speed : public Power //class declaration for Speed, derived class of Power
{
public:
	Speed(){}
	int getDamage();  // Returns amount of damage inflicted in one round of combat
};

class Laughter : public Power //class declaration for Laughter, derived class of Power
{
public:
	Laughter(){}
	int getDamage();  // Returns amount of damage inflicted in one round of combat
};


class Water : public Power //class declaration for Water, derived class of Power
{
public:
	Water(){}
	int getDamage();  // Returns amount of damage inflicted in one round of combat
};

class Player // class declaration for class Player
{
private:
	string name;
	Power* power;
	vector <string> items;
	int energy; // How much damage we can sustain
	Mat play;

public:
	Player();
	~Player() {delete power;}
	void setName(string t);
	string getName();
	int getEnergy();
	void setEnergy(int p);
	int getDamage();  // Returns amount of damage inflicted in one round of combat
	void setPower(Power* pp);
	Power* getPower();
	void selectPower(int o);
	void setItem(string i);
	vector <string> getItems();
	bool hasItem(string f);
	void setPlay(Mat p) {play = p; }
	Mat getPlay() {return play;}
};


class Villains // class declaration for class Villains
{
protected:
	int strength; // how much damage we can inflict
	int energy; // How much damage we can sustain
	string name;
	Mat tmp;
public:
	Villains();
	virtual ~Villains() {} // default destructor
	string getName();
	void setName(string w);
	int getStrength();
	void setStrength(int x);
	int getEnergy();
	void setEnergy(int y);
	virtual int getDamage() {return (rand() % getStrength() + 1);}  // Returns amount of damage this creature inflicts in one round of combat
	void setTmp(Mat mons) {tmp = mons; }
	Mat getTmp() {return tmp;}
};

class Kadabra : public Villains //class declaration for Kadabra, derived class of Villains
{
public:
	Kadabra() {setTmp(imread("kadabra.jpg"));} // default constructor
	int getDamage();  // Returns amount of damage this creature inflicts in one round of combat
};

class Grodd : public Villains //class declaration for Grodd, derived class of Villains
{
public:
	Grodd() {setTmp(imread("grodd.jpg"));} // default constructor
	int getDamage();  // Returns amount of damage this creature inflicts in one round of combat
};

class Devo : public Villains  //class declaration for Devo, derived class of Villains
{
public:
	Devo() {setTmp(imread("devo.jpg"));} // default constructor
	int getDamage();  // Returns amount of damage this creature inflicts in one round of combat
};

class Reverse_Flash : public Villains //class declaration for Reverse_Flash, derived class of Villains
{
public:
	Reverse_Flash() {setTmp(imread("reverse.jpg"));} // default constructor
	int getDamage();  // Returns amount of damage this creature inflicts in one round of combat
};

class StarLabs // class declaration for class StarLabs
{
private:
	Villains* villains;
	string item;
	string name;
	string requiredItem;
	Mat itm;
	Mat needItm;
public:
	StarLabs(){}
	~StarLabs() {delete villains;}
	void setVillains(Villains* boop);
	Villains* getVillains();
	void setItem(string gg);
	string getItem();
	void setName(string damn);
	string getName();
	void setRequiredItem(string yolo);
	string getRequiredItem();
	void setItm(Mat u) {itm = u; }
	Mat getItm() {return itm;}
	void setNeedItm(Mat y) {needItm = y; }
	Mat getNeedItm() {return needItm;}
};


class Laboratory : public StarLabs //class declaration for Laboratory, derived class of StarLabs
{
public:
	Laboratory();
};

class TestingChamber : public StarLabs //class declaration for TestingChamber, derived class of StarLabs
{
public:
	TestingChamber();
};

class Prison : public StarLabs //class declaration for Prison, derived class of StarLabs
{
public:
	Prison();
};

class Collider : public StarLabs //class declaration for Collider, derived class of StarLabs
{
public:
	Collider();
};


#endif
