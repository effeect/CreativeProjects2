#ifndef HUBWORLDTEXT_H
#define HUBWORLDTEXT_H

#include "ofMain.h"
#include "ofxXmlSettings.h"
/*
	This class is responsible for the string reading
*/
class HubWorldText {
public:
	ofTrueTypeFont lineText;

	vector <string> textState0;
	vector <string> textState1;
	vector <string> textState2;

	ofxXmlSettings lines; //Object file

	void process(string filename);

	void drawTextBox(int x, int y);
};

#endif