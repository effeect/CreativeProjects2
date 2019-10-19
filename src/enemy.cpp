#include "enemy.h"

enemy::enemy(float hp, float Level, float var3, float var4, float var5)
{
	//These are two statistics we will be using with our program
	health = hp;
	skillLevel = Level;

	//Loading Text Stuff
	lineText.load("Gameplay.ttf", 20);
	healthText.load("ARCADECLASSIC.TTF", 20);
}


void enemy::imageLoad(string filename)
{
	enemyIcon.load(filename);
}

void enemy::imageDraw(float x, float y)
{
	enemyIcon.draw(x, y); //Shows an image at the centre top of the screen
}

enemy::~enemy()
{
}