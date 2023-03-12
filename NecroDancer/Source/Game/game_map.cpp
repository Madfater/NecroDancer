#pragma once

#include "stdafx.h"
#include "../Library/gameutil.h"
#include "img_path.h"

#include "game_map.h"

#define _wall 1
#define _floor 0

void game_map::sight_generate()
{
	for (int y = 0; y < 9; y++)
	{
		for (int x = 0; x < 15; x++)
		{
			view[y][x].LoadBitmapByString({ img_floor,img_wall,img_wall_half });
			view[y][x].SetTopLeft(x * 60, y * 60);
			switch (_map[y][x])
			{
			case _wall:
				if (y == 0)
					view[y][x].SetFrameIndexOfBitmap(2);
				else
				{
					view[y][x].SetFrameIndexOfBitmap(1);
					view[y][x].SetTopLeft(x * 60, (y * 60) - 38);
				}
				break;
			case _floor:
				view[y][x].SetFrameIndexOfBitmap(0);
				break;
			default:
				break;
			}

			
		}
	}
}
void game_map::sight_show()
{
	for (int y = 0; y < 9; y++)
	{
		for (int x = 0; x < 15; x++)
		{
			view[y][x].ShowBitmap();
		}
	}
}
