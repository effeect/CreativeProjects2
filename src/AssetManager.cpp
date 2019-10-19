#include "AssetManager.h"

AssetManager::AssetManager(Manager* man) : manager(man)
{

}

AssetManager::~AssetManager()
{

}

//Function to get the texture with a name/ID. I couldn't dirrectly emplace ofImage into the map
//texture.emplace(id, texture_load.load(path)) <<--- doesnt't work
//It works this way tho
void AssetManager::AddTexture(std::string id, const char* path)
{
	texture_load.load(path);
	texture[id] = texture_load;
}

//Was a test function for tilemap storing. Didn't work out
void AssetManager::AddLevel(std::string id, const char* path) {

	level.emplace(id, path);
}
//Getting the texture with the correct ID from the map array
ofImage AssetManager::GetTexture(std::string id)
{
	return texture[id];
}

//Getting the correct tilemap ... again test, didn't work out
string AssetManager::GetMap(std::string id) {
	
	return level[id];
}