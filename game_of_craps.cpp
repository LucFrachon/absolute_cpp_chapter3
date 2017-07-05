/*
Programming project 9: Game of Craps
Simulate 10,000 games of craps and calculate win probability.
In the long term, the player wins only 49.2% of rounds. Winning odds are therefore
0.969:1. The bank wins in the long term!
*/

#include <iostream>
#include <cstdlib>
using namespace std;

const int SIDES = 6;  //Number of sides on the dice used in the game
const int NUM_DICE = 2;  //Number of dice used in the game (identical dice)

int throw_dice();
//Returns the sum of NUM_DICE throws of SIDES-sided dice using a pseudo-random generator.

int one_round();
//Simulates a full round of craps.
//Returns the outcome of the game: player wins (1) or loses (0)

bool first_throw_win_condition(int score);
//Precondition: Score is an integer.
//Returns a boolean that indicates if the player won on the first dice throw.

bool first_throw_lose_condition(int score);
//Precondition: Score is an integer.
//Returns a boolean that indicates if the player lost on the first dice throw.

int main()
{
	int num_rounds, win_counter = 0;  //How many games were won by player

	cout << "WELCOME TO CRAPPY CRAPS SIMULATOR\n"
		<< "How many rounds of craps would you like to simulate?\n";
	cin >> num_rounds;

	for (int i = 0; i < num_rounds; i++)  //Simulate as many games as requested by user
		win_counter += one_round();

	//Display outcomes
	cout << "Completed " << num_rounds << " rounds of craps.\n"
		<< "Player won " << win_counter << " rounds,\n"
		<< "and lost   " << num_rounds - win_counter << " rounds.\n"
		<< "Win probability:\n"
		<< win_counter / static_cast<float>(num_rounds) << endl
		<< "Winning odds:\n"
		<< win_counter / static_cast<float>(num_rounds - win_counter) << endl;

	return 0;
}


int throw_dice()
{
	int score = 0;
	for (int i = 0; i < NUM_DICE; i++)
		score += 1 + rand() % SIDES;  //Add up random throws of SIDE-sided dice
	return score;
}

bool first_throw_win_condition(int score)
{
	return ((score == 7) || (score == 11));
}

bool first_throw_lose_condition(int score)
{
	return ((score == 2) || (score == 3) || (score == 12));
}

int one_round()
{
	int throw_result, point;
	int win_lose = 2;  //Indicator takes value 0 if player loses, 1 if they win and 2 otherwise

	//First throw
	throw_result = throw_dice();

	if (first_throw_win_condition(throw_result))
	{
		win_lose = 1;
	}
	else if (first_throw_lose_condition(throw_result))
	{
		win_lose = 0;
	}
	else
	{
		point = throw_result;  //The result becomes "the point"
		//The game continues
	}

	//Subsequent throws
	while (win_lose == 2)  //Keep throwing as long as neither 7 nor the point are thrown
	{
		throw_result = throw_dice();
		if (throw_result == 7)
			win_lose = 0;
		else if (throw_result == point)
			win_lose = 1;
	}

	return win_lose;
}

