#pragma once
class CSDL_Setup
{
public:
	CSDL_Setup(bool* quit, int passed_screenWidth, int passed_screenHeight, float *pCameraX, float *CameraY);
	~CSDL_Setup();

	SDL_Renderer* getRenderer();
	SDL_Event* getMainEvent();

	void Begin();
	void End();

private:
	float *CameraX;
	float *CameraY;
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Event* aEvent;
};

