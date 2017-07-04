/*
3.1. Predefined functions
Self-test exercise: Boolean functions
*/

#include <iostream>
#include <cmath>
using namespace std;

bool inOrder(int n1, int n2, int n3);
// Takes three integers and tests whether they are in ascending order or not.
// Returns true is they are, false otherwise.

int main()
{
	int num1, num2, num3;

	cout << "Enter three integers:\n";
	cin >> num1 >> num2 >> num3;
	cout << "Are the numbers are in ascending order (yes=1 / no=0): "
		<< inOrder(num1, num2, num3);
	return 0;
}

bool inOrder(int n1, int n2, int n3)
{
	bool sorted = false;

	if (n1 <= n2)
		if (n2 <= n3)
			sorted = true;
	return sorted;
}