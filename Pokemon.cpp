/**
*	@file : Pokemon.cpp
*	@author :  Zach Zastrow zast@ku.edu
*	@id: 2314432
*	@date : 07 February 2014
*	Purpose: Implementation of Pokemon class
*/

#include <string>
#include "Pokemon.h"

//constructor sets all ints to 0, name to "", and creates the needed dices.
Pokemon::Pokemon(){

	int hp = 0;
	int aLevel = 0;
	int dLevel = 0;
	int a1 = 0;
	int a2 = 0;
	int a3 = 0;
	int get = 0;
	std::string name = "";
	d20 = Dice(20);
	d6 = Dice(6);

}

//Determines the name and characteristics of the Pokemon.
void Pokemon::userBuild(){

	//names the Pokemon
	std::cout << "=====================" << '\n';
	std::cout << '\n';
	std::cout << "Please name your Pokemon: ";
	setName();

	//Determines the hp of the Pokemon
	std::cout << "How many hit points will it have? (1-50): ";
	std::cin >> get;
	setHp(get);
	//If the hp is an invalid number, prompts user again until the hp is acceptable.
	while(getHp() < 1 || getHp() > 50){
	std::cout << "Sorry, your Pokemon must have between 1 and 50 hit points. Please re-enter: ";
	std::cin >> get;	
	setHp(get);
	}

	//Prompts user to choose the attack level and defense level.  Continues to prompt the user until valid numbers are chosen.
	std::cout << "Split 50 points between attack level and defense level." << '\n';
	do
	{
		
		std::cout << "Enter your attack level (1-49): ";	
		setALevel();
		while(getALevel() < 1 || getALevel() > 49){
		std::cout << "Attack level must be between 1 and 49. Please re-enter: ";
		setALevel();
		}

		std::cout << "Enter your defense level (1-49): ";
		setDLevel();
		while(getDLevel() < 1 || getDLevel() > 49){
		std::cout << "Defense level must be between 1 and 49. Please re-enter: ";
		setDLevel();
		}

		if(getALevel() + getDLevel() > 50){
			std::cout << "Sorry, cannot split more than 50 points between attack level and defense level!" << '\n';
		}
	}while(getALevel() + getDLevel() > 50);

}

//Attack function that determines how much damage is dealt to the opposing pokemon.
bool Pokemon::attack(Pokemon opponent){
	//sets up attack and defense bonus for each pokemon.
	std::cout << name << " is attacking " << opponent.name << '\n';
	setABonus();
	std::cout << name << " rolls and attack bonus of " << getABonus() << '\n';
	opponent.setDBonus();
	std::cout << opponent.name << " rolls a defense bonus of " << opponent.getDBonus() << '\n';
	
	//if the sum of the attack level and bonus of the attacking pokemon are greater than the defense level and bonus of the defending pokemon, the attack will hit.  Otherwise, the attack misses.
	if(getALevel() + getABonus() > opponent.getDLevel() + opponent.getDBonus()){
		//randomly roll a 6-sided dice three times in order to determine the total amount of damage dealt to the opposing pokemon.		
		std::cout << "The attack hits dealing 3-d6 damage!" << '\n';
		a1 = d6.roll();
		a2 = d6.roll();
		a3 = d6.roll();
		total = a1 + a2 + a3;
		std::cout << "The rolls are " << a1 << ", " << a2 << ", and " << a3 << " totalling: " << total << " damage!" << '\n';
		opponent.setHp(opponent.getHp() - total);
		if(opponent.getHp() > 0){
		std::cout << opponent.name << " has " << opponent.getHp() << " hit points left." << '\n';
		}else{
		std::cout << opponent.name << " is defeated!" << '\n';
		return true;		
		}	
	}else{
		std::cout << "The attack missed!" << '\n';
	}
	return false;
}

//set and get functions

void Pokemon::setName(){
	std::cin >> name;
}

int Pokemon::setHp(int x){
	hp = x;
}

int Pokemon::getHp(){
	return hp;
}

int Pokemon::setALevel(){
	std::cin >> aLevel;
}

int Pokemon::getALevel(){
	return aLevel;
}

int Pokemon::setDLevel(){
	std::cin >> dLevel;
}

int Pokemon::getDLevel(){
	return dLevel;
}

int Pokemon::setABonus(){
	aBonus = d20.roll();
}

int Pokemon::getABonus(){
	return aBonus;
}

int Pokemon::setDBonus(){
	dBonus = d20.roll();
}

int Pokemon::getDBonus(){
	return dBonus;
}

int Pokemon::getTotal(){
	return total;
}

int Pokemon::setTotal(int y){
	total = y;
}
