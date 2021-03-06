/*
3.1. Predefined functions
Self-test exercises: Write various functions performing actions on integers.
*/

#include <iostream>
#include <cmath>
using namespace std;

int sum_three(int number1, int number2, int number3);
// Takes three integers and computes their sum.

char pos_neg(int test_number);
// Tests whether an integer is positive or negative (or zero) and returns 'P'
// in the first case, 'N' in the second case.

int main()
{
	int n1, n2, n3, result;

	cout << "Enter three integers:\n";
	cin >> n1 >> n2 >> n3;
	result = sum_three(n1, n2, n3);
	cout << n1 << " + " << n2 << " + " << n3 << " = "
		<< result << endl;
	cout << "Positive or Negative/zero?\n"
		<< pos_neg(result);

	return 0;
}

int sum_three(int number1, int number2, int number3)
{
	return number1 + number2 + number3;
}

char pos_neg(int test_number)
{
	if (test_number > 0)
		return 'P';
	else
		return 'N';
}