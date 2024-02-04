#include <iostream>
#include <string>

int main() {

	std::string decimal{};
	int exp{};
	int point{};

	std::cout << "Write floating point number ";
	std::getline(std::cin, decimal);
	//Determining the index of a point
	for (int i = 0; i < decimal.size(); i++)
	{
		if (decimal[i] == '.') point = i;
	}
	//Calculating the number of characters that will leave the mantissa and go to the exponent
	exp = point - 1;
	std::string newDecimal = decimal;
	newDecimal[1] = '.';
	float isPoint = false;
	for (int i = 1; i < decimal.size(); i++)
	{
		if (i != point) {
			if (!isPoint) {
				newDecimal[i + 1] = decimal[i];
			}
			else {
				newDecimal[i] = decimal[i];
			}
		}
		else {
			isPoint = true;
		}
	}
	std::string exponent{ 'e' + std::to_string(exp) };
	newDecimal += exponent;
	std::cout << newDecimal;
	// input: 12341.131231231
	// output: 1.2341131231231e4
}
