#pragma once
#include "GameObject.h"
#include "SDL_Setup.h"
#include "Camera.h"

#define UP  0
#define UP_R 1
#define RIGHT  2
#define RIGHT_D 3
#define DOWN  4
#define DOWN_L 5
#define LEFT  6
#define LEFT_U 7

class CUnit : public CGameObject
{
public:
	CUnit(float phealth, SDL_Renderer* pRenderer, std::string filename, int x, int y, int w, int h, int pamount_frame_x, int pamount_frame_y, float *pCameraX, float *pCameraY);
	void keyControl(CSDL_Setup* csdl_setup, CCamera * camera,int endFrame,  float speed);

private:
	void setAnimation(int px, int py);
	void playAnimation(int BeginFrame,int EndFrame, float Speed);

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

	int dir;

	float health;
	bool puke;

};

