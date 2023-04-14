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
	//CAudio music1();
	//music1.load(0, "D:\OOP\2023s\teamproject\NecroDancer\NecroDancer\Resources\audio\zone1_1.wav");
	m.init();
	c.init(&m);
}
character* is_collide(character* chr,vector<character*> chrs,int d)
{
	for (character* &i : chrs)
		if (i->get_map_x() == chr->get_map_x() + direction_x[d] && i->get_map_y() == chr->get_map_y() + direction_y[d])
			return i;
	return nullptr;
}

void move(int direction,game_map m)
{
	if (direction >= 0 && direction <= 4)
	{
		if (m.get_block_info(m.player->get_map_x() + direction_x[direction], m.player->get_map_y() + direction_y[direction])->type == 0 && is_collide(m.player, m.characters, direction)==nullptr)
		{
			m.player->set_map_position(m.player->get_map_x() + direction_x[direction], m.player->get_map_y() + direction_y[direction]);
			m.player->set_moving();
			for (auto &i : m.characters)
			{
				int x = i->get_map_x() + direction_x[i->get_move_direction()];
				int y = i->get_map_y() + direction_y[i->get_move_direction()];
				int is_wall = m.get_block_info(x, y)->type;
				if (is_wall == 0 && is_collide(i, m.characters, i->get_move_direction())==nullptr)
				{
					i->set_map_position(i->get_map_x() + direction_x[i->get_move_direction()], i->get_map_y() + direction_y[i->get_move_direction()]);
					i->set_moving();
				}
				else if (is_collide(i, { m.player }, i->get_move_direction()))
				{
					i->attack(m.player);
				}
				i->move_step_increase();
			}
		}
		else if (is_collide(m.player, m.characters, direction))
		{
			m.player->attack(is_collide(m.player, m.characters, direction));
		}
		for (auto &j : m.characters)
		{
			int camera_x = 7 - (m.player->get_map_x() - j->get_map_x());
			int camera_y = 4 - (m.player->get_map_y() - j->get_map_y());
			j->set_camera_position(camera_x, camera_y);
		}
	}
}

void CGameStateRun::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	//if (tempo.if_shouldjump())
	if(1)
	{
		int direction = nChar - 37;
		move(direction, m);
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
}
