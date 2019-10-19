#include "HubWorldText.h"

void HubWorldText::process(string filename) {
	//Loading the font, seems to have issues within classes. 
	lineText.load("Gameplay.ttf", 20); 

	//This is the value that will be changed when the process function is called
	lines.loadFile(filename);
	
	lines.pushTag("lines");
	int numberOfSpeeches = lines.getNumTags("speech"); //Grabbing the amount of tags

	//Looping through the amount of tags with "speech"
	for (int i = 0; i < numberOfSpeeches; i++)
	{
		lines.pushTag("speech", i);

		/*
			In order for variety, I've decided to make three diffirent text states for the hub world.
			The idea being that the player would get diffirent results when they interact with the same object.

			Note : The parameter at the end of getValue is a placeholder
		*/
		string textState0i = lines.getValue("text1", "error text not found");
		string textState1i = lines.getValue("text2", "error text not found");
		string textState2i = lines.getValue("text3", "error text not found");

		//Pushing back the results from the strings
		textState0.push_back(textState0i);
		textState1.push_back(textState1i);
		textState2.push_back(textState2i);

		lines.popTag(); //Popping tag for speech
	}
	lines.popTag(); //Popping for lines
}

void HubWorldText::drawTextBox(int x, int y) //Placeholder to allow for the text box to appear whereever.
{
	ofSetColor(0);
	ofRect(0, ofGetHeight() * 0.65, ofGetWidth(), ofGetHeight() * 0.09); //This box is the where the enemy lines will appear!
	ofSetColor(255);
	lineText.drawString(textState0[0], ofGetWidth() * 0.1, ofGetHeight() * 0.71);
}
