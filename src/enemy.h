/*
	This is the enemy class, this acts as a global variable.
	Every enemy type will use this class as a stepping stone for
	all of the other NPCS
*/

#ifndef ENEMY_H
#define ENEMY_H

//Files required for this class to be operational
#include "ofMain.h"
#include "XMLreader.h"
#include "playerStats.h"

class enemy
{
public:
	//Constructor
	enemy(float hp, float Level, float var3, float var4, float var5); //These are the global values of the enemy

	//Image related functions
	ofImage enemyIcon;
	ofImage backgroundImage;
	
	//Must be run in setup
	void imageLoad(string filename); 

	//Must be run in draw
	void imageDraw(float x, float y);

	playerStats playerValues; //Player health, gets reset for every battle;
	~enemy();
protected: //Variables that can only be accessed with inhertiance

	//Variables for the moving object
	float xPos;
	float yPos;

	//Values of the enemy
	float skillLevel;
	float health;

	vector <int> heightValues; //This is to help out with randomising values
	ofTrueTypeFont lineText;
	ofTrueTypeFont healthText;

	//LineReader Object
	XMLreader XMLlines;
	int id; 
};
#endif
