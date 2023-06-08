#pragma once
#ifndef CLASSitem_H
#define CLASSitem_H
#include "../Library/gameutil.h"
#include "img_path.h"
#include "game_map.h"

class game_map;

class Item 
{
	protected:
		Item::Item(vector<string>);
		virtual ~Item() = default;

		game_framework::CMovingBitmap img;

		int x;
		int y;
		int camera_x;
		int camera_y;

	public:
		int get_x();
		int get_y();
		int get_camera_x();
		int get_camera_y();
		void set_position(int, int, game_map*);
		virtual void show() = 0;
		
};

class Bomb :public Item 
{
	private:
		int cnt;	

	public:
		Bomb() : Item(img_bomb) {};
		virtual void show() override;
};

class Chest :public Item
{
	private:

	public:
		Chest() : Item(img_chest) {};
		virtual void show() override;
};

class Stair :public Item
{
	private:

	public:
		Stair() : Item(img_stair) {};
		virtual void show() override;
};

#endif