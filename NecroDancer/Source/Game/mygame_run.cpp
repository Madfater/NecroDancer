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
	_map.sight_generate();
	character.LoadBitmap({ "resources/player1.bmp","resources/player2.bmp","resources/player3.bmp","resources/player4.bmp" }, RGB(0, 0, 0));
	character.SetTopLeft(60*7, 60*4);
	character.SetAnimation(120, false);
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
	_map.sight_show();
	if (jump == 1) {
		if (isfalling == 0) {
			character.SetTopLeft(character.GetLeft(), character.GetTop() - 5); //控制上升速度
			if (character.GetTop() <= 60*4-30) //上升高度
				isfalling = 1;
		}
		if (isfalling == 1) {
			character.SetTopLeft(character.GetLeft(), character.GetTop() + 5); //控制下降速度
			if (character.GetTop() == 60*4) { //下降高度
				isfalling = 0;
				jump = 0;
			}
		}
	}
	character.ShowBitmap();
}
