#include <iostream>
#include <string>

void EraseNullsFromEnd(std::string& dec, int point) {
	for (int i = dec.size()-1; i > point;i--)
	{
		if (dec[i] == '0') {
			dec.erase(i, 1);
		}
		else { break; }
	}
}

int main() {

	std::string decimal{};
	int exp{};
	int point{};

	std::cout << "Write floating point number ";
	std::getline(std::cin, decimal);
	//Determining the index of a point
	point = decimal.find('.');
	if (!(point>0)) { point = decimal.size(); }

	//проверка начала
	int tempPoint = point;
	for (int i = 0; i < tempPoint;)
	{
		if (decimal[i] != '0') { exp = tempPoint - 1 - i; break; }
		else { 
			decimal.erase(i, 1);
			tempPoint--;
		}
	}
	//Если число с 0 в целой части
	if (exp == 0) {
		point = 0;
		for (int i = point; i < decimal.size() - 1;)
		{
			if ((decimal[i] != '0') and (decimal[i]!='.')) { break; }
			exp--;
			decimal.erase(i, 1);
		}
	}
	std::string newDecimal;
	//СЦЕНАРИЙ, ПРИ КОТОРОМ ЭКСПОНЕНТА НЕОТРИЦАТЕЛЬНАЯ
	if (exp >= 0) {
		decimal.erase(point, 1);
		std::string rest = decimal.substr(1, decimal.size() - 1);
		//Делаем 2345123
		EraseNullsFromEnd(rest, 0);
		//Если число как меньше 10, то у него остальная часть равна пустой строке
		if (rest == "") {
			newDecimal = (decimal[0] +('e' + std::to_string(exp)));
		}
		else {
			newDecimal = (decimal[0] + ('.' + rest + 'e') + std::to_string(exp));
		}
	}

	//СЦЕНАРИЙ, ПРИ КОТОРОМ ЭКСПОНЕНТА ОТРИЦАТЕЛЬНАЯ
	if (exp < 0) {
		std::string rest = decimal.substr(1, decimal.size() - 1);
		newDecimal = (decimal[0] + ('.' + rest + 'e') + std::to_string(exp));

	}
	std::cout << newDecimal;
}
