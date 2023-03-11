#include "../Library/gameutil.h"
#include "img_path.h"

#define _wall 1
#define _floor 0

class game_map
{
	private:
		game_framework::CMovingBitmap view[9][15];
		int _map[9][15] = {
							{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
						 };
		void sight_generate();
		void sight_show();
};

void game_map::sight_generate()
{
	for (int y = 0; y < 9; y++)
	{
		for (int x = 0; x < 15; x++)
		{
			view[y][x].LoadBitmapByString({ img_floor,img_wall,img_wall_half });

			switch (_map[y][x])
			{
			case _wall:
				if (y == 0)
					view[x][y].SetFrameIndexOfBitmap(2);
				else
					view[x][y].SetFrameIndexOfBitmap(1);
				break;
			case _floor:
				view[x][y].SetFrameIndexOfBitmap(0);
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
			view[x][y].ShowBitmap();
		}
	}
}
