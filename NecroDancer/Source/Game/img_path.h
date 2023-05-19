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

const vector<int> bat_step = { 1, 4, 3, 4 };
const vector<int> slime_step = { 0, 4, 2, 4 };

const int direction_x[5] = { -1,0,1,0,0 };//left->up->right->down->stop
const int direction_y[5] = { 0,-1,0,1,0 };

const string img_menu = "resources/picture/mainmenu.bmp";
const string img_beat = "resources/picture/beat.bmp";
const vector<string> img_heart = {"resources/picture/heart1.bmp","resources/picture/heart2.bmp"	 };
const vector<string> img_background = { "resources/picture/wall.bmp","resources/picture/floor_even.bmp","resources/picture/floor_odd.bmp" };
//const string img_menu = "resources/picture/mainmenu.bmp";

const string img_health_temp_full = "resources/picture/heart_temp_full.bmp";
const string img_health_temp_empty = "resources/picture/heart_temp_empty.bmp";

const string img_health_full = "resources/picture/heart.bmp";
const string img_health_half = "resources/picture/heart_half.bmp";
const string img_health_empty = "resources/picture/heart_empty.bmp";
const string money = "resources/picture/heart_half.bmp";
const vector<string> img_monster_attack = {
	"resources/picture/monster_attack1.bmp",
	"resources/picture/monster_attack2.bmp",
	"resources/picture/monster_attack3.bmp",
	"resources/picture/monster_attack4.bmp",
	"resources/picture/monster_attack5.bmp"
};
const vector<vector<string>> img_attack_dagger = {//left up right down
												{
													"resources/picture/attack_dagger_left1.bmp",
													"resources/picture/attack_dagger_left2.bmp",
													"resources/picture/attack_dagger_left3.bmp"
												},
												{
													"resources/picture/attack_dagger_up1.bmp",
													"resources/picture/attack_dagger_up2.bmp",
													"resources/picture/attack_dagger_up3.bmp"
												},
												{
													"resources/picture/attack_dagger_right1.bmp",
													"resources/picture/attack_dagger_right2.bmp",
													"resources/picture/attack_dagger_right3.bmp"
												},
												{
													"resources/picture/attack_dagger_down1.bmp",
													"resources/picture/attack_dagger_down2.bmp",
													"resources/picture/attack_dagger_down3.bmp"
												},
										};
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

const vector<vector<vector<string>>> img_monsters = {
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
													}
};

const vector<vector<vector<string>>> minotaur = {
	{
		{
			"resources/picture/cow_left1.bmp",
			"resources/picture/cow_left2.bmp",
			"resources/picture/cow_left3.bmp",
			"resources/picture/cow_left4.bmp"
		},
		{
			"resources/picture/cow_right1.bmp",
			"resources/picture/cow_right2.bmp",
			"resources/picture/cow_right3.bmp",
			"resources/picture/cow_right4.bmp"
		}
	},
	{
		{
			"cow_attack_left.bmp"
		},
		{
			"cow_attack_right.bmp"
		}
	},
	{
		{
			"cow_stunned_left1.bmp",
			"cow_stunned_left2.bmp",
			"cow_stunned_left3.bmp",
			"cow_stunned_left4.bmp"
		},
		{
			"cow_stunned_right1.bmp",
			"cow_stunned_right2.bmp",
			"cow_stunned_right3.bmp",
			"cow_stunned_right4.bmp"
		}
	}

	};
