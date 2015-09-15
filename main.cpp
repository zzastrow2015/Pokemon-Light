/**	File Name: main.cpp
*	Author: Zach Zastrow
*       KUID: 2314432
*	Email Address: zast@ku.edu
*	Homework Assignment Number: Lab 02 
*	Description: Main file creates two pokemon and a 10-sided dice.  The dice is then rolled to determine the order of attack.  The main function will call on functions from the Pokemon and Dice classes to build the pokemon's characteristics, change the pokemons' hp, etc.
*	Last Changed: 19 February 2014
*/

#include <iostream>
#include <string>
#include "Pokemon.h"
#include "Dice.h"

int main(){

//Create all variables and classes needed.
Pokemon Player1 = Pokemon();
Pokemon Player2 = Pokemon();
Dice TenSided = Dice(10);
int rollValue;

//Create Player1 and Player2
std::cout << '\n';
std::cout << "Player 1, build your Pokemon!" << '\n';
Player1.userBuild();

std::cout << '\n';
std::cout << "Player 2, build your Pokemon!" << '\n';
Player2.userBuild();

//rolls dice to see who attacks first first.
std::cout << '\n';
std::cout << "Player 1 will roll a D10, 6 or higher to go first." << '\n';
rollValue = TenSided.roll();

//if the dice is > 5, Player 1 goes first. Otherwise, Player 2 goes first.
if(rollValue > 5){
	std::cout << '\n';
	std::cout << "Player 1 rolls a " << rollValue << ". Player 1 will go first." << '\n';
	std::cout << '\n';

	//Creates each round.  Loop ends when one player defeates the other, or if 10 rounds complete.
	for(int x =1; x <= 10; x++){
		std::cout << '\n';
		std::cout << "Round " << x << "!" << '\n';
		std::cout << '\n';

		if(Player1.attack(Player2) == true){
			break;
		}
		if(Player2.attack(Player1) == true){
			break;
		}
		if(x == 10){
			std::cout << "Both Pokemon are still standing! It's a draw!" << '\n';
		}
		//sets each pokemon's new hp.
		Player1.setHp(Player1.getHp() - Player2.getTotal());
		Player2.setHp(Player2.getHp() - Player1.getTotal());
		Player1.setTotal(0);
		Player2.setTotal(0);

	}

}else{
	std::cout << "Player 1 rolls a " << rollValue << ". Player 2 will go first." << '\n';
	
	//Creates each round.  Loop ends when one player defeates the other, or if 10 rounds complete.
	for(int x =1; x <= 10; x++){
		std::cout << '\n';
		std::cout << "Round " << x << "!" << '\n';
		std::cout << '\n';
		if(Player2.attack(Player1) == true){
			break;
		}
		if(Player1.attack(Player2) == true){
			break;
		}
		if(x == 10){
			std::cout << "Both Pokemon are still standing! It's a draw!" << '\n';
		}
		//sets each pokemon's new hp.
		Player1.setHp(Player1.getHp() - Player2.getTotal());
		Player2.setHp(Player2.getHp() - Player1.getTotal());
		Player1.setTotal(0);
		Player2.setTotal(0);
	}
}


return 0;
}
