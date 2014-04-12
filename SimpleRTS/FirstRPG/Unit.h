#pragma once
#include "GameObject.h"
class CUnit : public CGameObject
{
public:
	CUnit(float phealth, SDL_Renderer* pRenderer, std::string filename, int x, int y, int w, int h, float *pCameraX, float *pCameraY);
	~CUnit();
	void SetUpAnimation(int px, int py);
	void PlayAnimation(int beginFrame, int EndFrame, int Row, float Speed);
private:
	SDL_Rect crop;
	int CurrentFrame;
	int animationDelay;
	int Amount_Frame_X;
	int Amount_Frame_Y;
};

