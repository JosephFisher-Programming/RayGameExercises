/*******************************************************************************************
*
*   raylib [core] example - basic window
*
*   This example has been created using raylib 1.0 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2013-2016 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib.h"
#include "Tile.h"

void drawTile(Tile tile, int xPos, int yPos);
void drawTile(Tile tile[], int xPos, int yPos);

int main()
{
	// Initialization
	//--------------------------------------------------------------------------------------
	int screenWidth = 1600;
	int screenHeight = 900;
	int tileNum = 0;

	InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

	Tile ground1;
	Tile ground2{ "mapTile_003.png" };

	Tile tileMap[4];
	Tile tilesPlaced[100];

	tileMap[0].Background = LoadTexture("mapTile_002.png");
	tileMap[1].Background = LoadTexture("mapTile_016.png");
	tileMap[2].Background = LoadTexture("mapTile_018.png");
	tileMap[3].Background = LoadTexture("mapTile_032.png");

	SetTargetFPS(60);
	//--------------------------------------------------------------------------------------

	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		// Update
		//----------------------------------------------------------------------------------
		// TODO: Update your variables here
		//----------------------------------------------------------------------------------
		if (IsMouseButtonDown(0)) 
		{
			int mouseX = GetMouseX();
			int mouseY = GetMouseY();
			for (int i = 0; i < 4; i++) {
				if ((mouseX - (int)tileMap[i].position.x <= 32 && mouseX - (int)tileMap[i].position.x >= -32) && (mouseY - (int)tileMap[i].position.y <= 32 && mouseY - (int)tileMap[i].position.y >= -32))
				{
					ground1.Background = tileMap[i].Background;
					ground1.masterTile = true;

				}
			}
			if (ground1.masterTile == true)
			{
				if (tileNum > 99)
					tileNum = 0;
				tilesPlaced[tileNum] = ground1;
				tileNum++;
			}
			
		}
		// Draw
		//----------------------------------------------------------------------------------
		BeginDrawing();

		ClearBackground(RAYWHITE);

		DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

		drawTile(ground1,GetMouseX(),GetMouseY());
		drawTile(ground2, 300, 300);
		drawTile(tileMap,0,0);

		for (int i = 0; i < 100; i++) 
		{
			if (tilesPlaced[i].position.y == NULL) 
			{
				break;
			}
				
			drawTile(tilesPlaced[i], tilesPlaced[i].position.x, tilesPlaced[i].position.y);
		}

		EndDrawing();
		//----------------------------------------------------------------------------------
	}

	// De-Initialization
	//--------------------------------------------------------------------------------------   
	CloseWindow();        // Close window and OpenGL context
	//--------------------------------------------------------------------------------------

	return 0;
}

void drawTile(Tile tile, int xPos, int yPos) 
{
	tile.position.x = xPos + 32;
	tile.position.y = yPos + 32;
	DrawTexture(tile.Background, xPos-32, yPos-32, tile.tint);
}

void drawTile(Tile tile[], int xPos, int yPos)
{
	for (int i = 0; i < 4; i++) 
	{
		tile[i].position.x = xPos + (i * 64) + 32;
		tile[i].position.y = yPos + 32;
		DrawTexture(tile[i].Background, xPos + (i*64), yPos, tile[i].tint);
	}
}