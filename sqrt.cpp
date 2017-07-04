/* 
3.1. Predefined functions
Self-test exercise: Compute the square roots of every number for 1 to 10
*/

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	for (int n = 1; n <= 10; n++)
		cout << "Square root of " << n << " = " << sqrt(n) << endl;


	return 0;
}