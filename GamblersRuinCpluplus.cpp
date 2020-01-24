// GamblersRuinCpluplus.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <time.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

class GamblersRuin
{
	//Random object must be created at start of class to prevent RNG being seeded the same with each call
	public:
		GamblersRuin()
		{
			srand(time(NULL));
		}

	//Tosscoin() simulates a random coin flip and
	//returns a true for heads or false for tails
	public:
		bool Tosscoin()
		{


			//Generate random positive int less than 2
			//Either 0 or 1
			int n = rand() % 2;
			if (n == 1)
				return true;
			else
				return false;
		}
	//Rungame simualtes 1 iteration of the gambers ruin.
	//Returns true if player 1 wins.
	//Returns false if player 2 wins.
	//n1 = number of coins for player 1.
	//n2 = number of coins for player 2.
	public:
		bool Rungame(int n1, int n2)
		{
			while (n1 > 0 && n2 > 0)
			{
				if (Tosscoin())
				{
					//Player 1 gains a coin
					n1++;
					//Player 2 loses a coin
					n2--;
				}
				else
				{
					//Player 1 loses a coin
					n1--;
					//Player 2 gains a coin
					n2++;
				}
			}
			//End the game
			if (n2 == 0)
			{
				//Player 1 wins
				return true;
			}
			else
			{
				//Player 2 wins
				return false;
			}
		}
};
int main()
{
	cout << "Hello World!\n";

	cout << "Welcome to the Gamblers Ruin\n";

	//Create new GamblersRuin object
	GamblersRuin gambler;
	int totalRuns;
	int player1Wins;


	/* Part 1
		* n1 = n2 = 100
		* 1000 simulations of the gamblers ruin
		* Outputs number of times player 1 wins and player 2 wins
		*/
	totalRuns = 1000;
	player1Wins = 0;

	for (int i = 0; i < totalRuns; i++)
	{
		//Keep track of number of times player 1 wins
		if (gambler.Rungame(100, 100))
			player1Wins++;
	}

	//Output results
	cout << "Part 1 :\n";
	cout << "n1 = 100, n2 = 100\n";
	cout <<"Player 1 won  " << player1Wins << " times.\n";
	cout << "Player 2 won " << totalRuns - player1Wins << " times.\n";

	/* Part 2
		* n1 = 150, n2 = 50
		* 1000 simulations of the gamblers ruin
		* Outputs number of times player 1 wins and player 2 wins
		*/
	totalRuns = 1000;
	player1Wins = 0;

	for (int i = 0; i < totalRuns; i++)
	{
		//Keep track of number of times player 1 wins
		if (gambler.Rungame(150, 50))
			player1Wins++;
	}
	cout << "\nPart 2 :\n";
	cout << "n1 = 150, n2 = 50\n";
	cout <<"Player 1 won " << player1Wins << " times.\n";
	cout << "Player 2 won " << totalRuns - player1Wins << " times.";
}
