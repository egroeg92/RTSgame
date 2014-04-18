#pragma once
#include "GameObject.h"
#include "SDL_Setup.h"
#include "Camera.h"

class CUnit : public CGameObject
{
public:
	CUnit(float phealth, SDL_Renderer* pRenderer, std::string filename, int x, int y, int w, int h, int pamount_frame_x, int pamount_frame_y, float *pCameraX, float *pCameraY);

	void keyControl(CSDL_Setup* csdl_setup, CCamera * camera,int endFrame,  float speed);

private:
	void setAnimation(int px, int py);
	void playAnimation(int EndFrame, float Speed);

	int current_frame;
	int animationDelay;
	int amount_frame_x;
	int amount_frame_y;
	

	bool move;
	bool move_U;
	bool move_D;
	bool move_L;
	bool move_R;

	int timeCheck;
	int row;

};

