#ifndef TRUMP_H
#define TRUMP_H

#include "ofMain.h"
#include "enemy.h"
#include <string>
#include "ofxXmlSettings.h"

/*
	Each enemy NPC is attached to the enemy class which gives our enemy some values.
*/

class trump : public enemy {
public:
	trump(float x, float y);
	void draw();
	void setup();
	float mappedEnemy;
	float mappedPlayer;
	vector <string> linesXML;
	void mousePressed();

	bool wrongResponseCheck;
	bool rightResponseCheck;

	int i = 0;

private:
	//These variables are used for the loading animaition feature
	float timeMeasure;
	int loopCheck;
};
#endif
