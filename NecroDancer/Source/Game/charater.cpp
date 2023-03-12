#pragma once

#include "stdafx.h"
#include "../Library/gameutil.h"
#include "character.h"

character::character(int _HP, int _x, int _y, vector<string> files)
{
	HP = _HP;
	img.LoadBitmapByString(files, CLR_INVALID);
	img.SetTopLeft(_x, _y);
}

character::character(int _HP, int _x, int _y,vector<string> files, COLORREF color)
{
	HP = _HP;
	img.LoadBitmapByString(files,color);
	img.SetTopLeft(_x, _y);
	img.SetAnimation(120, false);
}

int character::get_x()
{
	return img.GetLeft();
}

int character::get_y()
{
	return img.GetTop();
}

void character::show()
{
	img.ShowBitmap();
}

character::~character()
{

}

void main_character::move()
{
	if (is_falling)
	{
		img.SetTopLeft(img.GetLeft(), img.GetTop() + 5); //控制下降速度
		if (img.GetTop() == y) //下降停止高度
				is_falling = false;
	}
	else
	{
		img.SetTopLeft(img.GetLeft(), img.GetTop() - 5); //控制上升速度
		if (img.GetTop() == y - 30) //上升高度
			is_falling = true;
	}
}