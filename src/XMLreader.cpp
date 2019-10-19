#include "XMLreader.h"

void XMLreader::process(string filename) {
	lines.loadFile(filename); //This is the value that needs to be changed
	lines.pushTag("lines");
	int numberOfSpeeches = lines.getNumTags("speech"); //Grabbing the amount of tags

	for (int i = 0; i < numberOfSpeeches; i++)
	{
		lines.pushTag("speech", i);
		string textResult = lines.getValue("text", "error text not found");
		int powerResult = lines.getValue("power", 0); //The power number dictates how powerful the move is both ways
		string answerResult = lines.getValue("answer", "error text not found");
		string wrongAnswer1Result = lines.getValue("wrongAnswer1", "error text not found");
		string wrongAnswer2Result = lines.getValue("wrongAnswer2", "error text not found");
		string responseRightResult = lines.getValue("responseRight", "error text not found");
		string responseWrongResult = lines.getValue("responseWrong", "error text not found");

		//Pushing back all of the results to vectors. All of them have the same ID;
		text.push_back(textResult);
		power.push_back(powerResult);
		wrongAnswer1.push_back(wrongAnswer1Result);
		wrongAnswer2.push_back(wrongAnswer2Result);
		answer.push_back(answerResult);
		responseRight.push_back(responseRightResult);
		responseWrong.push_back(responseWrongResult);

		lines.popTag(); //Popping tag for speech
	}
	lines.popTag(); //Popping for trump
}