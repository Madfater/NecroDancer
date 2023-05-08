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
	tempo.init();
	i.init();
	//CAudio music1();
	//music1.load(0, "D:\OOP\2023s\teamproject\NecroDancer\NecroDancer\Resources\audio\zone1_1.wav");
	m.init();
	c.init(&m);
}

void move(int direction,game_map* m)
{
	if (direction >= 0 && direction <= 3)
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

		int info = m->get_block_info(m->player->get_map_x() + direction_x[direction], m->player->get_map_y() + direction_y[direction]);
		switch (info)
		{
			case _wall:
				break;
			case _floor:
				m->player->set_map_position(m->player->get_map_x() + direction_x[direction], m->player->get_map_y() + direction_y[direction]);
				m->player->set_moving();
				for (auto &i : m->get_chr())
				{
					int x = i->get_map_x() + direction_x[i->get_move_direction()];
					int y = i->get_map_y() + direction_y[i->get_move_direction()];
	
					switch (m->get_block_info(x, y))
					{
						case _wall:
							break;
						case _player:
							m->player->lose_HP(i->get_damage());
							break;
						case _floor:
							i->set_map_position(i->get_map_x() + direction_x[i->get_move_direction()], i->get_map_y() + direction_y[i->get_move_direction()]);
							break;
					} 
					i->move_step_increase();
				}
				break;
			default:
				character* monster = m->get_chr()[info*-1-1];
				m->player->attack(monster);
				if (monster->get_hp() <= 0)
					m->pop_monster(info*-1-1);
				break;
		}
	}
}

void CGameStateRun::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	//if (tempo.if_shouldjump())
	if(1)
	{
		int direction = nChar - 37;
		move(direction, &m);
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
	i.show();
}
