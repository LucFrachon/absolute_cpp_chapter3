/*
3.2. Programmer-defined functions
Self-test exercises: Void functions
*/

#include <iostream>
#include <cmath>
using namespace std;

void product(int n1, int n2, int n3);
//Precondition: n1, n2, n3 are integers.
//Postcondition: Displays the result of n1 * n2 * n3 on screen.

int main()
{
	int num1, num2, num3;

	cout << "Enter three integers and I'll show you their product:\n";
	cin >> num1 >> num2 >> num3;
	product(num1, num2, num3);

	return 0;
}

void product(int n1, int n2, int n3)
{
	cout << n1 * n2 * n3;
	return;  // Optional
}