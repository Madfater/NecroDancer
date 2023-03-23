#include "stdafx.h"
#include "camera.h"
#include "../Library/gameutil.h"
#include "game_map.h"

#define _wall 1
#define _floor 0

void camera::init(game_map* m)
{
	_map = m;
	for (int y = 0; y < 9; y++)
		for (int x = 0; x < 15; x++)
			camera_blocks[y][x].LoadBitmapByString(img_background);
}

void camera::show()
{
	int player_x = _map->characters[0]->get_x();
	int player_y = _map->characters[0]->get_y();
	for (int y = 0; y < 9; y++)
	{
		for (int x = 0; x < 15; x++)
		{
			if (_map->is_out_of_range(player_x - 7 + x, player_y - 4 + y))
				continue;

			switch (_map->get_block_info(player_x - 7 + x, player_y - 4 + y)->type)
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
			{
				_map->characters[0]->show();
			}

			for (int i = 1; i < _map->characters.size(); i++)
				if (_map->characters[i]->get_x() == player_x - 7 + x && _map->characters[i]->get_y() == player_y - 4 + y)
				{
					_map->characters[i]->set_position_camera(x, y);
					_map->characters[i]->show();
				}
		}
	}
	for (int i = 0; i < _map->characters.size(); i++)
	{
		if (_map->characters[i]->get_is_moving())
			_map->characters[i]->move();
	}
}