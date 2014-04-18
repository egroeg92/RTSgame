#include "stdafx.h"
#include "MiniMap.h"


CMiniMap::CMiniMap(SDL_Renderer* pRenderer, std::string filename, int x, int y, int w, int h, float *pCameraX, float *pCameraY)
: CSprite(pRenderer, filename, x, y, w, h, pCameraX, pCameraY)
{
	blueDot = IMG_LoadTexture(renderer, "data/blueSpot.png");
	if (blueDot == NULL)
	{
		std::cout << "Could not load image" << std::endl;
	}
	int  dp = 5;
	SDL_QueryTexture(blueDot, NULL, NULL, &dp, &dp);

	dot.h = 5;
	dot.w = 5;
	dot.x = 705;
	dot.y = 505;
}
void CMiniMap::addObj(CSprite *  O)
{
	objs.push_back(O);
}
void CMiniMap::removeObj(CSprite * O)
{
	int i = 0;
	for (it = objs.begin(); it != objs.end(); ++it)
	{
		CSprite * x = *it;
		
		if (O->getId() == x->getId())
		{
			std::cout << x->getX() << std::endl;

			objs.erase(objs.begin()+i);
			break;
		}
		i++;
	}
}

void CMiniMap::Draw()
{
	Camera.x = rect.x + *CameraX;
	Camera.y = rect.y + *CameraY;
	SDL_RenderCopy(renderer, image, &crop, &Camera);
	
	for (it = objs.begin(); it != objs.end(); ++it)
	{
		
		CSprite * x = *it;
		
	//	std::cout << x->getX() << std::endl;
		dot.x = x->getX() / 18 + 700;
		dot.y = x->getY() / 12 + 500;
		SDL_RenderCopy(renderer, blueDot, NULL, &dot);
	}
}