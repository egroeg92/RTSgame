#pragma once
#include "Sprite.h"
class CGameObject : public CSprite
{
public:
	CGameObject(float phealth ,SDL_Renderer* pRenderer, std::string filename, int x, int y, int w, int h, float *pCameraX, float *pCameraY);
	void repair(float d);
	void damage(float d);
	float getHealth();

private:

	float health;
};

