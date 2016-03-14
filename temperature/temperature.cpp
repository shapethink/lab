#include <iostream>
using namespace std;

float celsius_to_fahrenheit(float degC) {
	return 32 + degC*9/5;
}

float fahrenheit_to_celsius(float degF) {
	return (degF-32)*5/9;
}

int main() {
	cout << "Enter temperature: " << flush;
	float temp;
	cin >> temp;
	cout << temp << "°C is approximately "
		<< celsius_to_fahrenheit(temp) << "°F" << endl;
	cout << temp << "°F is approximately "
		<< fahrenheit_to_celsius(temp) << "°C" << endl;
}
