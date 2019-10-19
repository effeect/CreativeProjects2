#pragma once

#ifndef COLLIDER_COMPONENT_H
#define COLLIDER_COMPONENT_H



#include "game.h"
#include "Components.h"
#include <string>
#include "ofMain.h"



class ColliderComponent : public Component
{
public:
	ofRectangle collider;
	std::string tag;

	ofImage tex;
	ofImage tex_used;

	ofRectangle srcRect, destRect;

	TransformComponent* transform;

	ColliderComponent() {}

	//Getting only name of collider
	ColliderComponent(std::string t)
	{
		tag = t;
	}

	//Getting name, location and size of collider
	ColliderComponent(std::string t, int xpos, int ypos, int size)
	{
		tag = t;
		collider.x = xpos;
		collider.y = ypos;
		collider.height = size;
		collider.width = size;
	}

	void init() override
	{
		//Getting information from Transformcomponent for locations
		if (!entity->hasComponent<TransformComponent>())
		{
			entity->addcomponent<TransformComponent>();
		}
		transform = &entity->getComponent<TransformComponent>();

		//Setting position and size of collider rectangle
		destRect.x = collider.x;
		destRect.y = collider.y;
		destRect.width = collider.width;
		destRect.height = collider.height;
		
	}

	void update() override
	{
		//Checking if the collider has terrain (normal map tiles) or portal tags and if Not then turns it into an active collider
		if (tag != "terrain" && tag != "portal") {
			collider.x = static_cast<int>(transform->position.x);
			collider.y = static_cast<int>(transform->position.y);
			collider.width = transform->width * transform->scale;
			collider.height = transform->height * transform->scale;
		}
	
	}

	void draw() override
	{
		tex.draw(destRect.x, destRect.y);
	}
};

#endif // !COLLIDER_COMPONENT_H