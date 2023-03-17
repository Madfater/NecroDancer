/*
	設定所有圖片的路徑
*/
#pragma once
#include <string>
#include <vector>

const string img_wall ="resources/wall.bmp";
const string img_wall_half = "resources/wall_cut.bmp";
const string img_floor = "resources/floor.bmp";
const string img_menu = "resources/mainmenu.bmp";
const vector<vector<string>> img_player = 
{ 
	{	
		"resources/player_left1.bmp",
		"resources/player_left2.bmp",
		"resources/player_left3.bmp",
		"resources/player_left4.bmp"},
	{
		"resources/player_right1.bmp",
		"resources/player_right2.bmp",
		"resources/player_right3.bmp",
		"resources/player_right4.bmp"}
	};
const vector<string> img_player_left = {	 };
const vector<string> img_bat = {"resources/bat1.bmp",
								"resources/bat2.bmp",
								"resources/bat3.bmp",
								"resources/bat4.bmp" };
const vector<string> img_dragon = {	"resources/dragon_red1.bmp",
									"resources/dragon_red2.bmp",
									"resources/dragon_red3.bmp",
									"resources/dragon_red4.bmp" };
