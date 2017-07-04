/*
3.1. Predefined functions
Self-test exercise: Compute the square roots of every number for 1 to 10
*/

#include <iostream>
#include <cmath>
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