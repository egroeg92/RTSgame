#include "stdafx.h"
#include "Unit.h"


CUnit::CUnit(float phealth, SDL_Renderer* pRenderer, std::string filename, int x, int y, int w, int h, float *pCameraX, float *pCameraY) 
: CGameObject(phealth, pRenderer,filename,x,y,w,h,pCameraX,pCameraY)
{
}


CUnit::~CUnit()
{
}
void CUnit::SetUpAnimation(int passed_Amount_x, int passed_Amount_Y)
{
	Amount_Frame_X = passed_Amount_x;
	Amount_Frame_Y = passed_Amount_Y;
}
void CUnit::PlayAnimation(int BeginFrame, int EndFrame, int Row, float Speed)
{
	if (animationDelay + Speed < SDL_GetTicks())
	{


		if (EndFrame <= CurrentFrame)
		{
			CurrentFrame = BeginFrame;
		}
		else
		{
			CurrentFrame++;
		}
		crop.x = CurrentFrame * (img_width / Amount_Frame_X);

		crop.y = Row * (img_height / Amount_Frame_Y);
		crop.w = img_width / Amount_Frame_X;
		crop.h = img_height / Amount_Frame_Y;
		animationDelay = SDL_GetTicks();
	}
}