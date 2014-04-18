#pragma once
#include "SDL_Setup.h"
#include "Sprite.h"
#include "Camera.h"

#include "Unit.h"

class CMain
{
public:
	CMain(int passed_screenWidth, int passed_screenHeight);

	~CMain(void);

	void GameLoop();
	double GetDistance(int x1, int y1, int x2, int y2);

private:
	CUnit *dude;
	
	CCamera* Camera;
	float CameraX;
	float CameraY;
	float MenuX;
	float MenuY;
	float MiniMapX;
	float MiniMapY;
	bool quit;

	CSDL_Setup* csdl_setup;
	CSprite* back_ground;
	CSprite* menu_frame;
	CSprite* mini_map;
	CSprite* mini_mapFrame;

	//Mouse movement
	int MouseX;
	int MouseY;

	int curX;
	int curY;

	bool follow;
};

