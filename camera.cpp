#define _wall 1
#define _floor 0

void camera::init()
{
	camera_x = _map.get_start_x();
	camera_y = _map.get_start_y();

	for (int y = 0; y < 9; y++)
		for (int x = 0; x < 15; x++)
			camera[y][x].LoadBitmapByString(img_background);
}

void camera::show()
{
	for (int y = 0; y < 9; y++)
	{
		for (int x = 0; x < 15; x++)
		{
			if (_map.is_out_of_range(camera_x - 7 + x, camera_y - 4 + y))
				continue;

			switch (_map.get_block_info(camera_x - 7 + x, camera_y - 4 + y)->type)
			{
			case _wall:
				camera[y][x].SetFrameIndexOfBitmap(_wall);
				camera[y][x].SetTopLeft(x * 60, (y * 60) - 38);
				break;
			case _floor:
				camera[y][x].SetFrameIndexOfBitmap(_floor);
				camera[y][x].SetTopLeft(x * 60, y * 60);
				break;
			default:
				break;
			}
			camera[y][x].ShowBitmap();

			if (player->get_x() == x && player->get_y() == y)
				player->show();

			if (_map.get_block_info(camera_x - 7 + x, camera_y - 4 + y)->monster != NULL)
			{
				character* m = _map.get_block_info(camera_x - 7 + x, camera_y - 4 + y)->monster;
				((monster*)m)->set_position(x, y);
				((monster*)m)->show();
			}
		}
	}

	if (is_moving)
		is_moving = player->move();
}

void camera::keydown(UINT nChar)
{
	is_moving = true;
	int direction_x[4] = { -1,0,1,0 };//left->up->right->down
	int direction_y[4] = { 0,-1,0,1 };
	int direction = nChar - 37;
	try
	{
		if (direction == 0)
			player->set_faceright(false);
		else if (direction == 2)
			player->set_faceright(true);

		if (_map.get_block_info(camera_x + direction_x[direction], camera_y + direction_y[direction])->type == _wall ||
			_map.get_block_info(camera_x + direction_x[direction], camera_y + direction_y[direction])->monster != NULL)
			is_moving = false;
		else
		{
			camera_x += direction_x[direction];
			camera_y += direction_y[direction];
		}
	}
	catch (exception &e)
	{

	}

}