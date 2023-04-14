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
	i.init();
	//CAudio music1();
	//music1.load(0, "D:\OOP\2023s\teamproject\NecroDancer\NecroDancer\Resources\audio\zone1_1.wav");
	m.init();
	c.init(&m);
}
bool is_collide(character* chr,vector<character*> chrs,int d)
{
	for (character* &i : chrs)
		if (i->get_x() == chr->get_x() + direction_x[d] && i->get_y() == chr->get_y() + direction_y[d])
			return false;
	return true;
}

void CGameStateRun::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	if (tempo.if_shouldjump())
	{
		int direction = nChar - 37;
		if(direction>=0 && direction<=3)
		{
			character* player = m.characters[0];

			if (direction == 0)
				player->set_faceright(false);
			else if (direction == 2)
				player->set_faceright(true);

			for (auto &i : m.characters)
			{
				if (m.get_block_info(i->get_x() + direction_x[direction], i->get_y() + direction_y[direction])->type == 0 && is_collide(i, m.characters, direction))
				{
					i->set_position_map(i->get_x() + direction_x[direction], i->get_y() + direction_y[direction]);
					i->set_move_position(4 - (player->get_y() - i->get_y()));
					i->moving();
					for (auto &j : m.characters)
						j->set_position_camera(7 - (player->get_x() - j->get_x()), 4 - (player->get_y() - j->get_y()));
				}
			}
		}
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
