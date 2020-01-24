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

	cout << "Welcome to the Gamblers Ruin\n";

	//Create new GamblersRuin object
	GamblersRuin gambler;
	int totalRuns = 100;
	int player1Wins;
	int N;


	totalRuns = 1000;
	player1Wins = 0;
	N = 0;
	cout << "How many runs would you like to perform? ";
	cin >> totalRuns;
	cout << "\nHow many coins should Gambler A start with? ";
	cin >> N;

	for (int i = 0; i < totalRuns; i++)
	{
		//Keep track of number of times player 1 wins
		if (gambler.Rungame(N, 100 - N))
			player1Wins++;
	}

	//Output results
	
	cout << "\nn1 = " << N << " n2 = " << 100 - N <<"\n";
	cout <<"Gambler A won  " << player1Wins << " times.\n";
	cout << "Gambler B won " << totalRuns - player1Wins << " times.\n";
}
