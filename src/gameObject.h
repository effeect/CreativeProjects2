#pragma once


#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include "ofMain.h"
#include "Game.h"

class gameObject {

public:

	
	gameObject(const char* texture);
	~gameObject();

	void update();
	void draw();

private:

	int xpos;
	int ypos;

	ofImage texture;
	ofRectangle srcRect, destRect;
	
};

#endif // !TEXTURE_MANAGER_H
