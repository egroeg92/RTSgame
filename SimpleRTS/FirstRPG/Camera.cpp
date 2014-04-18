#include "stdafx.h"
#include "Camera.h"


CCamera::CCamera(float w, float h)
{
	miniMap = false;
	CameraX = 0;
	CameraY = 0;
	MiniMapX = 0;
	MiniMapY = 0;
	screenHeight = h;
	screenWidth = w;
	CameraSpeed =  0.45f;
}


CCamera::~CCamera()
{
}
void CCamera::setX(float x)
{
	CameraX = x+(screenWidth/2);

	MiniMapX = -(CameraX / 18);

}
void CCamera::setY(float y)
{
	CameraY = y+(screenHeight/2)-10;
	MiniMapY = -(CameraY / 12);
}

float CCamera::getX()
{
	return CameraX;
}

float CCamera::getMiniX()
{
	return MiniMapX;
}

float CCamera::getY()
{
	return CameraY;
}

float CCamera::getMiniY()
{
	return MiniMapY;
}
void CCamera::Draw(float MouseX, float MouseY, CSDL_Setup *setup)
{
	if (MouseX < 20 && MouseX > 0  && CameraX <200)
	{
		CameraX += CameraSpeed;
	}
	else if (MouseX > 879 && MouseX < 899 && CameraX > -2900 && MouseY < 500)
	{
		CameraX -= CameraSpeed;
	}


	if (MouseY < 20 && MouseY > 0 && CameraY <200)
	{
		CameraY += CameraSpeed;
	}
	else if (MouseY > 579 && MouseY < 600 && CameraY > -2000 && MouseX < 700)
	{
		CameraY -= CameraSpeed;
	}

	if (MouseX>700 && MouseX <900 && MouseY>500 && MouseY < 700)
	{
		if (setup->getMainEvent()->type == SDL_MOUSEBUTTONDOWN)
		{
			miniMap = true;
		}
		if (setup->getMainEvent()->type == SDL_MOUSEBUTTONUP)
		{
			miniMap = false;
		}
		if (miniMap)
		{
			
			float x = (MouseX - 700)* (18);
			float y = (MouseY - 500)* (12);

			MiniMapX = (x / 18) - 25;
			MiniMapY = (y / 12) - 25;

			CameraX = -MiniMapX * 18;
			CameraY = -MiniMapY * 12;


		}

	}

	else{


		MiniMapX = -(CameraX / 18);
		MiniMapY = -(CameraY / 12);
	}
}
