/*
	設定所有圖片的路徑
*/
#pragma once
#include <string>
#include <vector>

enum map_obj {_wall,_floor,_player, _empty, _border, _store, _slime, _bat, _minotaur};
enum status { normal, stunned, rush, _attack };
enum directions { _left, _up, _right, _down, _stop };

const int weapon_damage[1] = { 1 };

const vector<short> bat_step = { 4, 1, 4, 3 };
const vector<short> slime_step = { 4, 0, 4, 2 };

const short direction_x[5] = { -1,0,1,0,0 };
const short direction_y[5] = { 0,-1,0,1,0 };

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
const vector<string> img_shovel = { "resources/picture/shovel_left.bmp","resources/picture/shovel_right.bmp" };
const vector<string> img_monster_attack = {
	"resources/picture/monster_attack1.bmp",
	"resources/picture/monster_attack2.bmp",
	"resources/picture/monster_attack3.bmp",
	"resources/picture/monster_attack4.bmp",
	"resources/picture/monster_attack5.bmp"
};
const vector<vector<string>> img_attack_dagger = {
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

const vector<vector<vector<string>>> img_minotaur = {
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
			"resources/picture/cow_attack_left.bmp"
		},
		{
			"resources/picture/cow_attack_right.bmp"
		}
	},
	{
		{
			"resources/picture/cow_stunned_left1.bmp",
			"resources/picture/cow_stunned_left2.bmp",
			"resources/picture/cow_stunned_left3.bmp",
			"resources/picture/cow_stunned_left4.bmp"
		},
		{
			"resources/picture/cow_stunned_right1.bmp",
			"resources/picture/cow_stunned_right2.bmp",
			"resources/picture/cow_stunned_right3.bmp",
			"resources/picture/cow_stunned_right4.bmp"
		}
	}

	};
