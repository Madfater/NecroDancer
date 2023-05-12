#include "stdafx.h"
#include "player.h"

Player::Player(int _x, int _y)
{
	HP = 3;
	weapon_id = 0;
	
	
	
	for (int i = 0; i < 2; i++)
	{
		img.push_back(game_framework::CMovingBitmap{});
		img[i].LoadBitmapByString(img_player[i], RGB(0, 0, 0));
		img[i].SetTopLeft(7 * 60, 4 * 60 - 10);
		img[i].SetAnimation(100, false);
	}
	x = _x;
	y = _y;
	for (int i = 0; i < 4; i++) {
		atk_img.push_back(game_framework::CMovingBitmap{});
		atk_img[i].LoadBitmapByString(img_attack_dagger[i], RGB(0, 0, 0));
		atk_img[i].SetAnimation(100, false);
	}
	atk_img[0].SetTopLeft(6 * 60, 4 * 60 - 10); //left
	atk_img[1].SetTopLeft(7 * 60, 3 * 60 - 10); //up
	atk_img[2].SetTopLeft(8 * 60, 4 * 60 - 10); //right
	atk_img[3].SetTopLeft(7 * 60, 5 * 60 - 10); //down	
}

int Player::get_is_moving()
{
	return is_moving;
}

int Player::get_is_attacking()
{
	return is_attacking;
}

int Player::get_hp()
{
	return HP;
}

int Player::get_weapon_id()
{
	return weapon_id;
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

void Player::set_position(int _x, int _y)
{
	x = _x;
	y = _y;
}

void Player::set_faceright(bool is)
{
	is_faceright = is;
}

void Player::attack(Monster* chr,int direaction)
{
	attack_direction = direaction;
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

void Player::attack_animation() {
	if (attack_counter < 10) {
		atk_img[attack_direction].ShowBitmap();
		attack_counter = attack_counter + 1;
	}
	else {
		is_attacking = false;
		attack_counter = 0;
	}
}

void Player::lose_HP(int hp)
{
	HP -= hp;
}

void Player::show()
{
	img[is_faceright].ShowBitmap();
}
