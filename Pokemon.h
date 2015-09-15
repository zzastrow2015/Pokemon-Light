/**
*	@file : Pokemon.h
*	@author :  Zach Zastrow zast@ku.edu
*	@id: 2314432
*	@date : 07 February 2014
*	Purpose: Make header file of Pokemon class
*/

#include <iostream>
#include <string>
#include "Dice.h"

class Pokemon
{
	public:
		//constructor
		Pokemon();

		//determines amount of hp taken from oppenent during attack, if any.
		bool attack(Pokemon oponent);

		//sets values for name, hp, attack level, and defense level.
		void userBuild();

		//all set and get methods
		int getHp();
		int setHp(int x);

		int getALevel();
		int setALevel();

		int getDLevel();
		int setDLevel();

		int setABonus();
		int setDBonus();

		int getABonus();
		int getDBonus();

		void getName();
		void setName();

		int getTotal();
		int setTotal(int y);

	private:
		//creates variables needed for Pokemon class
		std::string name;
		int hp, aLevel, dLevel, aBonus, dBonus, a1, a2, a3, total, get;
		//Creates a 20-sided dice and a 6-sided dice.
		Dice d20;
		Dice d6;
};
