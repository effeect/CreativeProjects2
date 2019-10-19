
#include "tile.h"
#include "game.h"
#include <iostream>
#include <fstream>
#include "ECS/ECS.h"
#include "ECS/Components.h"

extern Manager manager;


//Getting the mapId, mapsize, and tilesize
Tile::Tile(std::string mID, int maps, int tiles) : mapID(mID), mapScale(maps), tileSize(tiles){

	scaledSize = maps * tiles;
};

Tile::~Tile() {
	
}

//getting the file path and the dimensions of map. like 20x25
void Tile::loadTile(std::string path,  int sizeX, int sizeY)  {
	
	//Using ifstream to load in file
	char c;
	ifstream mapFile;
	mapFile.open(ofToDataPath(path).c_str());

	int srcX, srcY;

	//checking if file is open
	if (mapFile.is_open()) {
		for (int y = 0; y < sizeY; y++) {
			for (int x = 0; x < sizeX; x++) {
				//checking for double digits
				//the first number is always the Y location on the tileset
				//the second number is always the X location on the tileset
				//it then multiples the got number with the tilesize (32) to get the location of tileTexture on the tileset

				mapFile.get(c);
				srcY = atoi(&c) * tileSize;
				mapFile.get(c);
				srcX = atoi(&c) * tileSize;
				AddTile(srcX, srcY, x * scaledSize, y * scaledSize);
				//ignore the comma (,)
				mapFile.ignore();
			}
		}
	}
	//ignore the next blank line
	mapFile.ignore();
	if (mapFile.is_open()) {
		for (int y = 0; y < sizeY; y++) {
			for (int x = 0; x < sizeX; x++) {
				//This one only checks for single digit numbers using a different tilemap in the same file for colliders
				//creates and entity for each collider and adds them to their respective groups
				mapFile.get(c);
				if (c == '1')
				{
					auto& tcol(manager.addEntity());
					tcol.addcomponent<ColliderComponent>("terrain", x * scaledSize, y * scaledSize, scaledSize);
					tcol.addGroup(Game::groupColliders);
					//mapFile.ignore();
					//cout << c << endl;
				}
				else if (c == '2')
				{
					auto& tport(manager.addEntity());
					tport.addcomponent<ColliderComponent>("portal", x * scaledSize, y * scaledSize, scaledSize);
					//tport.addcomponent<PortalController>(Game::port);
					tport.addGroup(Game::groupOutskirtsPort);
					cout << "port added" << endl;
				}
				else if (c == '3')
				{
					auto& tport(manager.addEntity());
					tport.addcomponent<ColliderComponent>("portal", x * scaledSize, y * scaledSize, scaledSize);
					tport.addGroup(Game::groupTownPort);
					cout << "port added" << endl;
				}
				else if (c == '4')
				{
					auto& tport(manager.addEntity());
					tport.addcomponent<ColliderComponent>("portal", x * scaledSize, y * scaledSize, scaledSize);
					tport.addGroup(Game::groupWarehousePort);
					cout << "port added" << endl;
				}
				else if (c == '5')
				{
					auto& tport(manager.addEntity());
					tport.addcomponent<ColliderComponent>("portal", x * scaledSize, y * scaledSize, scaledSize);
					tport.addGroup(Game::groupDocksPort);
					cout << "port added" << endl;
				}
                else if (c == '6')
				{
					auto& tport(manager.addEntity());
					tport.addcomponent<ColliderComponent>("portal", x * scaledSize, y * scaledSize, scaledSize);
					tport.addGroup(Game::groupTownEnemy);
					cout << "port added" << endl;
				}
				else if (c == '7')
				{
					auto& tport(manager.addEntity());
					tport.addcomponent<ColliderComponent>("portal", x * scaledSize, y * scaledSize, scaledSize);
					tport.addGroup(Game::groupWarehouseEnemy);
					cout << "port added" << endl;
				}
				else if (c == '8')
				{
					auto& tport(manager.addEntity());
					tport.addcomponent<ColliderComponent>("portal", x * scaledSize, y * scaledSize, scaledSize);
					tport.addGroup(Game::groupDocksEnemy);
					cout << "port added" << endl;
				}
				else if (c == '9')
				{
					auto& tport(manager.addEntity());
					tport.addcomponent<ColliderComponent>("portal", x * scaledSize, y * scaledSize, scaledSize);
					tport.addGroup(Game::groupDocksEnemy2);
					cout << "port added" << endl;
				}
				mapFile.ignore();
			}
		}
			mapFile.close();

	}


}
//
void Tile::AddTile(int srcX, int srcY, int xpos, int ypos) {

	//creates and entity for each tile and adds the tilecomponent with the calculated location data and texture and adds them to the group
	auto& tile(manager.addEntity());
	tile.addcomponent<TileComponent>(srcX, srcY, xpos, ypos, tileSize, mapScale, mapID);
	//tile.addcomponent<LevelComponent>();
	tile.addGroup(Game::groupMap);
	cout << "adding tile" << endl;
}

