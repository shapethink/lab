#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

void GetInches(ifstream&, int&, float&);

int main() {
	float average;
	float totalRain;
	int numberOfDays;
	ifstream rainFile;

	cout << fixed << showpoint;
	rainFile.open("data/rain.infile");

	GetInches(rainFile, numberOfDays, totalRain);

	if(totalRain == 0.0)
		cout << "There was no rain during this period."
			<< endl;
	else {
		average = totalRain / numberOfDays;
		cout << "The average rainfall over " << numberOfDays << " days was "
			<< setw(1) << setprecision(3) << average << endl;
	}

	return 0;
}

void GetInches(ifstream& rainFile, int& numberOfDays, float& totalRain) {
	rainFile >> numberOfDays;
	totalRain = 0.0;
	for(int day = 0; day < numberOfDays; day++)
	{
		float inches;
		rainFile >> inches;
		totalRain += inches;
	}
}