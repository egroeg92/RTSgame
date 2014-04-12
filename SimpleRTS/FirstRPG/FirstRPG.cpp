// FirstRPG.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Main.h"

int main(int argc, char *argv[])
{
	// initiate video
	SDL_Init(SDL_INIT_VIDEO);
	
	CMain* cmain = new CMain(900,700);
	cmain->GameLoop();
	delete cmain;
	return 0;
}

