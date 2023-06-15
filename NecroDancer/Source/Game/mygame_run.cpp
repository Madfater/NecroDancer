#include "stdafx.h"
#include "../Core/Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include <string>
#include "../Library/audio.h"
#include "../Library/gameutil.h"
#include "../Library/gamecore.h"
#include "mygame.h"
#include "img_path.h"
#include <fstream>
using namespace game_framework;

/////////////////////////////////////////////////////////////////////////////
// 這個class為遊戲的遊戲執行物件，主要的遊戲程式都在這裡
/////////////////////////////////////////////////////////////////////////////

CAudio* audio = CAudio::Instance();


void CGameStateRun :: monster_moving(game_map* m,_interface* inter)
{
	for (auto &i : m->get_chr())
	{
		if (i->get_hp() <= 0)
			continue;
		int d = i->move(m);
		int x = i->get_x() + direction_x[d];
		int y = i->get_y() + direction_y[d];

		switch (d)
		{
			case 0:
				i->set_faceright(false);
				break;
			case 2:
				i->set_faceright(true);
				break;
			default:
				break;
		}

		switch (m->get_block_info(x, y))
		{
			case _player:
				i->set_position(i->get_x(), i->get_y(), m);
				m->player->lose_HP(i->get_damage());
				audio->Play(4);
				break;
			case _floor:
				i->set_is_moving();
				i->set_position(x, y,m);
				break;
			default:
				i->set_position(i->get_x(), i->get_y(),m);
				break;
		}
		inter->load_hp(m->player->get_hp());
		if (m->player->get_hp() <= 0 && !is_debugmode)
		{
			phase_number = 4;
			init();
		}
	}
}

void CGameStateRun::moving(int direction)
{
	if ((direction >= 0 && direction <= 4) || direction==_stop)//left up right down
	{
		switch (direction)
		{
			case 0:
				m.player->set_faceright(false);
				break;
			case 2:
				m.player->set_faceright(true);
				break;
			default:
				break;
		}
		int player_x = m.player->get_x();
		int player_y = m.player->get_y();
		int weapon_id = m.player->get_weapon_id();
		std::random_device rd;
		std::mt19937 rng(rd());
		int id = 0;
		int info = m.get_block_info(player_x + direction_x[direction], player_y + direction_y[direction]);
		switch (info)
		{
			case _border:
				m.player->dig(direction);
				audio->Play(1);
				break;
			case _empty:
				break;
			case _door_hor:
				m.block_change(player_x + direction_x[direction], player_y + direction_y[direction], _floor);
				audio->Play(5);
				break;
			case _door_ver:
				m.block_change(player_x + direction_x[direction], player_y + direction_y[direction], _floor);
				audio->Play(5);
				break;
			case _wall:
				switch (m.player->get_shovel_id())
				{
					case 0:
						m.player->dig(direction);
						m.block_change(player_x + direction_x[direction], player_y + direction_y[direction], _floor);
						audio->Play(2);
						break;
					default:
						break;
				}
				break;
			case _floor:
				if (weapon_id != 0 && weapon_id != 3)
				{
					int ls1 = m.get_block_info(player_x + d_ls_x1[direction], player_y + d_ls_y1[direction]);
					int ls2 = m.get_block_info(player_x + d_ls_x2[direction], player_y + d_ls_y2[direction]);
					int s = m.get_block_info(player_x + d_spear_x[direction], player_y + d_spear_y[direction]);
					switch (weapon_id)
					{
						case longsword: case diamond_longsword:
							if (ls1 < 0)
							{
								int index = ls1 * -1 - 1;
								Monster* monster = m.get_chr()[index];
								m.player->attack(monster, direction);
								audio->Play(3);
								if (monster->get_hp() <= 0)
									m.pop_monster(index);
							}
							if (ls2 < 0)
							{
								int index = ls2 * -1 - 1;
								Monster* monster = m.get_chr()[index];
								m.player->attack(monster, direction);
								audio->Play(3);
								if (monster->get_hp() <= 0)
									m.pop_monster(index);
							}
							if (ls1 >= 0 && ls2 >= 0)
							{
								m.player->set_position(player_x + direction_x[direction], player_y + direction_y[direction]);
								m.player->set_moving();
							}
							break;
						case spear: case diamond_spear:
							if (s < 0)
							{
								int index = s * -1 - 1;
								Monster* monster = m.get_chr()[index];
								m.player->attack(monster, direction);
								audio->Play(3);
								if (monster->get_hp() <= 0)
									m.pop_monster(index);
							}
							else
							{
								m.player->set_position(player_x + direction_x[direction], player_y + direction_y[direction]);
								m.player->set_moving();
							}
							break;
						default:
							m.player->set_position(player_x + direction_x[direction], player_y + direction_y[direction]);
							m.player->set_moving();
							break;
					}
				}
				else
				{
					m.player->set_position(player_x + direction_x[direction], player_y + direction_y[direction]);
					m.player->set_moving();
				}
				break;
			case _player:
				break;
			case _stair:
				phase_number++;
				wid = m.player->get_weapon_id();
				init();
				break;
			case _chest:
				m.block_change(player_x + direction_x[direction], player_y + direction_y[direction], 1);
				m.player->set_position(player_x + direction_x[direction], player_y + direction_y[direction]);
				m.player->set_moving();
				audio->Play(6);
				if (phase_number == 0)
				{
					std::uniform_int_distribution<int> distInt(1, 2);
					id = distInt(rng);
				}
				else
				{
					std::uniform_int_distribution<int> distInt(1, 5);
					id = distInt(rng);
				}
				m.player->set_weapon_id(id);
				inter.set_weapon_id(id);
				break;
			default:
				{
					int ls1 = m.get_block_info(player_x + d_ls_x1[direction], player_y + d_ls_y1[direction]);
					int ls2 = m.get_block_info(player_x + d_ls_x2[direction], player_y + d_ls_y2[direction]);
					if (info < 0)
					{
						int index = info * -1 - 1;
						Monster* monster = m.get_chr()[index];
						m.player->attack(monster, direction);
						
						audio->Play(3);
						if (monster->get_hp() <= 0)
							m.pop_monster(index);
					}
					if (ls1 < 0 && (m.player->get_weapon_id()==longsword || m.player->get_weapon_id() == diamond_longsword))
					{
						int index = ls1 * -1 - 1;
						Monster* monster = m.get_chr()[index];
						m.player->attack(monster, direction);
						audio->Play(3);
						if (monster->get_hp() <= 0)
							m.pop_monster(index);
					}
					if (ls2 < 0 && (m.player->get_weapon_id() == longsword || m.player->get_weapon_id() == diamond_longsword))
					{
						int index = ls2 * -1 - 1;
						Monster* monster = m.get_chr()[index];
						m.player->attack(monster, direction);
						
						audio->Play(3);
						if (monster->get_hp() <= 0)
							m.pop_monster(index);
					}
				}
				break;
		}

		monster_moving(&m, &inter);

		if (phase_number == 2 && m.player->get_y() < 13)
		{
			m.block_change(10, 13, _border);
			m.block_change(11, 13, _border);
			m.block_change(12, 13, _border);
		}
		if (phase_number == 2)
		{
			bool f = true;
			for(auto &i:m.get_chr())
				if (i->get_hp() > 0)
				{
					f = false;
					break;
				}
			if (f)
			{
				m.block_change(10, 4, _floor);
				m.block_change(11, 4, _floor);
				m.block_change(12, 4, _floor);
			}
			
		}
	}
}

void game_framework::CGameStateRun::init()
{
	if (phase_number < 3)
	{
		tempo.init();
		inter.init();
		m.init(phase_number);
		c.init(&m);
		m.player->set_weapon_id(wid);
		inter.set_weapon_id(wid);
	}
	else
	{
		tempo.init();
		inter.init();
		m.init(0);
		c.init(&m);
	}
}

CGameStateRun::CGameStateRun(CGame *g) : CGameState(g)
{
}

CGameStateRun::~CGameStateRun()
{
}


void CGameStateRun::OnBeginState()
{
	audio->Load(0, "resources/audio/zone1_1.wav");
	audio->Load(1, "resources/audio/dig_dirt.wav");
	audio->Load(2, "resources/audio/dig_fail.wav");
	audio->Load(3, "resources/audio/hit.wav");
	audio->Load(4, "resources/audio/hurt.wav");
	audio->Load(5, "resources/audio/door_open.wav");
	audio->Load(6, "resources/audio/chest_open.wav");
	audio->Play(0,true);
	
}

void CGameStateRun::OnMove()							// 移動遊戲元素
{
	if(tempo.if_afterjump())
		moving(_stop);
}

void CGameStateRun::OnInit()  								// 遊戲的初值及圖形設定
{
	init();
}


void CGameStateRun::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	if (tempo.if_shouldjump())
		moving(nChar - 37);
	if (nChar == 32)
		is_debugmode = !is_debugmode;
}

void CGameStateRun::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	
}

void CGameStateRun::OnLButtonDown(UINT nFlags, CPoint point)  // 處理滑鼠的動作
{
	if ((point.x >= 335 && point.x <= 535) && (point.y >= 250 && point.y <= 350) && phase_number>2)
	{
		phase_number = 0;
		init();
	}
	else if ((point.x >= 335 && point.x <= 535) && (point.y >= 350 && point.y <= 450) && phase_number > 2)
	{
		phase_number = 0;
		init();
	}
}

void CGameStateRun::OnLButtonUp(UINT nFlags, CPoint point)	// 處理滑鼠的動作
{
}

void CGameStateRun::OnMouseMove(UINT nFlags, CPoint point)	// 處理滑鼠的動作
{
}

void CGameStateRun::OnRButtonDown(UINT nFlags, CPoint point)  // 處理滑鼠的動作
{
}

void CGameStateRun::OnRButtonUp(UINT nFlags, CPoint point)	// 處理滑鼠的動作
{
}

void CGameStateRun::OnShow()
{
	if (phase_number < 3)
	{
		c.show();
		tempo.show();
		inter.show();
	}
	else
	{
		game_framework::CMovingBitmap win;
		game_framework::CMovingBitmap restart;
		game_framework::CMovingBitmap leave;
		win.LoadBitmapByString({ "resources/picture/win.bmp","resources/picture/lose.bmp" });
		restart.LoadBitmapByString({ "resources/picture/restart.bmp" });
		leave.LoadBitmapByString({ "resources/picture/leave.bmp" });
		win.SetTopLeft(300, 0);
		restart.SetTopLeft(335, 250);
		leave.SetTopLeft(335, 350);
		win.SetFrameIndexOfBitmap(phase_number - 3);
		win.ShowBitmap();
		restart.ShowBitmap();
		leave.ShowBitmap();
	}
	
}