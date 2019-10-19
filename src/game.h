#pragma once


#ifndef GAME_H
#define GAME_H

#include "ofMain.h"
//#include "AssetManager.h"

#include <vector>
#include <iostream>

class AssetManager;
class ColliderComponent;

class Game{

public:

	Game();
	~Game();

	//basic funtions
	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	
	void handleEvents();
	void update();
	void render();
	void clean();

	bool running() { return isRunning; };


	static ofEvent<int> event;
	static AssetManager* assets;

	//creating the groupLabels for grouping entities
    enum groupLabels : std::size_t
	{
		groupMap,
		groupPlayer,
		groupColliders,
		groupTownPort,
		groupWarehousePort,
		groupDocksPort,
		groupOutskirtsPort,
		groupTownEnemy,
		groupWarehouseEnemy,
		groupDocksEnemy,
		groupDocksEnemy2
	};

	float locationX, locationY;


	static int mapSwitch;
	bool portToOutskirt, portToTown, portToWarehouse, portToDocks;
	bool townEnemyTrigger, warehouseEnemyTrigger, docksEnemyTrigger, docksEnemyTrigger2;
	
	bool townEnemy_end;
	

	//static ofKeyEventArgs keyEvent;
private:
	bool isRunning;
	


};
#endif // !GAME_H
