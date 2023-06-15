#include "stdafx.h"
#include "../Library/gameutil.h"
#include "interface.h"
#include "img_path.h"

#define weapon_icon_pos 0
#define weapon_icon_height 20
#define shovel_icon_pos 75
#define shovel_icon_height 20
#define heart_height 20
#define heart_space 60
#define heart_pos 700
#define heart_num 3

using namespace game_framework;

void _interface::init()
{
	slot_attack.LoadBitmapByString({img_slot_attack },RGB(0,0,0));
	slot_attack.SetTopLeft(weapon_icon_pos, weapon_icon_height);

	slot_shovel.LoadBitmapByString({ img_slot_shovel }, RGB(0, 0, 0));
	slot_shovel.SetTopLeft(shovel_icon_pos, shovel_icon_height);
	for (int i = 0; i < 6; i++)
	{
		CMovingBitmap weapon;
		weapon.LoadBitmapByString({ img_weapon_icon[i] }, RGB(0, 0, 0));
		weapon.SetTopLeft(weapon_icon_pos+7,weapon_icon_height+16);
		weapon_icon.push_back(weapon);
	}

	shovel_icon.LoadBitmapByString({ img_shovel[0] }, RGB(0, 0, 0));
	shovel_icon.SetTopLeft(shovel_icon_pos+7, shovel_icon_height+16);
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
void _interface::set_weapon_id(int id) {
	weapon_id = id;
}
void _interface::load_hp(int hp) {

	lifepoint = hp;
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
	for (int i = 0; i < heart_num; i++) 
	{
		hearts[i].ShowBitmap();
	}
	slot_attack.ShowBitmap();
	slot_shovel.ShowBitmap();
	weapon_icon[weapon_id].ShowBitmap();
	shovel_icon.ShowBitmap();
}