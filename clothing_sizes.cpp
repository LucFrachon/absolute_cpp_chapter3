/*
Programming project 5: Clothing sizes
Calculate clothing sizes based on user's height, weight, age
*/

#include <iostream>
using namespace std;

const float IN_TO_CM = 2.54;
const float LB_TO_KG = 0.453592;

float hat_size(float weight, float height);
//Precondition: Height is assumed not to be zero.
//Returns the estimated hat size.

float jacket_size(float weight, float height, int age);
//Returns the estimated jacket size (chest in cm).

float waist(float weight, float age);
//Returns the estimated waist size in cm.

int main()
{
	float height, weight;
	int age;

	cout << "Enter your height in cm, your weight in kg and your age:\n";
	cin >> height >> weight >> age;
	cout << "Your hat size: " << hat_size(weight, height) << endl;
	cout << "Your jacket size in cm: " << jacket_size(weight, height, age) << endl;
	cout << "Your waist size in cm: " << waist(weight, age) << endl;

	return 0;
}

float hat_size(float weight, float height)
{
	return (weight / LB_TO_KG) / (height / IN_TO_CM) * 2.9;
}

float jacket_size(float weight, float height, int age)
{
	// Adjust for age: add factor for each full decade over 30:
	int age_adjust = (age - 30) / 10;
	// Formula below applies to measurements in inches:
	float result_inches = (height / IN_TO_CM) * (weight / LB_TO_KG) / 288 + age_adjust / 8.0;
	return result_inches * IN_TO_CM;  // Convert result to cm
}

float waist(float weight, float age)
{
	// Adjust for age: Ass factor for each 2 full years over 28:
	int age_adjust = (age - 28) / 2;
	// Formula below applies to measurements in inches:
	float result_inches = (weight / LB_TO_KG) / 5.7 + age_adjust / 10.0;
	return result_inches * IN_TO_CM;  // Convert result to cm 
}