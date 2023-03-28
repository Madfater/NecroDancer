#include "stdafx.h"
#include "../Library/gameutil.h"
#include "tempo.h"
#include "img_path.h"

using namespace game_framework;

void tempo::init() 
{
	//CSpecialEffect::SetCurrentTime();
	for (int i = 0; i < 4; i++){// beat數量 右
		CMovingBitmap beat;
		beat.LoadBitmapByString({ img_beat }, RGB(0, 0, 0));
		beat.SetTopLeft(900 - i * 100, 400);
		beats_right.push_back(beat);
	}
	for (int i = 0; i < 4; i++){// beat數量 左
		CMovingBitmap beat;
		beat.LoadBitmapByString({ img_beat }, RGB(0, 0, 0));
		beat.SetTopLeft(i * 100, 400);
		beats_left.push_back(beat);
	}


	heart.LoadBitmapByString(img_heart, RGB(0, 0, 0));
	heart.SetTopLeft(400, 360);
	heart.SetAnimation(240, false);
	//beats = LoadBitmap(img_beat, RGB(0, 0, 0));

}
void tempo::beatspawn() 
{
	
}
bool tempo::is_touched()
{
	for (int i = 0; i < 4; i++) {
		if (beats_left[i].GetLeft() > 380) {
			_is_touched = true;
		}
	}
	return _is_touched;
}

void tempo::show() 
{	
	for (int i = 0; i < 4; i++) {
		beats_left[i].SetTopLeft(beats_left[i].GetLeft() + 2, 400);//beat速度
		if (beats_left[i].GetLeft() > 400) {
			beats_left[i].SetTopLeft(0, 400);
			_is_jumped = false;
		}
	}
	for (int i = 0; i < 4; i++) {
		beats_right[i].SetTopLeft(beats_right[i].GetLeft() - 2, 400);//beat速度
		if (beats_right[i].GetLeft() < 500) {
			beats_right[i].SetTopLeft(900, 400);
		}
	}
	for (int i = 0; i < 4; i++) {
		beats_left[i].ShowBitmap();
		beats_right[i].ShowBitmap();
	}
	heart.ShowBitmap();

}