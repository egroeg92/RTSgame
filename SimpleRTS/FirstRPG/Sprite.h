#pragma once
class CSprite
{
public:
	CSprite(SDL_Renderer* pRenderer, std::string filename, int x, int y, int w, int h, float *CameraX, float *CameraY);
	~CSprite();

	void Draw();

	void setX(float x);
	void setY(float y);
	void setPosition(float x, float y);

	float getX();
	float getY();

	int getWidth();
	int getHeight();

	void setWidth(int x);
	void setHeight(int x);

	void SetOrigin(float x, float y);

	void setAnimation(int pX, int pY);
	void playAnimation(int beginFrame, int endFrame, int row, float speed);
	
	
protected:

	SDL_Rect Camera;
	float *CameraX;
	float *CameraY;

	float Origin_X;
	float Origin_Y;
	float X_pos;
	float Y_pos;
	SDL_Texture* image;
	SDL_Rect rect;

	SDL_Rect crop;
	int img_width;
	int img_height;

	SDL_Renderer* renderer;



};

