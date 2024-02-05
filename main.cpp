#include <iostream>
#include <string>
void removing_non_adjacent_zeros(std::string& string_with_zeros);
std::string scientific_notation(const std::string math_double);
void test_scientific_notation(void);

int main() {
	test_scientific_notation();
}

void removing_non_adjacent_zeros(std::string& string_with_zeros) {
	//This is done so that 2.0e-5 is output instead of 2.e5
	for (int i = string_with_zeros.size()-1; i > 1;i--)
	{
		if (string_with_zeros[i] == '0') {
			string_with_zeros.erase(i, 1);
		}
		else { break; }
	}
}

std::string scientific_notation(const std::string math_double) {
	int exp{};
	int point{};
	std::string new_math_double{ math_double };
	std::string result;
	
	point = new_math_double.find('.');
	if (!(point > 0)) { point = new_math_double.size(); }

	//Here the integer part of the number is checked to see if a positive exponent is needed
	for (int i = 0; i < point;)
	{
		if (new_math_double[i] != '0') { exp = (point - 1) - i; break; }
		else {
			new_math_double.erase(i, 1);
			point--;
		}
	}

	if (exp >= 0) {
		new_math_double.erase(point, 1);
	}
	if (exp == 0 && point == 0) {
		exp--;
		for (int i = point; i < new_math_double.size() - 1;)
		{
			if (new_math_double[i] != '0') { break; }
			exp--;
			new_math_double.erase(i, 1);
		}
	}
	removing_non_adjacent_zeros(new_math_double);
	std::string newFractionalPart = new_math_double.substr(1, new_math_double.size() - 1);
	//String Tricks
	result = (new_math_double[0] + ('.' + newFractionalPart + 'e') + std::to_string(exp));
	return result;
}

void test_scientific_notation() {
	std::cout << (scientific_notation("12.122220000") == "1.212222e1") << '\n';
	std::cout << (scientific_notation("0000000000.000020000") == "2.0e-5") << '\n';
	std::cout << (scientific_notation("0001.12") == "1.12e0") << '\n';
	std::cout << (scientific_notation("1.0") == "1.0e0") << '\n';
	std::cout << (scientific_notation("0000212400.1010101002000") == "2.124001010101002e5") << '\n';
	std::cout << (scientific_notation("0000000000000000000010000.000000000000000000000000") == "1.0e4") << '\n';
	std::cout << (scientific_notation("10.") == "1.0e1") << '\n';
}
