#pragma once

#include "game.h"


#include "ECS.h"
#include "ECS/Components.h"
#include "ofEvent.h"
#include "ofEvents.h"
#include "tile.h"
#include "vector2D.h"
#include "collision.h"
#include "AssetManager.h"
//#include "trump.h"
//
//creating map
Tile* map1;

//Adding manager
Manager manager;

//Custom ofEvent for keyEvents
ofEvent<int> Game::event;


//int Game::mapSwitch;

//Creating the asset manager
AssetManager* Game::assets = new AssetManager(&manager);

//Adding the entities player and levels
auto& player(manager.addEntity());
auto& levels(manager.addEntity());

Game::Game() {

}
Game::~Game() {

}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {

	//Setting game window dimensions
	ofSetWindowTitle(title);
	ofSetWindowPosition(xpos, ypos);
	ofSetWindowShape(width, height);
	
	if (fullscreen) {
		ofSetFullscreen(true);
	}
	else {
		ofSetFullscreen(false);
	}

	//Adding texture of tileset
	assets->AddTexture("Outskirts", "city_new_map.jpg");

	//Creating map with same ID as the texture to match
	map1 = new Tile("Outskirts", 1, 32);

	
	//Test
	//assets->AddLevel("Outskirts", "outskirt.map");
	//assets->AddLevel("Town", "city_new_map.map");
	

	portToOutskirt = true;

	//Creating the player character and adding it to the playerGroup to work on it later
	player.addcomponent<TransformComponent>(350, 400);
	player.addcomponent<SpriteComponent>("draw_char.png");
	player.addcomponent<KeyboardController>();
	player.addcomponent<ColliderComponent>("player");
	player.addGroup(groupPlayer);

}

//Getting the groups data of each entity inside the group for collision, drawing, destroying etc.
auto& tiles(manager.getGroup(Game::groupMap));
auto& players(manager.getGroup(Game::groupPlayer));
auto& colliders(manager.getGroup(Game::groupColliders));
auto& outskirtPorts(manager.getGroup(Game::groupOutskirtsPort));
auto& townPorts(manager.getGroup(Game::groupTownPort));
auto& warehousePorts(manager.getGroup(Game::groupWarehousePort));
auto& docksPorts(manager.getGroup(Game::groupDocksPort));
auto& townEnemy(manager.getGroup(Game::groupTownEnemy));
auto& warehouseEnemy(manager.getGroup(Game::groupWarehouseEnemy));
auto& docksEnemy(manager.getGroup(Game::groupDocksEnemy));
auto& docksEnemy2(manager.getGroup(Game::groupDocksEnemy2));

//Had no real need for this
void Game::handleEvents() {

}

void Game::update() {

	//Was using this in first phase of tests for triggering battle and given location
	locationX = player.getComponent<TransformComponent>().position.x;
	locationY = player.getComponent<TransformComponent>().position.y;

	//Creating the player's collision rectangle and getting it's position
	ofRectangle playerCol = player.getComponent<ColliderComponent>().collider;
	Vector2D playerPos = player.getComponent<TransformComponent>().position;

	//Calling refresh and update on manager (essentially all the components update functions)
	manager.refresh();

	manager.update();

	//Checking the colliders againts the player collider for collision
	for (auto& c : colliders) {

		ofRectangle cCol = c->getComponent<ColliderComponent>().collider;
		if (Collision::AABB(cCol, playerCol))
		{
			player.getComponent<TransformComponent>().position = playerPos;
		}
	}

	//Checking collision againts the map portals and setting the new location on the new map
	//And sets given boolean to true to create the new map
	for (auto& p : outskirtPorts) {
		ofRectangle pCol = p->getComponent<ColliderComponent>().collider;
		if (Collision::AABB(pCol, playerCol))
		{
				portToOutskirt = true;
				player.getComponent<TransformComponent>().position.x = 550;
				player.getComponent<TransformComponent>().position.y = 400;
				//cout << "first port" << endl;
		}
		
	}
	for (auto& p : townPorts) {
		ofRectangle pCol = p->getComponent<ColliderComponent>().collider;
		if (Collision::AABB(pCol, playerCol))
		{
			portToTown = true;
			player.getComponent<TransformComponent>().position.x = 100;
			player.getComponent<TransformComponent>().position.y = 160;
			//cout << "first port" << endl;
		}

	}
	for (auto& p : warehousePorts) {
		ofRectangle pCol = p->getComponent<ColliderComponent>().collider;
		if (Collision::AABB(pCol, playerCol))
		{
			portToWarehouse = true;
			player.getComponent<TransformComponent>().position.x = 50;
			player.getComponent<TransformComponent>().position.y = 70;
			//cout << "first port" << endl;
		}

	}
	for (auto& p : docksPorts) {
		ofRectangle pCol = p->getComponent<ColliderComponent>().collider;
		if (Collision::AABB(pCol, playerCol))
		{
			portToDocks = true;
			player.getComponent<TransformComponent>().position.x = 280;
			player.getComponent<TransformComponent>().position.y = 50;
			//cout << "first port" << endl;
		}

	}
	//Checking collision againts the enemies to trigger the battles
    for (auto& e : townEnemy) {
		ofRectangle pCol = e->getComponent<ColliderComponent>().collider;
		if (Collision::AABB(pCol, playerCol)) {
			townEnemyTrigger = true;
		}
	}
	for (auto& e : warehouseEnemy) {
		ofRectangle pCol = e->getComponent<ColliderComponent>().collider;
		if (Collision::AABB(pCol, playerCol)) {
			warehouseEnemyTrigger = true;
		}
	}
	for (auto& e : docksEnemy) {
		ofRectangle pCol = e->getComponent<ColliderComponent>().collider;
		if (Collision::AABB(pCol, playerCol)) {
			docksEnemyTrigger = true;
		}
	}
	for (auto& e : docksEnemy2) {
		ofRectangle pCol = e->getComponent<ColliderComponent>().collider;
		if (Collision::AABB(pCol, playerCol)) {
			docksEnemyTrigger2 = true;
		}
	}

	//Test, didn't need in the end
	for (auto& e : townEnemy) {
		if (townEnemy_end == true) {
			e->destroy();
		}
	}


	

	
	 //Loading tile maps
	//Biggest headache. If I simply loaded tiles here upon collision it made the game really slow.
	//Solution was simple tho. After loading just the bool back to false so it only loads once.
	//It allso calls destroy on all the present tiles and colliders before drawing the new map
	//Loading time is still a bit slow..
	if (portToOutskirt == true) {

		for (auto& t : tiles) {
			t->destroy();
		}
		for (auto& c : colliders) {
			c->destroy();
		}
		for (auto& p : warehousePorts) {
			p->destroy();
		}
		for (auto& p : outskirtPorts) {
			p->destroy();
		}
		for (auto& p : docksPorts) {
			p->destroy();
		}
        for (auto& e : townEnemy) {
			e->destroy();
		}
		map1->loadTile("outskirt.map", 20, 25);
		portToOutskirt = false;
		
	}
	if (portToTown == true ) {
	
		for (auto& t : tiles) {
			t->destroy();
		}
		for (auto& c : colliders) {
			c->destroy();
		}
		for (auto& p : townPorts) {
			p->destroy();
		}
        for (auto& e : warehouseEnemy) {
			e->destroy();
		}
		for (auto& e : docksEnemy) {
			e->destroy();
		}
		for (auto& e : docksEnemy2) {
			e->destroy();
		}
		map1->loadTile("town.map", 20, 25);
		portToTown = false;
	}
	if (portToWarehouse == true) {
		for (auto& t : tiles) {
			t->destroy();
		}
		for (auto& c : colliders) {
			c->destroy();
		}
		for (auto& p : warehousePorts) {
			p->destroy();
		}
		for (auto& p : outskirtPorts) {
			p->destroy();
		}
		for (auto& p : docksPorts) {
			p->destroy();
		}
        for (auto& e : townEnemy) {
			e->destroy();
		}
		map1->loadTile("warehouse.map", 20, 25);
		portToWarehouse = false;
		
	}
	if (portToDocks == true) {
		for (auto& t : tiles) {
			t->destroy();
		}
		for (auto& c : colliders) {
			c->destroy();
		}
		for (auto& p : warehousePorts) {
			p->destroy();
		}
		for (auto& p : outskirtPorts) {
			p->destroy();
		}
		for (auto& p : docksPorts) {
			p->destroy();
		}
        for (auto& e : townEnemy) {
			e->destroy();
		}
		map1->loadTile("docks.map", 20, 25);
		portToDocks = false;

	}

	
}
	


void Game::render() {
	
	//Checking through the groups and calls draw on each entity inside the groups
	for (auto& t : tiles) 
	{
		
		t->draw();
	}
	for (auto& c : colliders)
	{
	     c->draw();
	}
	for (auto& p : players) {
		p->draw();
	}
}

void Game::clean() {


}
