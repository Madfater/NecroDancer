#include "stdafx.h"
#include "player.h"

Player::Player(int _x, int _y)
{
	HP = 6;
	weapon_id = 0;
	x = _x;
	y = _y;
	
	for (int i = 0; i < 2; i++)
	{
		img.push_back(game_framework::CMovingBitmap{});
		img[i].LoadBitmapByString(img_player[i], RGB(0, 0, 0));
		img[i].SetTopLeft(7 * 60, 4 * 60 - 10);
		img[i].SetAnimation(100, false);
		//img[i].ToggleAnimation();
	}
	for (int i = 0; i < 3; i++) {
		vector<game_framework::CMovingBitmap> temp;
		_atk_img.push_back(temp);
		for (int j = 0; j < 4; j++)
		{
			_atk_img[i].push_back(game_framework::CMovingBitmap{});
			_atk_img[i][j].LoadBitmapByString(img_weapon[i][j], RGB(0, 0, 0));
			_atk_img[i][j].SetAnimation(100, false);
		}
	}
	_atk_img[dagger][0].SetTopLeft(6 * 60, 4 * 60 - 10); //left player 7,4
	_atk_img[dagger][1].SetTopLeft(7 * 60, 3 * 60 - 10); //up
	_atk_img[dagger][2].SetTopLeft(8 * 60, 4 * 60 - 10); //right
	_atk_img[dagger][3].SetTopLeft(7 * 60, 5 * 60 - 10); //down	
		
	_atk_img[longsword][0].SetTopLeft(6 * 60, 3 * 60 - 10); //left
	_atk_img[longsword][1].SetTopLeft(6 * 60, 3 * 60 - 10); //up
	_atk_img[longsword][2].SetTopLeft(8 * 60, 3 * 60 - 10); //right
	_atk_img[longsword][3].SetTopLeft(6 * 60, 5 * 60 - 10); //down

	_atk_img[spear][0].SetTopLeft(5 * 60, 4 * 60 - 10); //left
	_atk_img[spear][1].SetTopLeft(7 * 60, 2 * 60 - 10); //up
	_atk_img[spear][2].SetTopLeft(8 * 60, 4 * 60 - 10); //right
	_atk_img[spear][3].SetTopLeft(7 * 60, 5 * 60 - 10); //down

	/*for (int i = 0; i < 4; i++) 
	{
		atk_img.push_back(game_framework::CMovingBitmap{});
		atk_img[i].LoadBitmapByString(img_attack_dagger[i], RGB(0, 0, 0));
		atk_img[i].SetAnimation(100, false);
	}
	atk_img[0].SetTopLeft(6 * 60, 4 * 60 - 10); //left
	atk_img[1].SetTopLeft(7 * 60, 3 * 60 - 10); //up
	atk_img[2].SetTopLeft(8 * 60, 4 * 60 - 10); //right
	atk_img[3].SetTopLeft(7 * 60, 5 * 60 - 10); //down	
	*/
	for (int i = 0; i < 4; i++) 
	{
		vector<game_framework::CMovingBitmap> temp;
		shovel_img.push_back(temp);
		for (int j = 0; j < 2; j++) 
		{
			shovel_img[i].push_back(game_framework::CMovingBitmap{});
			shovel_img[i][j].LoadBitmapByString({ img_shovel[j] }, RGB(0, 0, 0));
		}
		
	}
	for (int i = 0; i < 2; i++) {
		shovel_img[0][i].SetTopLeft(6 * 60, 3 * 60 - 30); //left
		shovel_img[1][i].SetTopLeft(7 * 60, 3 * 60 - 30); //up
		shovel_img[2][i].SetTopLeft(8 * 60, 3 * 60 - 30); //right
		shovel_img[3][i].SetTopLeft(7 * 60, 5 * 60 - 30); //down
	}

	being_atk_img.LoadBitmapByString(img_monster_attack, RGB(0, 0, 0));
	being_atk_img.SetAnimation(100, false);
	being_atk_img.SetTopLeft(7 * 60 - 4, 4 * 60 - 10);
}

int Player::get_is_moving()
{
	return is_moving;
}

int Player::get_be_attacking() {
	return be_attacking;
}

int Player::get_is_attacking()
{
	return is_attacking;
}

int Player::get_is_digging()
{
	return is_digging;
}

int Player::get_hp()
{
	return HP;
}

int Player::get_weapon_id()
{
	return weapon_id;
}

int Player::get_shovel_id()
{
	return shovel_id;
}
int Player::get_x()
{
	return x;
}

int Player::get_y()
{
	return y;
}

void Player::set_moving()
{
	is_moving = true;
}
void Player::set_weapon_id(int id)
{
	weapon_id = id;
}
void Player::set_position(int _x, int _y)
{
	x = _x;
	y = _y;
}

void Player::set_faceright(bool is)
{
	is_faceright = is;
}

void Player::dig(int direaction)
{
	_direction = direaction;
	is_digging = true;
}

void Player::attack(Monster* chr,int direaction)
{
	_direction = direaction;
	chr->lose_HP(weapon_damage[weapon_id]);
	is_attacking = true;
}

void Player::move_animation()
{
	if (is_falling == false)
	{
		img[is_faceright].SetTopLeft(img[is_faceright].GetLeft(), img[is_faceright].GetTop() - 5);
		if (img[is_faceright].GetTop() <= 4 * 60 - 40)
			is_falling = true;
	}
	else
	{
		img[is_faceright].SetTopLeft(img[is_faceright].GetLeft(), img[is_faceright].GetTop() + 5);
		if (img[is_faceright].GetTop() >= 4 * 60 - 10)
		{
			is_falling = false;
			is_moving = false;
		}
	}
}

void Player::attack_animation()
{
	if (attack_counter < 10) 
	{
		_atk_img[weapon_id][_direction].ShowBitmap();
		attack_counter++;
	}
	else
	{
		is_attacking = false;
		attack_counter = 0;
	}
}

void Player::be_attack_animation() {
	if (be_attack_counter < 20) {
		being_atk_img.ShowBitmap();
		be_attack_counter++;
	}
	else {
		be_attacking = false;
		be_attack_counter = 0;
	}
	
}

void Player::dig_animation()
{
	if (dig_counter < 10) {
		shovel_img[_direction][is_faceright].ShowBitmap();
		dig_counter++;
	}
	else {
		is_digging = false;
		dig_counter = 0;
	}
}
void Player::lose_HP(int hp)
{
	HP -= hp;
	be_attacking = true;
}

void Player::show()
{
	img[is_faceright].ShowBitmap();
}

