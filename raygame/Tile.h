//Tile.h
#include <string>
#include <iostream>
#include "raylib.h"
class Tile
{
public:
	bool masterTile = false;
	Vector2 position;
	Texture2D Background;
	Color tint;
	Tile(std::string imageFileName);
	Tile();
	~Tile();
};