#include "stdafx.h"
#include "Unit.h"



CUnit::CUnit(float phealth, SDL_Renderer* pRenderer, std::string filename, int x, int y, int w, int h,int pamount_frame_x, int pamount_frame_y, float *pCameraX, float *pCameraY) 
: CGameObject(phealth, pRenderer,filename,x,y,w,h,pCameraX,pCameraY)
{
	move = false;
	move_D = false;
	move_R = false;
	move_L = false;
	move_U = false;

	timeCheck = SDL_GetTicks();

	amount_frame_x = pamount_frame_x;
	amount_frame_y = pamount_frame_y;

	current_frame = 0;
	

}



void CUnit::playAnimation(int endFrame, float speed)
{
	std::cout << current_frame << endFrame << std::endl;
	if (animationDelay + speed < SDL_GetTicks())
	{
		if (endFrame <= current_frame)
		{
			current_frame = 0;
		}
		else
		{
			current_frame++;
		}

		crop.x = current_frame * (img_width / amount_frame_x);
		crop.y = row * (img_height / amount_frame_y);

		crop.w = img_width / amount_frame_x;
		crop.h = img_height / amount_frame_y;

		animationDelay = SDL_GetTicks();
	}


}

void CUnit::keyControl(CSDL_Setup* csdl_setup,CCamera* camera, int endFrame, float speed)
{
	switch (csdl_setup->getMainEvent()->type)
	{
	case SDL_KEYDOWN:
	{
						switch (csdl_setup->getMainEvent()->key.keysym.sym)
						{
						case SDLK_a:
							move_L = true;
							row = 1;
							break;
						case SDLK_s:
							move_D = true;
							row = 2;
							break;
						case SDLK_d:
							move_R = true;
							row = 0;
							break;
						case SDLK_w:
							move_U = true;
							row = 3;
							break;
						}
						break;
	}
	case SDL_KEYUP:
	{
					  switch (csdl_setup->getMainEvent()->key.keysym.sym)
					  {
					  case SDLK_a:
						  move = false;
						  move_L = false;
						  break;
					  case SDLK_s:

						  move = false;
						  move_D = false;
						  break;
					  case SDLK_d:

						  move = false;
						  move_R = false;
						  break;
					  case SDLK_w:

						  move = false;
						  move_U = false;
						  break;
					  }
					  break;
	}
	default:
		break;
	}

	if (timeCheck + 5 < SDL_GetTicks())
	{
		//diag moves twice as fast
		if (move_R && move_U)
		{
			move = true;

			setX(X_pos + 1);
			setY(Y_pos - 1);

		}
		else if (move_R && move_D)
		{
			move = true;

			setX(X_pos + 1);
			setY(Y_pos + 1);

		}
		else if (move_L && move_U)
		{

			move = true;
			setX(X_pos - 1);
			setY(Y_pos -1);

		}
		else if (move_L && move_D)
		{
			move = true;
			setX(X_pos - 1);
			setY(Y_pos + 1);

		}

		else if (move_R && !move_L && !move_U && !move_D)
		{
			move = true;
			setX(X_pos + 2);

		}
		else if (move_L && !move_R && !move_U && !move_D)
		{
			move = true;
			setX(X_pos - 2);

		}
		else if (move_D && !move_L && !move_U && !move_R)
		{
			move = true;
			setY(Y_pos + 2);

		}
		else if (move_U && !move_L && !move_R && !move_D)
		{
			move = true;
			setY(Y_pos - 2);

		}
		timeCheck = SDL_GetTicks();
	}
	if (move)
	{
		playAnimation(endFrame,speed);
		camera->setX(-X_pos);
		camera->setY(-Y_pos);

	}
}

