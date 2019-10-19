#include "may.h"
#include "enemy.h"
#include "ofMain.h"

may::may(float x, float y) : enemy(4, 100, 0, 0, 0) { //The values of the enemy
	xPos = x;
	yPos = y;
}

void may::setup() {
	XMLlines.process("may.xml"); //Reading the XML file found in the data folder

	heightValues.push_back(ofGetHeight() * 0.82);
	heightValues.push_back(ofGetHeight() * 0.90);
	heightValues.push_back(ofGetHeight() * 0.98);
	/*
		This randomises the order, this makes it so the correct answer
		isn't in the same position every time
	*/
	std::random_shuffle(heightValues.begin(), heightValues.end());

	/* Uncomment this to see the values (Not to be modified)

		std::cout << heightValues[0] << std::endl;
		std::cout << heightValues[1] << std::endl;
		std::cout << heightValues[2] << std::endl;

	*/
	wrongResponseCheck = false;
	rightResponseCheck = false;
}
void may::draw() {
	//This variable simply handles the method to make the text loading effect
	timeMeasure += ofGetFrameRate() * 2; //Default;

	//Health Bar Calculation
	mappedEnemy = ofMap(health, 0, 3, 0, ofGetWidth() - 70);
	mappedPlayer = ofMap(playerValues.health, 0, 5, 0, ofGetWidth() * 0.19);

	//DEBUG Stuff
// 	ofDrawBitmapString("Health : " + ofToString(health), 10, 10);
// 	ofDrawBitmapString("Skill : " + ofToString(skillLevel), 10, 30);

	//ENEMY LINES BOX
	ofSetColor(0);
	ofRect(0, ofGetHeight() * 0.65, ofGetWidth(), ofGetHeight() * 0.09); //This box is the where the enemy lines will appear!
	ofSetColor(255);

	//The following if statements allow the NPC to respond accordingly if the user has inputed the correct or incorrect answer. 
	if (playerValues.health != 0 && health > 0)
	{
		if (!wrongResponseCheck && !rightResponseCheck)
		{
			lineText.drawString("May : " + XMLlines.text[id].substr(0, loopCheck), ofGetWidth() * 0.1, ofGetHeight() * 0.71); // Question
		}
		if (wrongResponseCheck && !rightResponseCheck)
		{

			//std::cout << "Loading incorrect Answer" << std::endl;

			lineText.drawString("May : " + XMLlines.responseWrong[id].substr(0, loopCheck), ofGetWidth() * 0.1, ofGetHeight() * 0.71);
			if (loopCheck == XMLlines.responseWrong[id].size())
			{
				//std::cout << "Incorrect Answer" << std::endl;
				wrongResponseCheck = false;
				loopCheck = 0;

				//std::cout << wrongResponseCheck << std::endl;
			}
		}
		if (rightResponseCheck && !wrongResponseCheck)
		{
			//std::cout << "Loading correct answer" << std::endl;

			lineText.drawString("May : " + XMLlines.responseRight[id].substr(0, loopCheck), ofGetWidth() * 0.1, ofGetHeight() * 0.71);
			if (loopCheck == XMLlines.responseRight[id].size())
			{
				rightResponseCheck = false;
				loopCheck = 0;

				if (id <= XMLlines.answer.size())
				{
					id++;
					if (id == XMLlines.answer.size())
					{
						id = 0;
					}
					;
				}
				
			}
		}
		//For some reason there is a bug when both responses get triggered at the same time, this is a fix to that problem
		if (wrongResponseCheck && rightResponseCheck)
		{
			playerValues.health += 1;
			std::cout << "Euston we have a problem";
			wrongResponseCheck = false;
		}

	}
	else if (health == 0)
	{
		i++;
		if (i < 100)
		{
			lineText.drawString("Alright you win, go away", ofGetWidth() * 0.1, ofGetHeight() * 0.71);
			//std::cout << i << std::endl;
		}
		else
		{
			health = -1;
		}
	}
	else //Fail state
	{
		lineText.drawString("HaHaHa, I will make america great again!", ofGetWidth() * 0.1, ofGetHeight() * 0.71);
	}

	//ENEMY HEALTH BAR----------------------------------------------
	ofSetColor(0);
	ofRect(30, 10, ofGetWidth() - 60, ofGetHeight() * 0.075);
	ofSetColor(255, 0, 0); //Red
	ofRect(35, 15, mappedEnemy, ofGetHeight() * 0.06);
	ofSetColor(255);
	healthText.drawString("Enemy Health", ofGetWidth() / 2 - 75, ofGetHeight() * 0.05);

	//Player Health Bar
	ofSetColor(0);
	ofRect(20, ofGetHeight() * 0.55, ofGetWidth() * 0.20, ofGetHeight() * 0.05);
	ofSetColor(0, 255, 0);
	ofRect(25, ofGetHeight() * 0.555, mappedPlayer, ofGetHeight() * 0.040);
	ofSetColor(255, 255, 255);
	healthText.drawString("Your Health", ofGetWidth() * 0.05, ofGetHeight() * 0.585);



	//Changing time measure here will
	if (!wrongResponseCheck && !rightResponseCheck)
	{
		if (timeMeasure > 1000 && loopCheck < XMLlines.text[id].size()) //This if statement allows for the loading animation in the program
		{
			loopCheck = loopCheck + 1;
			timeMeasure = 0;
		}
	}
	if (wrongResponseCheck)
	{
		if (timeMeasure > 1000 && loopCheck < XMLlines.responseWrong[id].size()) //This if statement allows for the loading animation in the program
		{
			loopCheck = loopCheck + 1;
			timeMeasure = 0;
		}
	}
	if (rightResponseCheck)
	{
		if (timeMeasure > 1000 && loopCheck < XMLlines.responseRight[id].size()) //This if statement allows for the loading animation in the program
		{
			loopCheck = loopCheck + 1;
			timeMeasure = 0;
		}
	}

	/*
		BOX GUI section
		- This GUI section handles the text boxes color and gives feedback to the user
	*/
	if (!wrongResponseCheck && !rightResponseCheck) {
		if (loopCheck == XMLlines.text[id].size() && playerValues.health != 0) //Loads the text boxes only if the text has fully loaded. This is to give an animation effect
		{
			ofSetColor(0);
			//TEXT BOX 1-----------------------------------------------------------------------------------
			if (ofGetMouseY() > heightValues[0] - ofGetHeight() * 0.08 && ofGetMouseY() < heightValues[0])
			{
				ofSetColor(0);
				ofRect(0, heightValues[0] - ofGetHeight() * 0.08, ofGetWidth(), ofGetHeight() * 0.08);

				ofSetColor(255);
				lineText.drawString(XMLlines.answer[id], ofGetWidth() * 0.1, heightValues[0]);
			}
			else
			{
				ofSetColor(255);
				ofRect(0, heightValues[0] - ofGetHeight() * 0.08, ofGetWidth(), ofGetHeight() * 0.08);

				ofSetColor(0);
				lineText.drawString(XMLlines.answer[id], ofGetWidth() * 0.1, heightValues[0]);
			}
			//---------------------------------------------------------------------------------------------

			//TEXT BOX 2-----------------------------------------------------------------------------------
			if (ofGetMouseY() > heightValues[1] - ofGetHeight() * 0.08 && ofGetMouseY() < heightValues[1])
			{
				ofSetColor(0);
				ofRect(0, heightValues[1] - ofGetHeight() * 0.08, ofGetWidth(), ofGetHeight() * 0.08);

				ofSetColor(255);
				lineText.drawString(XMLlines.wrongAnswer1[id], ofGetWidth() * 0.1, heightValues[1]);
			}
			else
			{
				ofSetColor(255);
				ofRect(0, heightValues[1] - ofGetHeight() * 0.08, ofGetWidth(), ofGetHeight() * 0.08);

				ofSetColor(0);
				lineText.drawString(XMLlines.wrongAnswer1[id], ofGetWidth() * 0.1, heightValues[1]);
			}
			//TEXT BOX 3-----------------------------------------------------------------------------------
			if (ofGetMouseY() > heightValues[2] - ofGetHeight() * 0.08 && ofGetMouseY() < heightValues[2])
			{
				ofSetColor(0, 0, 0);
				ofRect(0, heightValues[2] - ofGetHeight() * 0.08, ofGetWidth(), ofGetHeight() * 0.08);

				ofSetColor(255, 255, 255);
				lineText.drawString(XMLlines.wrongAnswer2[id], ofGetWidth() * 0.1, heightValues[2]);
			}
			else
			{
				ofSetColor(255, 255, 255);
				ofRect(0, heightValues[2] - ofGetHeight() * 0.08, ofGetWidth(), ofGetHeight() * 0.08);

				ofSetColor(0, 0, 0);
				lineText.drawString(XMLlines.wrongAnswer2[id], ofGetWidth() * 0.1, heightValues[2]);
			}
			//-----------------------------------------------------------------------------------
		}
	}

}

void may::mousePressed() {
	/*
		This function passes the result that the user has clicked.
		There are only two possible states in this section of program
			- Correct, if correct the user will continue to the next question
			- Incorrect, if incorrect the user will lose health and the enemy will respond.

	*/
	if (playerValues.health != 0) {
		if (ofGetMouseY() > heightValues[0] - ofGetHeight() * 0.08 && ofGetMouseY() < heightValues[0])
		{
			health -= 1; //Enemy Health
			loopCheck = 0;
			timeMeasure = 0;
			rightResponseCheck = true;

			//This simply stops the vector from going out of range which causes a nasty runtime error.


			std::random_shuffle(heightValues.begin(), heightValues.end()); //Shuffles the question order

			/*
				//Uncomment this to print off the values after std::random_shuffle()
				std::cout << heightValues[0] << std::endl;
				std::cout << heightValues[1] << std::endl;
				std::cout << heightValues[2] << std::endl;
			*/

		}
		//The incorrect response
		if (ofGetMouseY() > heightValues[1] - ofGetHeight() * 0.08 && ofGetMouseY() < heightValues[1])
		{
			std::cout << "Why has this been executed?";
			playerValues.playerLoseHealth(1); //The player health

			//The animations need to be reset, even if the user gets the question wrong
			loopCheck = 0;
			timeMeasure = 0;
			wrongResponseCheck = true;

		}
		if (ofGetMouseY() > heightValues[2] - ofGetHeight() * 0.08 && ofGetMouseY() < heightValues[2])
		{
			std::cout << "Why has this been executed?";

			playerValues.playerLoseHealth(1); //The player health

			//The animations need to be reset, even if the user gets the question wrong
			loopCheck = 0;
			timeMeasure = 0;
			wrongResponseCheck = true;

		}
	}


}