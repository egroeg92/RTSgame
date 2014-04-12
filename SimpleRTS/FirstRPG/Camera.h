#pragma once
#include "SDL_Setup.h"
class CCamera
{
public:
	CCamera();
	~CCamera();
	void Draw(float MouseX, float MouseY,CSDL_Setup *setup);
	float getX();
	float getY();
	float getMiniX();
	float getMiniY();
private:
	bool miniMap;
	float CameraX;
	float CameraY;
	float MiniMapX;
	float MiniMapY;
	float CameraSpeed;
};

