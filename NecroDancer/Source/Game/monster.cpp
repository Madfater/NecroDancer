#include "stdafx.h"
#include "monster.h"

Monster::Monster(int _HP,int _damage, vector<vector<string>> files, COLORREF color)
{
	full_HP = _HP;
	HP = _HP;
	damage = _damage;
	is_faceright = true;

	for (int i = 0; i < 2; i++)
	{
		img.push_back(game_framework::CMovingBitmap{});
		img[i].LoadBitmapByString(files[i],RGB(0,0,0));
		img[i].SetAnimation(100, false);
	}
}

bool Monster::get_faceright() 
{
	return is_faceright;
}

bool Monster::get_is_moving()
{
	return is_moving;
}
bool Monster::get_is_damaged()
{
	return is_damaged;
}

int Monster::get_hp()
{
	return HP;
}

int Monster::get_damage()
{
	return damage;
}

int Monster::get_x()
{
	return x;
}

int Monster::get_y()
{
	return y;
}

int Monster::get_camera_x()
{
	return camera_x;
}

int Monster::get_camera_y()
{
	return camera_y;
}

void Monster::set_position(int _x, int _y, int player_x, int player_y)
{
	camera_x = _x - player_x + 7;
	camera_y = _y - player_y + 4;
	x = _x;
	y = _y;

	for (int i = 0; i < 2; i++)
		img[i].SetTopLeft(camera_x * 60, camera_y * 60 - 10);
}

void Monster::set_faceright(bool _is_faceright)
{
	is_faceright = _is_faceright;
}

void Monster::set_is_moving()
{
	is_moving = true;
}

void Monster::lose_HP(int damage)
{
	HP -= damage;
	is_damaged = true;
	hearts.clear();
	for (int i = 0; i < HP; i++)
	{
		hearts.push_back(game_framework::CMovingBitmap{});
		hearts[i].LoadBitmapByString({ img_health_temp_full }, RGB(0, 0, 0));
	}
	for (int i = HP; i < full_HP; i++)
	{
		hearts.push_back(game_framework::CMovingBitmap{});
		hearts[i].LoadBitmapByString({ img_health_temp_empty }, RGB(0, 0, 0));
	}
	for (int i = 0; i < full_HP; i++) {
		hearts[i].SetTopLeft(camera_x * 60 + 30 * i - full_HP/2*30 +15, camera_y * 60 - 30);
	}
}

void Monster::move_animation()
{
	if (is_falling == false)
	{
		img[is_faceright].SetTopLeft(img[is_faceright].GetLeft(), img[is_faceright].GetTop() - 5);
		if (img[is_faceright].GetTop() <= camera_y * 60 - 40)
			is_falling = true;
	}
	else
	{
		img[is_faceright].SetTopLeft(img[is_faceright].GetLeft(), img[is_faceright].GetTop() + 5);
		if (img[is_faceright].GetTop() >= camera_y * 60 - 10)
		{
			is_falling = false;
			is_moving = false;
		}
	}
}

void Monster::show()
{			
	img[is_faceright].ShowBitmap();
}

void Monster::show_hp()
{
	for (int i = 0; i < full_HP; i++)
	{
		hearts[i].SetTopLeft(camera_x * 60 + 30 * i - full_HP / 2 * 30 + 15, camera_y * 60 - 30);
		hearts[i].ShowBitmap();
	}
}

int bat::move(game_map* map)
{
	return bat_step[(step_cnt++) % bat_step.size()] ;
}

int slime::move(game_map* map)
{
	return slime_step[(step_cnt++) % slime_step.size()] ;
}

void minotaur::set_position(int _x, int _y, int player_x, int player_y)
{
	camera_x = _x - player_x + 7;
	camera_y = _y - player_y + 4;
	x = _x;
	y = _y;

	for (int i = 0; i < 2; i++)
	{
		img[i].SetTopLeft(camera_x * 60-35, camera_y * 60 - 73);
		img_stunned[i].SetTopLeft(camera_x * 60 - 35, camera_y * 60 - 73);
		img_attacking[i].SetTopLeft(camera_x * 60 - 35, camera_y * 60 - 73);
	}
}

void minotaur::show()
{
	switch (Status)
	{
		case normal:
			img[is_faceright].ShowBitmap();
			break;
		case stunned:
			img_stunned[is_faceright].ShowBitmap();
			break;
		case rush:
			img_attacking[is_faceright].ShowBitmap();
			break;
		case _attack:
			img_attacking[is_faceright].ShowBitmap();
			break;
	}
}

int minotaur::move(game_map* map)
{
	int player_x = map->player->get_x();
	int player_y = map->player->get_y();

	if (Status == stunned)
	{
		cnt_stun++;
		if (cnt_stun == 3)
		{
			cnt_stun = 0;
			Status = normal;
		}
	}

	if (Status == _attack)
	{
		if (cnt_attack == 1)
		{
			cnt_attack = 0;
			Status = rush;
		}
		cnt_attack++;
	}

	if ((x == player_x|| y==player_y) && Status == normal)
	{
		Status = rush;
		if (abs(x - player_x) == 1 || abs(y - player_y) == 1)
			Status = _attack;

		if (player_y > y)
			direction = _down;
		else if (player_y < y)
			direction = _up;
		else if (player_x > x)
			direction = _right;
		else if (player_x < x)
			direction = _left;
	}

	

	int rush_info = map->get_block_info(x + direction_x[direction], y + direction_y[direction]);

	if(rush_info == _wall && Status == rush)
	{
		Status = stunned;
		map->block_change(x + direction_x[direction], y + direction_y[direction], _floor);
		return _stop;
	}
	else if (rush_info == _wall && Status == rush)
	{
		Status = stunned;
		return _stop;
	}
	else if (rush_info == _player && Status == rush)
	{
		Status = normal;
		return direction;
	}
		
	int res = 4;
	int max = INT_MAX;
	switch (Status)
	{
		case normal:
			for (int i = 0; i < 4; i++)
			{
				int dis_x = player_x - (x + direction_x[i]);
				int dis_y = player_y - (y + direction_y[i]);
				if (dis_x * dis_x + dis_y * dis_y < max)
				{
					max = dis_x * dis_x + dis_y * dis_y;
					res = i;
				}
			}
			return res;
			break;
		case rush:
			return direction;
			break;
		case stunned:
			return _stop;
			break;
		case _attack:
			return _stop;
			break;
	}
}

void minotaur::move_animation()
{
	if (is_falling == false)
	{
		img[is_faceright].SetTopLeft(img[is_faceright].GetLeft(), img[is_faceright].GetTop() - 5);
		if (img[is_faceright].GetTop() <= camera_y * 60 - 103)
			is_falling = true;
	}
	else
	{
		img[is_faceright].SetTopLeft(img[is_faceright].GetLeft(), img[is_faceright].GetTop() + 5);
		if (img[is_faceright].GetTop() >= camera_y * 60 - 73)
		{
			is_falling = false;
			is_moving = false;
		}
	}
}
