#pragma once

#ifndef TRANSFORM_COMPONENT_H
#define TRANSFORM_COMPONENT_H


#include "Components.h"
#include "../vector2D.h"

class TransformComponent : public Component
{
public:

	Vector2D position;
	Vector2D velocity;

	int height = 30;
	int width = 30;
	int scale = 1;

	int speed = 3;

	//Zero position if nothing given
	TransformComponent()
	{
		position.Zero();
	}

	//Zero position and the scale
	TransformComponent(int sc)
	{
		position.Zero();
		scale = sc;
	}
	//Location
	TransformComponent(float x, float y) 
	{
		position.x = x;
		position.y = y;
	}

	//Location, size and scale
	TransformComponent(float x, float y, int w, int h, int sc)
	{
		position.x = x;
		position.y = y;
		width = w;
		height = h;
		scale = sc;
	}

	//Initially velocity is zero. Sprite/tile doesn't move
	void init() override
	{
		velocity.Zero();
	}

	//Position gets updated with velocity*speed
	void update() override
	{
		position.x += velocity.x * speed;
		position.y += velocity.y * speed;
	}

	
	
};
#endif // !TRANSFORM_COMPONENT_H