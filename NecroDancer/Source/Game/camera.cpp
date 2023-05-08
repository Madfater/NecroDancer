#include "stdafx.h"
#include "camera.h"

void camera::init(game_map* m)
{
	_map = m;

	for (int y = 0; y < 9; y++)
		for (int x = 0; x < 15; x++)
			camera_blocks[y][x].LoadBitmapByString(img_background);
}

void camera::show()
{
	if (_map->player->get_is_moving())
		_map->player->move_animation();

	for (int y = 0; y < 9; y++)
	{
		for (int x = 0; x < 15; x++)
		{
			if (_map->is_out_of_range(_map->player->get_map_x() - 7 + x, _map->player->get_map_y() - 4 + y))
				continue;

			switch (_map->get_block_info(_map->player->get_map_x() - 7 + x, _map->player->get_map_y() - 4 + y))
			{
				case _wall:
					camera_blocks[y][x].SetFrameIndexOfBitmap(_wall);
					camera_blocks[y][x].SetTopLeft(x * 60, (y * 60) - 38);
					break;
				default:
					camera_blocks[y][x].SetFrameIndexOfBitmap(_floor+(x+y)%2);
					camera_blocks[y][x].SetTopLeft(x * 60, y * 60);
					break;
			}
			camera_blocks[y][x].ShowBitmap();

			if (x == 7 && y == 4)
				_map->player->show();

			for (auto &i : _map->get_chr())
			{
				int cemera_x = i->get_map_x() - _map->player->get_map_x() + 7;
				int cemera_y = i->get_map_y() - _map->player->get_map_y() + 4;
				if (cemera_x == x && cemera_y == y)
				{
					i->set_show_position(cemera_x, cemera_y);
					i->show();
				}
			}
		}
	}
	
}