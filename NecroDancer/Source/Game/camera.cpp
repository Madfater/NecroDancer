#include "stdafx.h"
#include "camera.h"
#include "../Library/gameutil.h"
#include "game_map.h"

#define _wall 1
#define _floor 0

void camera::init(game_map* m)
{
	_map = m;

	for (auto &i : _map->characters)
		i->set_camera_position(7 - (_map->player->get_map_x() - i->get_map_x()), 4 - (_map->player->get_map_y() - i->get_map_y()));

	for (int y = 0; y < 9; y++)
		for (int x = 0; x < 15; x++)
			camera_blocks[y][x].LoadBitmapByString(img_background);
}

void camera::show()
{
	for (int y = 0; y < 9; y++)
	{
		for (int x = 0; x < 15; x++)
		{
			if (_map->is_out_of_range(_map->player->get_map_x() - 7 + x, _map->player->get_map_y() - 4 + y))
				continue;

			switch (_map->get_block_info(_map->player->get_map_x() - 7 + x, _map->player->get_map_y() - 4 + y)->type)
			{
				case _wall:
					camera_blocks[y][x].SetFrameIndexOfBitmap(_wall);
					camera_blocks[y][x].SetTopLeft(x * 60, (y * 60) - 38);
					break;
				case _floor:
					camera_blocks[y][x].SetFrameIndexOfBitmap(_floor);
					camera_blocks[y][x].SetTopLeft(x * 60, y * 60);
					break;
				default:
					break;
			}
			camera_blocks[y][x].ShowBitmap();

			if (x == 7 && y == 4)
				_map->player->show();

			for (auto &i : _map->characters)
				if (i->get_camera_x() == x && i->get_camera_y()==y)
					i->show();
		}
	}
	if (_map->player->get_is_moving())
		_map->player->move_animation();

	for (auto &i : _map->characters)
		if (i->get_is_moving())
			i->move_animation();
}