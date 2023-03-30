/*
	設定所有圖片的路徑
*/
#pragma once
#include <string>
#include <vector>

const string img_wall ="resources/picture/wall.bmp";
const string img_wall_half = "resources/picture/wall_cut.bmp";
const string img_floor = "resources/picture/floor.bmp";
const string img_menu = "resources/picture/mainmenu.bmp";
const string img_beat = "resources/picture/beat.bmp";
const vector<string> img_heart = {"resources/picture/heart1.bmp","resources/picture/heart2.bmp"	 };
const int direction_x[4] = { -1,0,1,0 };//left->up->right->down
const int direction_y[4] = { 0,-1,0,1 };

const vector<string> img_background = { "resources/picture/floor.bmp","resources/picture/wall.bmp"};
const string img_menu = "resources/picture/mainmenu.bmp";
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
															"resources/picture/bat1.bmp",
															"resources/picture/bat2.bmp",
															"resources/picture/bat3.bmp",
															"resources/picture/bat4.bmp"
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
															"resources/picture/slime_fire1.bmp",
															"resources/picture/slime_fire2.bmp",
															"resources/picture/slime_fire3.bmp",
															"resources/picture/slime_fire4.bmp"
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
