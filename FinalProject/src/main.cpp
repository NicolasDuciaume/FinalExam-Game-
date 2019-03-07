/************************************************

Nicolas Duciaume
December 15, 2017

This file contains the main program. It holds the game that will be played by the users.

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

using namespace cv;
using namespace std;

int main()
{
Player p; // Declaring a player object

StarLabs* room = new StarLabs; // creating StarLabs pointer

Laboratory one;
TestingChamber two;
Prison three;
Collider four;
//creating object for all rooms

string uName;

cout << "What is your name?" << endl;
cin >> uName;
p.setName(uName);
//asking for the users name and setting the players name to the name inputted

Mat pp = p.getPlay();
string im = "Player";
namedWindow( im, CV_WINDOW_AUTOSIZE );
putText(pp, uName, Point(50,300),FONT_HERSHEY_SIMPLEX, 0.8,Scalar(0,0,255), 3, 8 , false);
  imshow( im, pp );
  waitKey( 2000 );

destroyWindow(im);
// gets the image for the player, adds the user inputed name onto the picture and displays it for a short time

int Wpower = 0;

cout <<"Choose power:" << endl << "Enter 1 for Invisibility" << endl <<"Enter 2 for Speed" << endl << "Enter 3 for Laughter" << endl << "Enter 4 for Water" << endl;

while((Wpower < 1) || (Wpower > 4))
{
cin >> Wpower;
}
// asks the user to choose a power and makes sure that the what he picked is one of the correct number or asks him again

p.selectPower(Wpower); // gives the power select by the user to the player object

cout << "The object of the game is to search from room to room to find items that will allow you to go into other rooms until you reach the final room which you will beat the game and receive the PowerRing!" << endl;

cout << "Let's Begin" << endl << endl;
// explains the game to the polayer
int visited = 0; //variable that will be used later to make sure the player does not go back in a room he already visited

while(p.hasItem("PowerRing") == false) //while loop that doesn't end until the user finds the treasure
{
if(visited == 0)
{
cout << "Which Room do you wish to visit" << endl << "1.The Laboratory " << endl << "2.The Testing Chamber" << endl << "3.The Prison" << endl << "4.The Collider" << endl;
}
else
{
cout << "1.The Laboratory " << endl << "2.The Testing Chamber" << endl << "3.The Prison" << endl << "4.The Collider" << endl;
}
// if/else statement which changes the text depending if you have already visited a room or not

int visit = 0;

while((visit < 1) || (visit > 4))
{
cin >> visit;
}
// takes in the value of the room the player wants to visit and makes sure that it is within range

switch(visit)
{
	case 1:
			room = &one;
			break;
	case 2:
			room = &two;
			break;
	case 3:
			room = &three;
			break;
	case 4:
			room = &four;
			break;
	default:
			break;
} //allocates room objects to the pointer room which the player decided to visit

Mat RI = room->getNeedItm(); // gets the image of the required object to get in the room selected by the user

string itm = room->getRequiredItem(); //  // gets the name of the object required to get in the room

string RR = "Required";
string req = "Required Item to enter!";

namedWindow( RR, CV_WINDOW_AUTOSIZE );
putText(RI, req, Point(50,50),FONT_HERSHEY_SIMPLEX, 0.8,Scalar(0,0,255), 3, 8 , false);

putText(RI, itm, Point(50,100),FONT_HERSHEY_SIMPLEX, 0.8,Scalar(0,0,255), 3, 8 , false);

  imshow( RR, RI );
  waitKey( 2000 );

destroyWindow(RR);
// Displays the required object and its name for a short time then closes the image

if((p.hasItem(itm) == true) && (visit > visited)) // makes sure that the player has the required item and that he did not visit this room yet
{
cout << "You have succefully entered the room" << endl;
cout << "Here you find: " << room->getName() << endl;
int en; // store the previous energy of the Villain to be able to substract the damage
int ene;// store the previous energy of the player to be able to substract the damage
visited++; // puts visited up by one so that the player cannot go back into the room
Villains* tmp = room->getVillains(); //gets the villain allocated to this room
Mat mons = tmp->getTmp(); // gets the image of that villain
string yolo = "Monster";

moveWindow(yolo, 200, 600);
moveWindow(im, 200, 200); // moves both the player and villains picture so that they do not overlap

namedWindow( yolo, CV_WINDOW_AUTOSIZE );
putText(mons, room->getName(), Point(50,300),FONT_HERSHEY_SIMPLEX, 0.8,Scalar(0,0,255), 3, 8 , false);
moveWindow(yolo, 200, 600);
  imshow( yolo, mons );

Mat og = pp; // this is a saved copy of the original picture of the player before it starts to shrink down

namedWindow( im, CV_WINDOW_AUTOSIZE );
putText(pp, uName, Point(50,300),FONT_HERSHEY_SIMPLEX, 0.8,Scalar(0,0,255), 3, 8 , false);
	moveWindow(im, 200, 200);
  imshow( im, pp );
//these two displays the images of the player and the monster with their names on the pictures

while((p.getEnergy() > 0) && (tmp->getEnergy() > 0)) // battle begins and continues until someone looses all his energy
{
waitKey( 2000 ); //waits so the battle does not go by to quickly
destroyWindow(yolo);
destroyWindow(im);
imshow( yolo, mons );
imshow( im, pp );
// closes the picture to open them back up yet smaller because of damage over and over
en = tmp->getEnergy();
tmp->setEnergy(en - p.getDamage());
ene = p.getEnergy();
p.setEnergy(ene - tmp->getDamage());
//enflict the damage to the player and the villain
en = tmp->getEnergy() * 3;
ene = p.getEnergy() * 3;
//uses a function to give bigger sizes/ratio to the shrunken down images

if(en > 0 && ene > 0)// makes sure that the code does not shrink bellow or equal to zero, which will give an error
{
resize(mons,mons, cvSize(en,en));
resize(pp,pp, cvSize(ene,ene));
//shrinks the images of the player and the monster depending on their amount of health left
}

moveWindow(yolo, 200, 600);
moveWindow(im, 200, 200);
imshow( yolo, mons );
imshow( im, pp );
//displays the shrunken down versions of the player and monster

}
	if(p.getEnergy() <= 0) // sees if the player lost
	{
	cout << "You died game Over" << endl;
	destroyWindow(yolo);
	destroyWindow(im);
	return 0;
  //closes both images and finishes the game
	}
	else if(tmp->getEnergy() <= 0)
	{
	pp = og; //returns the picture of the player to the original saved earlier
	destroyWindow(yolo);
	destroyWindow(im);
	cout << "You Won!" << endl;
	string io = room->getItem(); // gets the name of the item you get for winning this room
	cout << "You have received: " << io << endl;
	p.setItem(io);
	p.setEnergy(INITIAL_ENERGY);
  //set the item from that room to the player and puts back his energy to 100

	Mat I = room->getItm();

	string RO = "Received";
	string rec = "You received";

	namedWindow( RO, CV_WINDOW_AUTOSIZE );
	putText(I, rec, Point(50,50),FONT_HERSHEY_SIMPLEX, 0.8,Scalar(0,0,255), 3, 8 , false);

	putText(I, io, Point(50,100),FONT_HERSHEY_SIMPLEX, 0.8,Scalar(0,0,255), 3, 8 , false);

  	imshow( RO, I );
  	waitKey( 2000 );

	destroyWindow(RO);
  //gets the image of the item you received, and prints out you received , and its name on the image for a short time before closing it
	}
}
else if((p.hasItem(itm) == true) && (visit <= visited)) // see that the player has already been in this room and asks them to pick again
{
cout << "You have already been here, Pick again" << endl;
}
else // sees that the player does not have the require object
{
cout << "You do not have the required object, Pick again" << endl;

}
continue;


}
cout << "You won the game!!" << endl; //you won the game message.

return 0;
}
