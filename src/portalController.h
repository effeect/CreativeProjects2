#pragma once

#ifndef PORTAL_CONTROLLER_H
#define PORTAL_CONTROLLER_H

#include "Components.h"
#include "game.h"
#include "ECS.h"


class PortalController : public Component
{
public:

	bool isPorted = false;
	TileComponent *map;

	PortalController() = default;
	PortalController(bool isPort) {
	
		isPorted = isPort;
	}

	//~Portalcontroller() {}

	void init() override
	{
		map = &entity->getComponent<TileComponent>();
	}

	void update() override
	{
		
		if (isPorted == true) {
			
			map->mapSelect("Town");
		}
	}

};
#endif // !PORTAL_CONTROLLER_H
