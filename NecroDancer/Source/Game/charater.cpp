#pragma once

#include "stdafx.h"
#include "../Library/gameutil.h"
#include "character.h"

character::character(int _HP, int _x, int _y,vector<vector<string>> files, COLORREF color)
{
	HP = _HP;
	for (int i = 0; i < 2; i++)
	{
		img[i].LoadBitmapByString(files[i], color);
		img[i].SetTopLeft(_x * 60, _y * 60 - 30);
		img[i].SetAnimation(120, false);
	}
	is_faceright = true;
	x = _x;
	y = _y;
}

int character::get_x()
{
	return x;
}

int character::get_y()
{
	return y;
}
bool character::get_faceright() {
	return is_faceright;
}
void character::set_faceright(bool _is_faceright) {
	is_faceright = _is_faceright;
}

void character::show()
{	
	img[is_faceright].ShowBitmap();
}

bool main_character::move()
{
	if (is_falling == false) 
	{
		img[is_faceright].SetTopLeft(img[is_faceright].GetLeft(), img[is_faceright].GetTop() - 8); //±±¨î¤W¤É³t«×
		if (img[is_faceright].GetTop() <= y * 60 - 60) //¸õÅD°ª«×
			is_falling = true;
	}
	else 
	{
		img[is_faceright].SetTopLeft(img[is_faceright].GetLeft(), img[is_faceright].GetTop() + 8); //±±¨î¤U­°³t«×
		if (img[is_faceright].GetTop() >= y * 60 - 30)//¤U­°°ª«×
		{
			is_falling = false;
			return false;
		}
	}
	return true;
}