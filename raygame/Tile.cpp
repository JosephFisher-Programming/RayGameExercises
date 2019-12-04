//  Tile.cpp

#include <string>
#include <iostream>
#include "raylib.h"
#include "Tile.h"

Tile::Tile(std::string imageFilename) 
{
	Background = LoadTexture(imageFilename.data());
	tint = WHITE;
}
Tile::Tile() 
{
	//Background = LoadTexture("mapTile_001.png");
	tint = WHITE;
}
Tile::~Tile() 
{
}