#include "stdafx.h"
#include "../Library/gameutil.h"
#include "tempo.h"
#include "img_path.h"

#define interval_right 20
#define interval_left 380
#define left_beat_start_pos 0
#define left_beat_end_pos 400
#define right_beat_start_pos 900
#define right_beat_end_pos 500
#define beat_y 400
#define beats_space 100
#define beats_num 4
#define beat_speed 2

using namespace game_framework;

void tempo::init() 
{
	//CSpecialEffect::SetCurrentTime();
	for (int i = 0; i < beats_num; i++){// beat數量 右
		CMovingBitmap beat;
		beat.LoadBitmapByString({ img_beat }, RGB(0, 0, 0));
		beat.SetTopLeft(right_beat_start_pos - i * beats_space, beat_y);
		beats_right.push_back(beat);
	}
	for (int i = 0; i < beats_num; i++){// beat
		CMovingBitmap beat;
		beat.LoadBitmapByString({ img_beat }, RGB(0, 0, 0));
		beat.SetTopLeft(left_beat_start_pos+i * beats_space, beat_y);
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
bool tempo::if_shouldjump()
{
	for (int i = 0; i < beats_num; i++) {
		if (beats_left[i].GetLeft() > interval_left || beats_left[i].GetLeft() < interval_right) {
			if (_has_moved) {
				return false;
			}
			_has_moved = true;
			return true;
		}
	}
	return false;
}

bool tempo::if_afterjump()
{
	bool jump = false;
	for (int i = 0; i < beats_num; i++) {
		if (beats_left[i].GetLeft() > interval_left || beats_left[i].GetLeft() < interval_right) 
		{
			jump = true;
		}
	}
	if (jump == true && _has_moved == false)
		return true;
	else
		return false;
}

void tempo::show() 
{	
	for (int i = 0; i < beats_num; i++) {
		beats_left[i].SetTopLeft(beats_left[i].GetLeft() + beat_speed, beat_y);//beat速度
		if (beats_left[i].GetLeft() > left_beat_end_pos) {
			beats_left[i].SetTopLeft(left_beat_start_pos, beat_y);
		}
		if (beats_left[i].GetLeft() > interval_right && beats_left[i].GetLeft() < interval_right+10) {
			_has_moved = false;
		}
	}
	for (int i = 0; i < beats_num; i++) {
		beats_right[i].SetTopLeft(beats_right[i].GetLeft() - beat_speed, beat_y);//beat速度
		if (beats_right[i].GetLeft() < right_beat_end_pos) {
			beats_right[i].SetTopLeft(right_beat_start_pos, beat_y);
		}
	}
	for (int i = 0; i < beats_num; i++) {
		beats_left[i].ShowBitmap();
		beats_right[i].ShowBitmap();
	}
	heart.ShowBitmap();

}