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
	
	for (auto &i : _map->get_chr())
		if (i->get_is_moving())
			i->move_animation();

	for (int y = 0; y < 9; y++)
	{
		for (int x = 0; x < 15; x++)
		{
			if (_map->is_out_of_range(_map->player->get_x() - 7 + x, _map->player->get_y()- 4 + y))
				continue;

			switch (_map->get_block_info(_map->player->get_x()- 7 + x, _map->player->get_y() - 4 + y))
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
				if (i->get_camera_x() == x && i->get_camera_y() == y) 
				{
					i->show();
					if (i->get_is_damaged())
						i->show_hp();
				}
		
		}
	}

	if (_map->player->get_is_attacking())
		_map->player->attack_animation();
	if (_map->player->get_is_digging())
		_map->player->dig_animation();

	for (auto &i : _map->get_chr())
		if (i->get_is_damaged())
			i->show_hp();
	
	if (_map->player->get_be_attacking())
		_map->player->be_attack_animation();
	
}