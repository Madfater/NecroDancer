#include "stdafx.h"
#include "item.h"

Item::Item(vector<string> file)
{
	img.LoadBitmapByString(file, RGB(0, 0, 0));
}

int Item::get_x()
{
	return x;
}

int Item::get_y()
{
	return y;
}

int Item::get_camera_x()
{
	return camera_x;
}

int Item::get_camera_y()
{
	return camera_y;
}

void Item::set_position(int _x, int _y, game_map* m)
{
	camera_x = _x - m->player->get_x() + 7;
	camera_y = _y - m->player->get_y() + 4;
	x = _x;
	y = _y;

	img.SetTopLeft(camera_x * 60 , camera_y * 60 - 10);
}

void Bomb::show()
{
}

void Chest::show()
{
}
