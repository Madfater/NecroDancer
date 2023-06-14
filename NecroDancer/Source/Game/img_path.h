/*
	設定所有圖片的路徑
*/
#pragma once
#include <string>
#include <vector>

enum map_obj {
	_wall, _floor, _player, _empty, _border, _store, 
	_slime,_bat, _minotaur, _door_hor, _door_ver,
	_stair,_chest, _pawn, _knight, _rook, 
	_bishop, _queen, _king
};
enum status { normal, stunned, rush, _attack };
enum directions { _left, _up, _right, _down, _upr, _downr, _downl, _upl, _stop};
enum weapon { dagger, longsword, spear, diamond_dagger, diamond_longsword, diamond_spear };

const int weapon_damage[6] = { 1, 1, 1, 2, 2, 2};

const vector<short> slime_step = { _stop, _left, _stop, _right };

const short direction_x[17] = { -1,0,1,0,1,1,-1,-1,0,2,2,-2,-2,1,1,-1,-1 };
const short direction_y[17] = { 0,-1,0,1,-1,1,1,-1,0,1,-1,1,-1,2,-2,2,-2 };

const int d_spear_x[4] = { -2,0,2,0 };
const int d_spear_y[4] = { 0,-2,0,2 };

const int d_ls_x1[4] = { -1,-1,1,1 };
const int d_ls_y1[4] = { 1,-1,-1,1 };

const int d_ls_x2[4] = { -1,1,1,-1 };
const int d_ls_y2[4] = { -1,-1,1 ,1 };

const string img_menu = "resources/picture/mainmenu.bmp";

const string img_beat = "resources/picture/beat.bmp";

const vector<string> img_heart = {"resources/picture/heart1.bmp","resources/picture/heart2.bmp"	 };

const vector<string> img_background = { "resources/picture/wall.bmp",
										"resources/picture/floor_even.bmp",
										"resources/picture/floor_odd.bmp",
										"resources/picture/unbreakable.bmp",
										"resources/picture/stair.bmp",
										"resources/picture/door_hor.bmp",
										"resources/picture/door_ver.bmp",
										"resources/picture/chest1.bmp"
									  };

//const string img_menu = "resources/picture/mainmenu.bmp";

const string img_health_temp_full = "resources/picture/heart_temp_full.bmp";
const string img_health_temp_empty = "resources/picture/heart_temp_empty.bmp";

const string img_health_full = "resources/picture/heart.bmp";
const string img_health_half = "resources/picture/heart_half.bmp";
const string img_health_empty = "resources/picture/heart_empty.bmp";

const vector<string> img_bomb = { "resources/picture/bomb1.bmp" ,"resources/picture/bomb2.bmp" };
const vector<string> img_chest = { "resources/picture/chest.bmp" };
const vector<string> img_stair = { "resources/picture/stair.bmp" };

const string money = "resources/picture/heart_half.bmp";

const vector<string> img_shovel = { "resources/picture/shovel_left.bmp","resources/picture/shovel_right.bmp" };

const vector<string> img_weapon_icon = 
{ 
	"resources/picture/dagger.bmp", 
	"resources/picture/longsword.bmp",
	"resources/picture/spear.bmp",
	"resources/picture/dagger_diamond.bmp",
	"resources/picture/longsword_diamond.bmp",
	"resources/picture/spear_diamond.bmp"


};

const vector<string> img_monster_attack = {
											"resources/picture/monster_attack1.bmp",
											"resources/picture/monster_attack2.bmp",
											"resources/picture/monster_attack3.bmp",
											"resources/picture/monster_attack4.bmp",
											"resources/picture/monster_attack5.bmp"
										  };
const vector<vector<vector<string>>> img_weapon = {
	{
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
		}
	},
	{
		{
			"resources/picture/attack_longsword_left1.bmp",
			"resources/picture/attack_longsword_left2.bmp",
			"resources/picture/attack_longsword_left3.bmp"
		},
		{
			"resources/picture/attack_longsword_up1.bmp",
			"resources/picture/attack_longsword_up2.bmp",
			"resources/picture/attack_longsword_up3.bmp"
		},
		{
			"resources/picture/attack_longsword_right1.bmp",
			"resources/picture/attack_longsword_right2.bmp",
			"resources/picture/attack_longsword_right3.bmp"
		},
		{
			"resources/picture/attack_longsword_down1.bmp",
			"resources/picture/attack_longsword_down2.bmp",
			"resources/picture/attack_longsword_down3.bmp"
		},
	},
	{
		{
			"resources/picture/attack_spear_left1.bmp",
			"resources/picture/attack_spear_left2.bmp",
			"resources/picture/attack_spear_left3.bmp",
			"resources/picture/attack_spear_left4.bmp",
		},
		{
			"resources/picture/attack_spear_up1.bmp",
			"resources/picture/attack_spear_up2.bmp",
			"resources/picture/attack_spear_up3.bmp",
			"resources/picture/attack_spear_up4.bmp"
		},
		{
			"resources/picture/attack_spear_right1.bmp",
			"resources/picture/attack_spear_right2.bmp",
			"resources/picture/attack_spear_right3.bmp",
			"resources/picture/attack_spear_right4.bmp"
		},
		{
			"resources/picture/attack_spear_down1.bmp",
			"resources/picture/attack_spear_down2.bmp",
			"resources/picture/attack_spear_down3.bmp",
			"resources/picture/attack_spear_down4.bmp"
		}
	}

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

const vector<vector<string>> img_minotaur = {
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
												}
										  };

const vector<vector<string>> img_minotaur_attack = {
														{
															"resources/picture/cow_attack_left.bmp"
														},
														{
															"resources/picture/cow_attack_right.bmp"
														}
												   };

const vector<vector<string>> img_minotaur_stunned = {
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
													};


const vector<vector<string>> img_pawn = {
											{
												"resources/picture/pawn1.bmp",
												"resources/picture/pawn2.bmp",
												"resources/picture/pawn3.bmp",
												"resources/picture/pawn4.bmp"
											},
											{
												"resources/picture/pawn1.bmp",
												"resources/picture/pawn2.bmp",
												"resources/picture/pawn3.bmp",
												"resources/picture/pawn4.bmp"
											}
										};

const vector<string> img_pawn_attack = { "resources/picture/pawn_attack.bmp" };


const vector<vector<string>> img_knight = {
											{
												"resources/picture/knight1.bmp",
												"resources/picture/knight2.bmp",
												"resources/picture/knight3.bmp",
												"resources/picture/knight4.bmp"
											},
											{
												"resources/picture/knight1.bmp",
												"resources/picture/knight2.bmp",
												"resources/picture/knight3.bmp",
												"resources/picture/knight4.bmp"
											}
									   };

const vector<string> img_knight_attack = { "resources/picture/knight_attack.bmp" };

const vector<vector<string>> img_rook = {
											{
												"resources/picture/rook1.bmp",
												"resources/picture/rook2.bmp"
											},
											{
												"resources/picture/rook1.bmp",
												"resources/picture/rook2.bmp"
											}
										};

const vector<string> img_rook_attack = { "resources/picture/rook_attack.bmp" };

const vector<vector<string>> img_bishop = {
											{
												"resources/picture/bishop1.bmp",
												"resources/picture/bishop2.bmp",
												"resources/picture/bishop3.bmp",
												"resources/picture/bishop4.bmp"
											},
											{
												"resources/picture/bishop1.bmp",
												"resources/picture/bishop2.bmp",
												"resources/picture/bishop3.bmp",
												"resources/picture/bishop4.bmp"
											}
										};

const vector<string> img_bishop_attack = { "resources/picture/bishop_attack.bmp" };

const vector<vector<string>> img_queen = {
											{
												"resources/picture/queen.bmp"
											},
											{
												"resources/picture/queen.bmp"
											}
										};

const vector<vector<string>> img_king = {
											{
												"resources/picture/king1.bmp",
												"resources/picture/king2.bmp",
												"resources/picture/king3.bmp",
												"resources/picture/king4.bmp"
											},
											{
												"resources/picture/king1.bmp",
												"resources/picture/king2.bmp",
												"resources/picture/king3.bmp",
												"resources/picture/king4.bmp"
											}
										};