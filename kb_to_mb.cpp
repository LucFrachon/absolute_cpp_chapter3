/* 
Programming project 1: kb and minutes to MB
*/

#include <iostream>
using namespace std;

const double KB_PER_MB = 8000;

double convert_to_mb(float bitrate, float duration);
//Precondition: bitrate (per second) and duration (in minutes) are assumed to be
//positive floats.
//Postcondition: Returns the file size in MB.

int main()
{
	float bitrate, duration;
	cout << "Enter the file's bitrate in kb per second and its duration in minutes:\n";
	cin >> bitrate >> duration;
	cout << "Estimated file size in MB:\n"
		<< convert_to_mb(bitrate, duration);
}

double convert_to_mb(float bitrate, float duration)
{
	return bitrate * 60 * duration / KB_PER_MB;
}