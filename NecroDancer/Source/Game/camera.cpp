#include "stdafx.h"
#include "camera.h"

void camera::init(game_map* m)
{
	_map = m;

	for (int y = 0; y < 9; y++)
	{
		for (int x = 0; x < 15; x++)
			camera_blocks_img[y][x].LoadBitmapByString(img_background,RGB(0,0,0));
		camera_blocks.push_back({vector<int>(15,0)});
	}
			
}

//Bresenham's line algorithm
bool hasObstacle(int x, int y, vector<vector<int>> blocks)
{
	int player_x = 7;
	int player_y = 4;
	int deltaX = abs(player_x - x);
	int deltaY = abs(player_y - y);
	int error = deltaX - deltaY;
	int stepX = player_x< x ? 1 : -1;
	int stepY = player_y < y ? 1 : -1;

	while (player_x != x || player_y != y)
	{
		//obstacle
		if (blocks[player_y][player_x] == _door_hor || 
			blocks[player_y][player_x] == _door_ver || 
			blocks[player_y][player_x] == _wall || 
			blocks[player_y][player_x] ==_border ||
			blocks[player_y][player_x] == _empty)
			return true;

		int error2 = error * 2;

		if (error2 > -deltaY) {
			error -= deltaY;
			player_x += stepX;
		}
		if (error2 < deltaX) {
			error += deltaX;
			player_y += stepY;
		}
	}

	return false;
}

void camera::updateVisibility()
{
	vector<vector<bool>> visible(9, vector<bool>(15, false));

	for (int y = 0; y < 9; y++)
		for (int x = 0; x < 15; x++)
			visible[y][x] = !hasObstacle(x, y, camera_blocks);

	for (int y = 0; y < 9; y++)
		for (int x = 0; x < 15; x++)
			if(!visible[y][x])
				camera_blocks[y][x] = _empty;

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
			if (_map->is_out_of_range(_map->player->get_x() - 7 + x, _map->player->get_y() - 4 + y))
			{
				camera_blocks[y][x] = _empty;
				continue;
			}

			camera_blocks[y][x] = _map->get_block_info(_map->player->get_x() - 7 + x, _map->player->get_y() - 4 + y);
		}
	}

	updateVisibility();

	for (int y = 0; y < 9; y++)
	{
		for (int x = 0; x < 15; x++)
		{
			camera_blocks_img[y][x].SetTopLeft(x * 60, (y * 60) - 38);
			switch (camera_blocks[y][x])
			{
				case _empty:
					break;
				case _border:
					camera_blocks_img[y][x].SetFrameIndexOfBitmap(3);
					break;
				case _door_hor:
					camera_blocks_img[y][x].SetFrameIndexOfBitmap(5);
					break;
				case _door_ver:
					camera_blocks_img[y][x].SetFrameIndexOfBitmap(6);
					break;
				case _wall:
					camera_blocks_img[y][x].SetFrameIndexOfBitmap(_wall);
					break;
				case _stair:
					camera_blocks_img[y][x].SetFrameIndexOfBitmap(4);
					camera_blocks_img[y][x].SetTopLeft(x * 60, y * 60);
					break;
				case _chest:
					camera_blocks_img[y][x].SetFrameIndexOfBitmap(7);
					camera_blocks_img[y][x].SetTopLeft(x * 60, y * 60);
					break;
				default:
					camera_blocks_img[y][x].SetFrameIndexOfBitmap(_floor+(x+y)%2);
					camera_blocks_img[y][x].SetTopLeft(x * 60, y * 60);
					break;
			}

			if(camera_blocks[y][x]!=_empty)
				camera_blocks_img[y][x].ShowBitmap();

			if (x == 7 && y == 4)
				_map->player->show();
		}

		for (int x = 0; x < 15; x++)
			for (auto &i : _map->get_chr())
				if (i->get_camera_x() == x && i->get_camera_y() == y && camera_blocks[y][x] != _empty && i->get_hp()>0)
				{
					i->show();
					if (i->get_is_damaged())
						i->show_hp();
				}

	}

	for (auto &i : _map->get_chr())
		if (i->get_is_damaged() && i->get_hp()>0)
			i->show_hp();

	if (_map->player->get_is_attacking())
		_map->player->attack_animation();

	if (_map->player->get_is_digging())
		_map->player->dig_animation();

	
	if (_map->player->get_be_attacking())
		_map->player->be_attack_animation();
	
}