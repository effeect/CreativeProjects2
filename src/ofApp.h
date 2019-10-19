#pragma once

#include "ofMain.h"
//#include "tile.h"
//#include "character.h"
#include "collision.h"
#include "game.h"
#include "ECS/Components.h"
#include "ECS.h"

#include <iostream>
#include <algorithm>
//Fighting Related Functions
#include "ofMain.h"
#include "enemy.h"
#include <fstream>
#include "playerStats.h"
#include "XMLreader.h"
#include "ofxXmlSettings.h"

//Enemy Classes
#include "trump.h"
#include "farage.h"
#include "duke.h"
#include "may.h"


#include "HubWorldText.h"

using namespace std;

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		Game *game = nullptr;

		
		//Tile* tile = new Tile();
		//Character* character = new Character();

		
		ofRectangle tileRect;
		ofRectangle charRect;
		
		
		float y_pos;
		float x_pos;

		int type = 0;

		float playerY, playerX;

		bool is_hitpoint = false;

		

//FIGHTING SYSTEM RELATED FUNCTIONS
		//Enemy Types
		trump TrumpEnemy{ 0,0 };
		farage farageEnemy{ 0,0 };
		duke dukeEnemy{ 0,0 };
		may mayEnemy{ 0,0 };
		

		//This class stores all of the player values, this contains health, skill and morale
		playerStats playerValues;

		//HUD RELATED variables
		bool enemySwitchX = false;
		bool enemySwitchY = false;

		float enemyMoveX = 0;
		float enemyMoveY = 0;

		ofTrueTypeFont myFont;
		//ofTrueTypeFont lineText;
		float winWidth;
		float winHeight;

		float playerHealth;
		float playerSkill;

		HubWorldText hubTextClass;

		bool testing = false;
		bool testing2 = false;

		//Map Images
		ofImage outskirts;
		ofImage warehouse;

		//Menu Stuff 
		ofVideoPlayer myPlayer;
		ofTrueTypeFont menuFont;
		bool isOnMenu = true;
		ofImage tutorial;
};
