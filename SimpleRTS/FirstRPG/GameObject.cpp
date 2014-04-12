#include "stdafx.h"
#include "GameObject.h"


CGameObject::CGameObject(float phealth, SDL_Renderer* pRenderer, std::string filename, int x, int y, int w, int h, float *pCameraX, float *pCameraY) 
: CSprite(pRenderer, filename, x, y, w, h, pCameraX, pCameraY)
{
	health = phealth;
}

CGameObject::~CGameObject() 
{
}

void CGameObject::repair(float d)
{
	health += d;
}
void CGameObject::damage(float d)
{
	health -= d;
}
float CGameObject::getHealth()
{
	return health;
}