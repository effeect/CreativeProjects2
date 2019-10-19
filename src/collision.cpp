

#include "collision.h"
#include "ECS/colliderComponent.h"

//basic AABB collision used in general
bool Collision::AABB(const ofRectangle& rectA, const ofRectangle& rectB) {
	
				if (

					rectA.x + rectA.width >= rectB.x &&
					rectB.x + rectB.width >= rectA.x &&
					rectA.y + rectA.height >= rectB.y &&
					rectB.y + rectB.height >= rectA.y
					/*character.position.x >= tile.position.x &&
					character.position.x <= tile.position.x + 32 &&
					character.position.y >= tile.position.y &&
					character.position.y <= tile.position.y + 32*/
					) {

					return true;
				}
	return false;

}
//Was a test function
bool Collision::AABB(const ColliderComponent& rectA, const ColliderComponent& rectB)
{
	if (AABB(rectA.collider, rectB.collider)) {

		std::cout << rectA.tag << "hit" << rectB.tag << std::endl;
		return true;
	}
	else
	{
		return false;
	}

}

	
//int type = 0;
//
//for (int row = 0; row < 10; row++) {
//	for (int col = 0; col < 15; col++) {
//
//		type = tile.map[row][col];
//		if (type == 1) {