
#include "character.h"

Character::Character() {


	character.loadImage("char.png");
}

void Character::draw() {

	character.draw(x, y);
}

void Character::move(int key) {

	switch (key) {

	case 1:
		x += 5;
	break;
	case 2:
		x -= 5;
		break;
	case 3:
		y += 5;
		break;
	case 4:
		y -= 5;
    }	
}