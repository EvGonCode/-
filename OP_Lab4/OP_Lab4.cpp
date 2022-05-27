#include <iostream>
#include "Header.h"

using namespace std;

int main()
{
	Numeral_16 number1 = Numeral_16(25);
	Numeral_16 number2 = Numeral_16("19");
	Numeral_16 number3;
	number3.setNumber(20);

	cout << "Number1 is: " << number1.getNumber() << "(" << number1.getDeciNumber() << ")" <<
		"\nNumber2 is: " << number2.getNumber() << "(" << number2.getDeciNumber() << ")" <<
		"\nNumber3 is: " << number3.getNumber() << "(" << number3.getDeciNumber() << ")" << endl;

	number1++;
	cout << "Number1 incremented is: " << number1.getNumber() <<"(" << number1.getDeciNumber() << ")" << endl;

	number2 += 1;
	cout << "Number2 incremented is: " << number2.getNumber() << "(" << number2.getDeciNumber() << ")" << endl;

	number3 = number1 + number2;
	cout <<"Number3 changed is: " << number3.getNumber() << "(" << number3.getDeciNumber() << ")" << endl;
}