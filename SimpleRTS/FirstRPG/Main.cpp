#include "stdafx.h"
#include "Main.h"
#include <math.h>

CMain::CMain(int passed_screenWidth, int passed_screenHeight)
{
	Camera = new CCamera(passed_screenWidth,passed_screenHeight);
	CameraX = 0;
	CameraY = 0;
	MiniMapX = 0;
	MiniMapY = 0;
	MenuX = 0;
	MenuY = 0;
	quit = false;

	
	csdl_setup = new CSDL_Setup(&quit, passed_screenWidth, passed_screenHeight, &CameraX, &CameraY);
	back_ground = new CSprite(csdl_setup->getRenderer(), "data/grass.bmp", 0, 0, 3600, 2400,&CameraX,&CameraY);
	menu_frame = new CSprite(csdl_setup->getRenderer(), "data/MenuFrame.png", 0, 600, 900, 100, &MenuX, &MenuY);
	mini_map = new CSprite(csdl_setup->getRenderer(), "data/miniMap.png", 700, 500, 200, 200, &MenuX, &MenuY);
	mini_mapFrame = new CSprite(csdl_setup->getRenderer(), "data/miniMap_frame.png", 700, 500, 50, 50, &MiniMapX, &MiniMapY);
	
	dude = new CUnit(100, csdl_setup->getRenderer(), "data/charBlue.png", 100, 100, 50, 50,4,4, &CameraX, &CameraY);
	//dude->setAnimation(4, 4);

	MouseX = 0;
	MouseY = 0;
	curX = 0;
	curY = 0;
	follow = false;

}


CMain::~CMain(void)
{
	delete back_ground;
	delete menu_frame;
	delete mini_map;
	delete csdl_setup;
}


void CMain::GameLoop(void)
{
	int i = 0;
	bool forward = true;
	while (!quit && csdl_setup->getMainEvent()->type != SDL_QUIT)
	{
		csdl_setup->Begin();
		SDL_GetMouseState(&MouseX, &MouseY);
		

		Camera->Draw(MouseX, MouseY, csdl_setup);
		CameraX = Camera->getX();
		CameraY = Camera->getY();
		MiniMapX = Camera->getMiniX();
		MiniMapY = Camera->getMiniY();


		//dude->playAnimation(0,3,0,200);
		dude->keyControl(csdl_setup,Camera,3, 200);		//Draw
		back_ground->Draw();
		dude->Draw();
		menu_frame->Draw();
		mini_map->Draw();
		mini_mapFrame->Draw();
		csdl_setup->End();
	}
}
