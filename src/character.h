#pragma once

#ifndef CHARACTER_H
#define CHARACTER_H

#include "ofMain.h"

class Character {

private:


	int x = 10;
	int y = 10;

	ofImage character;

public:

	Character();
	~Character();

	void draw();
	void move(int key);

	ofVec2f position = { x, y };

};
#endif // !CHARACTER_H
