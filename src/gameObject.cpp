
#include "gameObject.h"

//Test class in the begining.
gameObject::gameObject(const char* _texture) {

	texture.loadImage(_texture);
}

void gameObject::update() {

	xpos = 0;
	ypos = 0;

	srcRect.height = 32;
	srcRect.width = 32;
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.x = xpos;
	destRect.y = ypos;
	destRect.height = srcRect.height * 2;
	destRect.width = srcRect.width * 2;

}

void gameObject::draw() {

	//texture.draw(srcRect);
	texture.draw(destRect.x, destRect.y);
}