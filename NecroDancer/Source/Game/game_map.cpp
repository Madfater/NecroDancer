#include "stdafx.h"
#include "game_map.h"


void game_map::init(int phase_number)
{
	start_x = s_x[phase_number];
	start_y = s_y[phase_number];
	map_height = 21;
	map_width = 24;
	std::ifstream inputFile = std::ifstream(map_name[phase_number], std::ios::binary);

	monsters = vector<Monster*>();
	blocks = vector<vector<block>>();
	player = new Player(start_x,start_y);

	std::vector<std::vector<int>> matrix(map_height, std::vector<int>(map_width));

	for (int i = 0; i < map_height; i++)
	{
		for (int j = 0; j < map_width; j++)
		{
			inputFile.read(reinterpret_cast<char*>(&matrix[i][j]), 1);
		}
	}
	inputFile.close();

	for (int i = 0; i < map_height; i++)
	{
		blocks.push_back(vector<block>());
		for (int j = 0; j < map_width; j++)
		{
			int block = 1;
			switch (matrix[i][j])
			{
				case _slime:
					monsters.push_back(new slime());
					monsters[monsters.size() - 1]->set_position(j, i, this);
					break;
				case _bat:
					monsters.push_back(new bat());
					monsters[monsters.size() - 1]->set_position(j, i, this);
					break;
				case _minotaur:
					monsters.push_back(new minotaur());
					monsters[monsters.size() - 1]->set_position(j, i, this);
					break;
				case _pawn:
					monsters.push_back(new pawn());
					monsters[monsters.size() - 1]->set_position(j, i, this);
					break;
				case _knight:
					monsters.push_back(new knight());
					monsters[monsters.size() - 1]->set_position(j, i, this);
					break;
				case _rook:
					monsters.push_back(new rook());
					monsters[monsters.size() - 1]->set_position(j, i, this);
					break;
				case _bishop:
					monsters.push_back(new bishop());
					monsters[monsters.size() - 1]->set_position(j, i, this);
					break;
				case _queen:
					monsters.push_back(new queen());
					monsters[monsters.size() - 1]->set_position(j, i, this);
					break;
				case _king:
					monsters.push_back(new king());
					monsters[monsters.size() - 1]->set_position(j, i, this);
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

	if (is_out_of_range(x, y))
		return _empty;

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
