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
	
	void map_movement(Unit_Values)
	{
		;
	}
};


void set_unit_positions(std::vector<Unit_Values> units_pointer, int map_size)
{
	int x_val = 0, y_val = 0;
	for (Unit_Values unit : units_pointer)
	{
		
		(&unit)->set_unit_location(x_val, y_val, 0);

		//std::cout << unit.getX() << " " << unit.getY() << " " << unit.getZ() << "END ";
		
		if ((x_val > map_size) && (x_val % map_size == 0 || 1))
		{
			//std::cout << "\ny change from " << y_val << " to ";
			x_val = 0;
			++y_val;
			//std::cout << y_val << "\n";
		}
		//std::cout << "x value:" << x_val << ", ";
		x_val++;
	}
}

std::vector<Unit_Values> redeem_points(int num)
{
	std::vector<Unit_Values> unit_vector;
	Soldier curr_unit;
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

	std::vector<Unit_Values> our_units = redeem_points(1600);

	std::vector<Unit_Values> *units_pointer = &our_units;

	set_unit_positions(*units_pointer, our_map.map_size);
	
	for (Unit_Values unit : *units_pointer)
	{
		//std::cout << unit.health << "HEALTH ";
		std::cout << unit.getX() << " " << unit.getY() << " " << unit.getZ() << "END ";
		//std::cout << "(" << unit.getX() << ", " << unit.getY() << ", " << unit.getZ() << ")" << std::endl;
	}
	
	return 0;
}
