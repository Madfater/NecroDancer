/*
	設定所有圖片的路徑
*/
#pragma once
#include <string>
#include <vector>

const int direction_x[4] = { -1,0,1,0 };//left->up->right->down
const int direction_y[4] = { 0,-1,0,1 };

const vector<string> img_background = { "resources/floor.bmp","resources/wall.bmp"};
const string img_menu = "resources/mainmenu.bmp";
const vector<vector<string>> img_player={ 
											{	
												"resources/player_left1.bmp",
												"resources/player_left2.bmp",
												"resources/player_left3.bmp",
												"resources/player_left4.bmp"
											},
											{
												"resources/player_right1.bmp",
												"resources/player_right2.bmp",
												"resources/player_right3.bmp",
												"resources/player_right4.bmp"
											}
										};

const vector<vector<vector<string>>> img_monsters={
													{
														{
															"resources/bat1.bmp",
															"resources/bat2.bmp",
															"resources/bat3.bmp",
															"resources/bat4.bmp"
														},
														{
															"resources/bat1.bmp",
															"resources/bat2.bmp",
															"resources/bat3.bmp",
															"resources/bat4.bmp"
														}
													},
													{
														{
															"resources/slime_fire1.bmp",
															"resources/slime_fire2.bmp",
															"resources/slime_fire3.bmp",
															"resources/slime_fire4.bmp"
														},
														{
															"resources/slime_fire1.bmp",
															"resources/slime_fire2.bmp",
															"resources/slime_fire3.bmp",
															"resources/slime_fire4.bmp"
														}
													},
													{
														{
															"resources/dragon_red1.bmp",
															"resources/dragon_red2.bmp",
															"resources/dragon_red3.bmp",
															"resources/dragon_red4.bmp"
														},
														{
															"resources/dragon_red1.bmp",
															"resources/dragon_red2.bmp",
															"resources/dragon_red3.bmp",
															"resources/dragon_red4.bmp"
														}
													}
												};
