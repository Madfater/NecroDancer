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
		i->set_position_camera(7 - (_map->characters[0]->get_x() - i->get_x()), 4 - (_map->characters[0]->get_y() - i->get_y()));

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

			for (auto &i : _map->characters)
				if (i->get_x() == player_x - 7 + x && i->get_y() == player_y - 4 + y)
					i->show();
		}
	}
	for (auto &i : _map->characters)
	{
		if (i->get_is_moving())
			i->move();
	}
}