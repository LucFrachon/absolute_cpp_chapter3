/*
3.1. Predefined functions
Self-test exercise: Ask for a seed and output a list of 10 probabilities.
*/

#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
	int seed;

	cout << "Choose a random seed:\n";
	cin >> seed;

	srand(seed);

	for (int i = 0; i < 10; i++)
		cout << (RAND_MAX - rand()) / static_cast<double>(RAND_MAX) 
			<< endl;
	return 0;
}