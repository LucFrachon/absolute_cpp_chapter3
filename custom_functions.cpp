/*
3.1. Predefined functions
Self-test exercise: Compute the square roots of every number for 1 to 10
*/

#include <iostream>
#include <cmath>
using namespace std;

int sum_three(int number1, int number2, int number3);
// Takes three integers and computes their sum.

int main()
{
	int n1, n2, n3, result;

	cout << "Enter three integers:\n";
	cin >> n1 >> n2 >> n3;
	result = sum_three(n1, n2, n3);
	cout << n1 << " + " << n2 << " + " << n3 << " = "
		<< result;

	return 0;
}

int sum_three(int number1, int number2, int number3)
{
	return number1 + number2 + number3;
}