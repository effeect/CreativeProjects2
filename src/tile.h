#pragma once

#ifndef TILE_H
#define TILE_H

#include "ofMain.h"
#include <string>

class Tile {

public:

	Tile(std::string mID, int maps, int tiles);
	~Tile();
	void loadTile(std::string path,  int sizeX, int sizeY);
	void AddTile(int srcX, int srcY, int xpos, int ypos);
	int id;
private:
	std::string mapID;
	int mapScale;
	int tileSize;
	int scaledSize;
};

#endif // !TILE_H

