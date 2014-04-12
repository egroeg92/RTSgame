#include "stdafx.h"
#include "SDL_Setup.h"


CSDL_Setup::CSDL_Setup(bool* quit, int passed_screenWidth, int passed_screenHeight, float *pCameraX, float *pCameraY)
{
	CameraX = pCameraX;
	CameraY = pCameraY;
	window = NULL;
	//window 600x400 at (500,500) on screen(from top left corner)

	window = SDL_CreateWindow("My RPG", 100, 100, passed_screenWidth, passed_screenHeight, SDL_WINDOW_SHOWN );
	if (window == NULL)
	{
		std::cout << "Cannot create window" << std::endl;
		*quit = true;
	}

	//renderer updates the screen
	renderer = NULL;
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	aEvent = new SDL_Event();
}


CSDL_Setup::~CSDL_Setup()
{

	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	delete(aEvent);
}

SDL_Renderer* CSDL_Setup::getRenderer()
{
	return renderer;
}

SDL_Event* CSDL_Setup::getMainEvent()
{
	return aEvent;
}

void CSDL_Setup::Begin()
{
	SDL_PollEvent(aEvent);
	SDL_RenderClear(renderer);

}

void CSDL_Setup::End()
{
	SDL_RenderPresent(renderer);

}