#pragma once
#ifndef LEVELS_H
#define LEVELS_H




#include <string>
struct Levels
{
	int index;
	std::string path;

	Levels() {}
	Levels(int i, std::string p) {
		index = i;
		path = p;
	}
};

#endif // !#pragma once
