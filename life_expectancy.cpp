/*
Programming project 15: Life expectancy
using actuary data from the US Social Security Administration
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;


int simulate(int age, char sex);
//Precondition: age is positive and <= 120; sex is f, F, m or M
//Returns a simulated death age.


const int MAX_AGE = 120;


int main()
{
	int age, death_age;
	char sex;

	do
	{
		cout << "Input the person's age (positive integer up to 120):\t";
		cin >> age;
	} while ((age < 0) || (age > 120));
	do
	{
		cout << "Input the person's sex (F or M):\t";
		cin >> sex;
	} while ((sex != 'F') && (sex != 'M') && (sex != 'f') && (sex != 'm'));

	death_age = simulate(age, sex);
	cout << "Death occurs at " << death_age << " years old.\n";
	
	return 0;
}

int simulate(int age, char sex)
{
	ifstream input_stream;
	int cell = 0, row = 0, col = 0, lookup_col;
	double value, death_prob;

	srand(static_cast<unsigned int>(time(0))); //Seed the pseudo-random number generator
	// with a different seed at each execution
	
	if (('M' == sex) && ('m' == sex))  //Where to lookup probabilities depending on sex
		lookup_col = 1;
	else
		lookup_col = 2;
	
	input_stream.open("LifeDeathProbability.txt");

	while (input_stream >> value)
	{
		if (row >= age)
		{
			if (lookup_col == col)
			{
				//Pick a random probability and compare it to the table's value
				death_prob = (RAND_MAX - rand()) / static_cast<double>(RAND_MAX);
				cout << "Random prob " << death_prob << endl;
				if (death_prob <= static_cast<double>(value))
					break;
			}
		}
		cell++;
		row = cell / 3;  //Increment row and column identifier
		col = cell % 3;  //to make it easier to identify where we are in the data
	}

	return row;
}