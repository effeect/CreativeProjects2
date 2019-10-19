#pragma once

#ifndef TILE_COMPONENT_H
#define TILE_COMPONENT_H

#include "Components.h"
#include "ECS.h"
#include "ofMain.h"
//#include "Maps.h"
#include "AssetManager.h"


class TileComponent : public Component
{

private:
	int x_pos;
	int y_pos;


public:
	//std::map<const char*, Maps> maps;

	ofImage texture;

	ofImage texture_used;

	//ofVbo texture;
	ofRectangle srcRect, destRect;



	TileComponent() = default;

	~TileComponent() {
		texture.clear();
	}

	//Getting location, size and name
	TileComponent(int srcX, int srcY, int xpos, int ypos, int tsize, int tscale, std::string id)
	{
		x_pos = xpos;
		y_pos = ypos;

		//the location of the image on the tilemap
		destRect.x = x_pos;
		destRect.y = y_pos;
		destRect.width = destRect.height = 32;

		//Sets the texture used
		mapSelect("Outskirts");
		setTex(id);

		//Crops the given tile from the tileset
		texture_used.cropFrom(texture, srcX, srcY, 32, 32);

	}

	void init() override
	{

		
	}

	void update() override
	{
		
	}

	void draw() override
	{
		texture_used.draw(destRect.x, destRect.y);
	}

	//Getting the texture image with the correct tag/name
	void setTex(std::string id) {
		
		texture = Game::assets->GetTexture(id);
	}

	void mapSelect(std::string mapID) {

		texture = Game::assets->GetTexture(mapID);
	}
};
#endif