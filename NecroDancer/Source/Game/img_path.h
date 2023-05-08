/*
	設定所有圖片的路徑
*/
#pragma once
#include <string>
#include <vector>

#define _wall 0
#define _floor 1
#define _player 2

const int weapon_damage[1] = { 1 };

const int direction_x[5] = { -1,0,1,0,0 };//left->up->right->down->stop
const int direction_y[5] = { 0,-1,0,1,0 };

const string img_menu = "resources/picture/mainmenu.bmp";
const string img_beat = "resources/picture/beat.bmp";
const vector<string> img_heart = {"resources/picture/heart1.bmp","resources/picture/heart2.bmp"	 };
const vector<string> img_background = { "resources/picture/wall.bmp","resources/picture/floor_even.bmp","resources/picture/floor_odd.bmp" };
//const string img_menu = "resources/picture/mainmenu.bmp";

const string img_health_full = "resources/picture/heart.bmp";
const string img_health_half = "resources/picture/heart_half.bmp";
const string img_health_empty = "resources/picture/heart_empty.bmp";
const string money = "resources/picture/heart_half.bmp";
const vector<vector<string>> img_player={ 
											{	
												"resources/picture/player_left1.bmp",
												"resources/picture/player_left2.bmp",
												"resources/picture/player_left3.bmp",
												"resources/picture/player_left4.bmp"
											},
											{
												"resources/picture/player_right1.bmp",
												"resources/picture/player_right2.bmp",
												"resources/picture/player_right3.bmp",
												"resources/picture/player_right4.bmp"
											}
										};

const vector<vector<vector<string>>> img_monsters={
													{
														{
															"resources/picture/bat_left1.bmp",
															"resources/picture/bat_left2.bmp",
															"resources/picture/bat_left3.bmp",
															"resources/picture/bat_left4.bmp"
														},
														{
															"resources/picture/bat1.bmp",
															"resources/picture/bat2.bmp",
															"resources/picture/bat3.bmp",
															"resources/picture/bat4.bmp"
														}
													},
													{
														{
															"resources/picture/slime_fire1.bmp",
															"resources/picture/slime_fire2.bmp",
															"resources/picture/slime_fire3.bmp",
															"resources/picture/slime_fire4.bmp"
														},
														{
															"resources/picture/slime_fire_right1.bmp",
															"resources/picture/slime_fire_right2.bmp",
															"resources/picture/slime_fire_right3.bmp",
															"resources/picture/slime_fire_right4.bmp"
														}
													},
													{
														{
															"resources/picture/dragon_red1.bmp",
															"resources/picture/dragon_red2.bmp",
															"resources/picture/dragon_red3.bmp",
															"resources/picture/dragon_red4.bmp"
														},
														{
															"resources/picture/dragon_red1.bmp",
															"resources/picture/dragon_red2.bmp",
															"resources/picture/dragon_red3.bmp",
															"resources/picture/dragon_red4.bmp"
														}
													}
												};
