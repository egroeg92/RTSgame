#pragma once
#include "Sprite.h"
#include <vector>

class CMiniMap : public CSprite
{
public:
	CMiniMap(SDL_Renderer* pRenderer, std::string filename, int x, int y, int w, int h, float *pCameraX, float *pCameraY);
	void addObj(CSprite * O);
	void removeObj(CSprite * O);
	void Draw();
private:
	std::vector<CSprite*> objs;
	std::vector<CSprite*>::iterator it;
	SDL_Texture* blueDot;

	SDL_Rect dot;
};

