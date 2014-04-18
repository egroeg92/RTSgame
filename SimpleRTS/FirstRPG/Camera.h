#pragma once
#include "SDL_Setup.h"
class CCamera
{
public:
	CCamera(float w, float h);
	~CCamera();
	void Draw(float MouseX, float MouseY,CSDL_Setup *setup);
	void setX(float x);
	void setY(float y);
	
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
	float screenWidth;
	float screenHeight;
};

