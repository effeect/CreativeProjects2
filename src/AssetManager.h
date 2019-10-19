#pragma once

#ifndef ASSET_MANAGER_H
#define ASSET_MANAGER_H

#include <map>
#include <string>
#include "vector2D.h"
#include "ECS/ECS.h"
#include <vector>
#include "ofMain.h"

class AssetManager
{
public:
	AssetManager(Manager* man);
	~AssetManager();

	void AddTexture(std::string id, const char* path);
	string GetMap(std::string id);
	
	void AddLevel(std::string id, const char* path);

	ofImage GetTexture(std::string id);


	string map_level;
	ofImage texture_load;
private:

	Manager* manager;
	
	//Using std::map to store the textures with a "name" and the paired data
	//map is a paired type of array where always two pair of values are stored
	std::map<std::string, ofImage> texture;
	std::map<std::string, string> level;
	std::map<std::string, vector<int>> maps;
};

#endif // !ASSET_MANAGER_H
