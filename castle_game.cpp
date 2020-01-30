// castlegame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>


class Unit_Values
{
private:
	int x_val, y_val, z_val;


public:
	int health, armor, move_speed, experience, attack_range;
	std::string damage_type, name;

	void set_unit_location(int x, int y, int z)
	{
		x_val = x;
		y_val = y;
		z_val = z;
	}

	int getX(void)
	{
		return x_val;
	}

	int getY(void)
	{
		return y_val;
	}

	int getZ(void)
	{
		return z_val;
	}
};


class Player
{
public:
	std::string name;
	std::vector<Unit_Values> army;
};


class Soldier : public Unit_Values
{
public:
	Soldier() 
	{
		health = 100;
		armor = 50;
		move_speed = 25;
		experience = 10;
		attack_range = 1;
		name = "Soldier";
		damage_type = "Melee";
	}
};

class Archer : public Unit_Values
{
public:
	Archer()
	{
		health = 25;
		armor = 5;
		move_speed = 35;
		experience = 25;
		attack_range = 5;
		name = "Archer";
		damage_type = "Ranged";
	}
};


class warmap
{
public:
	int map_size = 200;
	
	void map_movement(Player player_one, Player player_two)
	{
		for (auto &unit_one : player_one.army)
		{
			for (auto &unit_two : player_two.army)
			{
				unit_one.
			}
		}
	}
};


void set_player_one(std::vector<Unit_Values> &units_pointer, int map_size, std::string player_name)
{
	int x_val = 0, y_val = 0;
	for (auto &unit : units_pointer)
	{
		unit.set_unit_location(x_val, y_val, 0);

		if ((x_val > map_size) && (x_val % map_size == 0 || 1))
		{
			x_val = 0;
			++y_val;
		}
		x_val++;
	}
}

void set_player_two(std::vector<Unit_Values> &units_pointer, int map_size, std::string player_name)
{
	int x_val = 0, y_val = map_size;

	for (auto &unit : units_pointer)
	{
		unit.set_unit_location(x_val, y_val, 0);

		if ((x_val > map_size) && (x_val % map_size == 0 || 1))
		{
			x_val = 0;
			--y_val;
		}
		x_val++;
	}
}

void set_unit_positions(std::vector<Unit_Values> &units_pointer, int map_size, std::string player_name)
{
	for (auto &unit : units_pointer)
	{
		
		if (player_name == "player_one")
		{
			int x_val = 0, y_val = 0;

			unit.set_unit_location(x_val, y_val, 0);

			if ((x_val > map_size) && (x_val % map_size == 0 || 1))
			{
				x_val = 0;
				++y_val;
			}
			x_val++;
		}

		else if (player_name == "player_two")
		{
			int x_val = 0, y_val = map_size;

			unit.set_unit_location(x_val, y_val, 0);

			if ((x_val > map_size) && (x_val % map_size == 0 || 1))
			{
				x_val = 0;
				--y_val;
			}
			x_val++;
		}
	}
}

std::vector<Unit_Values> redeem_points(int num)
{
	std::vector<Unit_Values> unit_vector;
	 for (int i = 0; i < num; ++i)
	{
		Soldier curr_unit;
		unit_vector.push_back(curr_unit);
		//std::cout << curr_unit.health << " " << curr_unit.health << " " << curr_unit.damage_type << "\n";
	} 
	return unit_vector;
}


int main()
{
	warmap our_map;

	Player player_one;
	Player player_two;


	std::vector<Unit_Values> our_units = redeem_points(400);
	player_one.army = redeem_points(400);
	std::vector<Unit_Values> *player_one_army_pointer = &player_one.army;
	player_two.army = redeem_points(400);
	std::vector<Unit_Values> *player_two_army_pointer = &player_two.army;
	player_one.name = "player_one";
	player_two.name = "player_two";

	set_player_one(*player_one_army_pointer, our_map.map_size, player_one.name);
	set_player_two(*player_two_army_pointer, our_map.map_size, player_two.name);

	
	for (auto &unit : *player_one_army_pointer)
	{
		//std::cout << unit.getX() << " " << unit.getY() << " " << unit.getZ() << "END ";
		std::cout << "(" << unit.getX() << ", " << unit.getY() << ", " << unit.getZ() << ")" << std::endl;
	}
	int inp;
	
	std::cout << "enter a number:" << std::endl;
	std::cin >> inp; 
	
	for (auto &unit : *player_two_army_pointer)
	{
		std::cout << "(" << unit.getX() << ", " << unit.getY() << ", " << unit.getZ() << ")" << std::endl;
	}
	
	//our_map.map_movement(player_one, player_two);

	return 0;
}
