#pragma once

#include "ofMain.h"
#include <iostream>

//#include "character.h"
//#include "tile.h"

#ifndef COLLISION_H
#define COLLISION_H

class ColliderComponent;

class Collision
{

public:

	static bool AABB(const ofRectangle& rectA, const ofRectangle& rectB);
	static bool AABB(const ColliderComponent& rectA, const ColliderComponent& rectB);
};



#endif // !COLLISION_H
