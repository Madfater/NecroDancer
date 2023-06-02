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


void monster_moving(game_map* m,_interface* inter)
{
	for (auto &i : m->get_chr())
	{
		int d = i->move(m);
		int x = i->get_x() + direction_x[d];
		int y = i->get_y() + direction_y[d];

		switch (m->get_block_info(x, y))
		{
			case _player:
				i->set_position(i->get_x(), i->get_y(), m->player->get_x(), m->player->get_y());
				m->player->lose_HP(i->get_damage());
				inter->lose_hp();
				break;
			case _floor:
				i->set_is_moving();
				i->set_position(x, y, m->player->get_x(), m->player->get_y());
				break;
			default:
				i->set_position(i->get_x(), i->get_y(), m->player->get_x(), m->player->get_y());
				break;
		}
	}
}

void moving(int direction, game_map* m, _interface* inter)
{
	if (direction >= 0 && direction <= 4)//left up right down
	{
		switch (direction)
		{
			case 0:
				m->player->set_faceright(false);
				break;
			case 2:
				m->player->set_faceright(true);
				break;
			default:
				break;
		}
		
		int info = m->get_block_info(m->player->get_x() + direction_x[direction], m->player->get_y() + direction_y[direction]);
		switch (info)
		{
			case _border:
				break;
			case _empty:
				break;
			case _wall:
				switch (m->player->get_shovel_id())
				{
					case 0:
						m->player->dig(direction);
						m->block_change(m->player->get_x() + direction_x[direction], m->player->get_y() + direction_y[direction], _floor);
						break;
					default:
						break;
				}
				break;
			case _floor:
				m->player->set_position(m->player->get_x() + direction_x[direction], m->player->get_y() + direction_y[direction]);
				m->player->set_moving();
				break;
			case _player:
				break;
			default:
				int index = info * -1 - 1;
				Monster* monster = m->get_chr()[index];
				m->player->attack(monster, direction);
				if (monster->get_hp() <= 0)
					m->pop_monster(index);
				break;
		}
		monster_moving(m, inter);
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
}

void CGameStateRun::OnMove()							// 移動遊戲元素
{
	
}

void CGameStateRun::OnInit()  								// 遊戲的初值及圖形設定
{
	CAudio* audio = CAudio::Instance();
	audio->Load(0, "resources/audio/zone1_1.wav");
	audio->Play(0);
	tempo.init();
	inter.init();
	m.init();
	c.init(&m);
}



void CGameStateRun::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	//if (tempo.if_shouldjump())
	if(1)
	{
		int direction = nChar - 37;
		moving(direction, &m, &inter);
	}
}

void CGameStateRun::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	
}

void CGameStateRun::OnLButtonDown(UINT nFlags, CPoint point)  // 處理滑鼠的動作
{
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
	c.show();
	tempo.show();
	inter.show();
}
