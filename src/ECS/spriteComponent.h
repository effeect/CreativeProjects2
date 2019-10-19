#pragma once

#include "Components.h"
#include "ofMain.h"
#include <chrono>

class SpriteComponent : public Component
{

private:
	//Creating ofImage for texture use
	TransformComponent *transform;
	ofImage texture;
	ofImage texture_used;
	ofRectangle srcRect, destRect;

	bool animated = false;
	int frames = 0;
	int speed = 100;

public:
	SpriteComponent() = default;
	//Getting the image path
	SpriteComponent(const char* path)
	{
		setTex(path);
	}

	~SpriteComponent()
	{
		texture.clear();
	}

	//Failed attempt on character animation :(
	SpriteComponent(const char* path, int nFrames, int mSpeed)
	{
		animated = true;
		frames = nFrames;
		speed = mSpeed;
		setTex(path);
	}

	//Setting the texture
	void setTex(const char* path)
	{
		texture.load(path);
	}

	void init() override
	{
		//Getting Transformcomp for location and movement
		transform = &entity->getComponent<TransformComponent>();

		srcRect.x = 0;
		srcRect.y = 0;
		srcRect.width = transform->width;
		srcRect.height = transform->height;

		

	}

	void update() override
	{
		//Again for animation...didnt work :(
		if (animated)
		{
			//int thing = static_cast<int>((ofGetElapsedTimeMillis() / speed) % frames);
			//cout << thing << endl;
			srcRect.x = srcRect.width * static_cast<int>((ofGetElapsedTimeMillis() / speed) % frames);

			texture_used.cropFrom(texture, srcRect.x, srcRect.y, srcRect.width, srcRect.height);
		}

		//casting location to int for easier later calculation of drawing with movement
		destRect.x = static_cast<int>(transform->position.x);
		destRect.y = static_cast<int>(transform->position.y);

		destRect.width = transform->width * transform->scale;
		destRect.height = transform->height * transform->scale;
	}
	void draw() override
	{
		if (animated) {
			texture_used.draw(destRect.x, destRect.y);
		}
		else {
			texture.draw(destRect.x, destRect.y);
		}
		
	}

};
