#include "stdafx.h"
#include "../Library/gameutil.h"
#include "interface.h"
#include "img_path.h"

#define heart_height 20
#define heart_space 60
#define heart_pos 700
#define heart_num 3

using namespace game_framework;

void _interface::init()
{
	lifepoint = 3;
	full=lifepoint / 2;
	empty = (10 - lifepoint) / 2;
	int num = 0;
	for (int i = 0; i < full; i++)
	{
		CMovingBitmap heart;
		heart.LoadBitmapByString({ img_health_full }, RGB(0, 0, 0));
		heart.SetTopLeft(heart_pos+heart_space * num, heart_height);
		hearts.push_back(heart);
		num++;
	}
	if (lifepoint % 2 == 1) {
		CMovingBitmap heart;
		heart.LoadBitmapByString({ img_health_half }, RGB(0, 0, 0));
		heart.SetTopLeft(heart_pos+heart_space * num, heart_height);
		hearts.push_back(heart);
		num++;
	}
	for (int i = 0; i < empty; i++)
	{
		CMovingBitmap heart;
		heart.LoadBitmapByString({ img_health_empty }, RGB(0, 0, 0));
		heart.SetTopLeft(heart_pos+heart_space * num, heart_height);
		hearts.push_back(heart);
		num++;
	}


	
	
	



}
void _interface::lose_hp() {
	lifepoint = lifepoint - 1;
	hearts.clear();

	full = lifepoint / 2;
	empty = (10 - lifepoint) / 2;
	int num = 0;
	for (int i = 0; i < full; i++)
	{
		CMovingBitmap heart;
		heart.LoadBitmapByString({ img_health_full }, RGB(0, 0, 0));
		heart.SetTopLeft(heart_pos + heart_space * num, heart_height);
		hearts.push_back(heart);
		num++;
	}
	if (lifepoint % 2 == 1) {
		CMovingBitmap heart;
		heart.LoadBitmapByString({ img_health_half }, RGB(0, 0, 0));
		heart.SetTopLeft(heart_pos + heart_space * num, heart_height);
		hearts.push_back(heart);
		num++;
	}
	for (int i = 0; i < empty; i++)
	{
		CMovingBitmap heart;
		heart.LoadBitmapByString({ img_health_empty }, RGB(0, 0, 0));
		heart.SetTopLeft(heart_pos + heart_space * num, heart_height);
		hearts.push_back(heart);
		num++;
	}
}
void _interface::show()
{

	for (int i = 0; i < heart_num; i++) {
		hearts[i].ShowBitmap();
	}


}