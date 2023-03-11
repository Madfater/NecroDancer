#include "stdafx.h"
#include "../Core/Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "../Library/audio.h"
#include "../Library/gameutil.h"
#include "../Library/gamecore.h"
#include "mygame.h"

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
	
	for (int y = 0; y < 9; y++)
	{
		for (int x = 0; x < 15; x++)
		{
			background[x][y].LoadBitmapByString({ "resources/wall.bmp","resources/floor.bmp","resources/wall_cut.bmp" });


			if (y == 0)
			{
				background[x][y].SetTopLeft(x * 60, y * 60);
				background[x][y].SetFrameIndexOfBitmap(2);
			}
			else if (y == 2)
			{
				background[x][y].SetTopLeft(x * 60, (y * 60) - 38);
				background[x][y].SetFrameIndexOfBitmap(0);
			}
			else
			{
				background[x][y].SetTopLeft(x * 60, y * 60);
				background[x][y].SetFrameIndexOfBitmap(1);
			}
		}
	}
	character.LoadBitmap({ "resources/player1.bmp","resources/player2.bmp","resources/player3.bmp","resources/player4.bmp" }, RGB(0,0,0));
	character.SetTopLeft(450, 270);
	character.SetAnimation(50, false);
}

void CGameStateRun::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	if (nChar == 37) { // Left Arrow
		jump = 1;
	}
	if (nChar == 38) { // Up Arrow	
		jump = 1;
	}
	if (nChar == 39) { // Right Arrow
		jump = 1;
	}
	if (nChar == 40) { // Down Arrow
		jump = 1;
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
	for (int y = 0; y < 9; y++)
	{
		for (int x = 0; x < 15; x++)
		{
			background[x][y].ShowBitmap();
		}
	}
	if (jump == 1) {
		if (isfalling == 0) {
			character.SetTopLeft(character.GetLeft(), character.GetTop() - 5); //控制上升速度
			if (character.GetTop() <= 240) //上升高度
				isfalling = 1;
		}
		if (isfalling == 1) {
			character.SetTopLeft(character.GetLeft(), character.GetTop() + 5); //控制下降速度
			if (character.GetTop() >= 270) { //下降高度
				isfalling = 0;
				jump = 0;
			}
		}
	}
	character.ShowBitmap();
}
