#pragma once

#include "ECS.h"
#include "ECS/Components.h"
#include "AssetManager.h"

//Another attempt on dealing with swapping maps on the run
class MapComponent : public Component {

private:
	std::string mapName;

public:

	MapComponent(std::string mapID) : mapName(mapID) {

	}

    ~MapComponent(){}

	TileComponent *tiles;

	void init() override
	{
		tiles = &entity->getComponent<TileComponent>();
	}

	void update() override
	{
		//tiles->mapSelect(Game::mapName);
	}
	

};