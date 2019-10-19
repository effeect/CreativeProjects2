#ifndef XMLREADER_H
#define XMLREADER_H

#include "ofMain.h"
#include "ofxXmlSettings.h"
/*
	This class is responsible for the string reading, we've transitioned to the
*/
class XMLreader {
public:
	vector <string> text;
	vector <int> power; //Values are
	vector <string> wrongAnswer1;
	vector <string> wrongAnswer2;
	vector <string> answer;
	vector <string> responseRight;
	vector <string> responseWrong;

	ofxXmlSettings lines; //Object file

	void process(string filename);
};

#endif