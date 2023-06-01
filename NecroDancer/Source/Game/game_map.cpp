#include "stdafx.h"
#include "game_map.h"


void game_map::init()
{
	start_x = 3;
	start_y = 3;
	map_height = 17;
	map_width = 24;

	player = new Player(start_x,start_y);

	std::ifstream inputFile("resources/map/map.bin", std::ios::binary);

	// 讀取數據
	std::vector<std::vector<int>> matrix(17, std::vector<int>(24));

	for (int i = 0; i < 17; i++)
	{
		for (int j = 0; j < 24; j++)
		{
			inputFile.read(reinterpret_cast<char*>(&matrix[i][j]), 1);
		}
	}
	inputFile.close();
	// 關閉檔案
	for (int i = 0; i < 17; i++)
	{
		blocks.push_back(vector<block>());
		for (int j = 0; j < 24; j++)
		{
			int block = 1;
			switch (matrix[i][j])
			{
				case _slime:
					monsters.push_back(new slime());
					monsters[monsters.size()-1]->set_position(j, i, player->get_x(), player->get_y());
					break;
				case _bat:
					monsters.push_back(new bat());
					monsters[monsters.size() - 1]->set_position(j, i, player->get_x(), player->get_y());
					break;
				case _minotaur:
					monsters.push_back(new minotaur());
					monsters[monsters.size() - 1]->set_position(j, i, player->get_x(), player->get_y());
					break;
				default:
					block = matrix[i][j];
					break;
			}
			blocks[i].push_back({ block });
		}
	}
}

vector<Monster*> game_map::get_chr()
{
	return monsters;
}

void game_map::pop_monster(int n)
{
	monsters.erase(monsters.begin() + n);
}

bool game_map::is_out_of_range(int x, int y)
{
	if (y >= map_height || y < 0 || x >= map_width || x < 0)
		return true;

	return false;
}

int game_map::get_block_info(int x,int y)
{

	if (player->get_x() == x && player->get_y() == y)
		return _player;

	for (int i = 0; i < monsters.size(); i++)
		if (monsters[i]->get_x() == x && monsters[i]->get_y() == y)
			return -1*(i+1);

	return blocks[y][x].type;
}

void game_map::block_change(int x, int y, int type)
{
	blocks[y][x].type = type;
}
