#pragma once

#include "stdafx.h"
#include "../Library/gameutil.h"
#include "img_path.h"
#include <vector>
#include <string>

#include "character.h"

character::character(int _HP, int _x, int _y, vector<string> files, COLORREF color = CLR_INVALID)
{
	HP = _HP;
	x = _x;
	y = _y;
	img.LoadBitmapByString(files,color);
}

int character::get_x()
{
	return x;
}

int character::get_y()
{
	return y;
}

void character::show()
{
	img.ShowBitmap();
}

character::~character()
{
	img.UnshowBitmap();
}

void main_character::move()
{
	if (is_jumping)
	{
		if (is_falling)
		{
			img.SetTopLeft(img.GetLeft(), img.GetTop() + 5); //����U���t��
			if (img.GetTop() == y) //�U������
			{ 
				is_falling = false;
				is_jumping = false;
			}
		}
		if (is_falling == 1) 
		{
			img.SetTopLeft(img.GetLeft(), img.GetTop() - 5); //����W�ɳt��
			if (img.GetTop() <= y - 30) //�W�ɰ���
				is_falling = 1;
		}
	}
}