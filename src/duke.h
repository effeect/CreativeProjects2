#ifndef DUKE_H
#define DUKE_H

#include "ofMain.h"
#include "enemy.h"
#include <string>
#include "ofxXmlSettings.h"

class duke : public enemy {
public:
	duke(float x, float y);
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
