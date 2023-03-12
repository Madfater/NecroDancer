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

bool main_character::move()
{
	if (is_falling == false) 
	{
		img.SetTopLeft(img.GetLeft(), img.GetTop() - 8); //����W�ɳt��
		if (img.GetTop() <= 180) //���D����
			is_falling = true;;
	}
	else 
	{
		img.SetTopLeft(img.GetLeft(), img.GetTop() + 8); //����U���t��
		if (img.GetTop() >= 210)//�U������
		{
			is_falling = false;
			return false;
		}
	}
	return true;
}