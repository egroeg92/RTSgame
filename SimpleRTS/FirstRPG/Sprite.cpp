#include "stdafx.h"
#include "Sprite.h"


CSprite::CSprite(SDL_Renderer* pRenderer, std::string filename, int x, int y, int w, int h, float *pCameraX, float *pCameraY)
{
	renderer = pRenderer;
	image = NULL;
	image = IMG_LoadTexture(renderer, filename.c_str());

	if (image == NULL)
	{
		std::cout << "Could not load image" << std::endl;
	}
	rect.x = x;
	rect.y = y;
	rect.w = w;
	rect.h = h;

	SDL_QueryTexture(image, NULL, NULL, &img_width, &img_height);

	crop.w = img_width;
	crop.h = img_height;

	X_pos = x;
	Y_pos = y;

	Origin_X = 0;
	Origin_Y = 0;


	CameraX = pCameraX;
	CameraY = pCameraY;
	Camera.x = rect.x + *CameraX;
	Camera.y = rect.y + *CameraY;
	Camera.w = rect.w;
	Camera.h = rect.h;



}


CSprite::~CSprite()
{
	SDL_DestroyTexture(image);
}

void CSprite::Draw()
{
	Camera.x = rect.x + *CameraX;
	Camera.y = rect.y + *CameraY;
	SDL_RenderCopy(renderer, image, &crop, &Camera);


}

void CSprite::setX(float x)
{
	X_pos = x;
	rect.x = int(x - Origin_X);
}

void CSprite::setY(float y)
{
	Y_pos = y;
	rect.y = int(y - Origin_Y);
}
void CSprite::setPosition(float x, float y)
{
	X_pos = x;
	Y_pos = y;
	rect.x = int(x - Origin_X);
	rect.y = int(y - Origin_Y);
}

float CSprite::getX()
{
	return X_pos;
}
float CSprite::getY()
{
	return Y_pos;
}
void CSprite::SetOrigin(float x, float y)
{
	Origin_X = x;
	Origin_Y = y;

	setPosition(getX(), getY());
}

int CSprite::getHeight()
{
	return rect.h;
}
int CSprite::getWidth()
{
	return rect.w;
}

void CSprite::setHeight(int x)
{
	rect.h = x;
}
void CSprite::setWidth(int x)
{
	rect.w = x;
}

