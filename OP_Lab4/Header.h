#include <iostream>

using namespace std;

class Numeral_16 {
private:
    string hexadecimal = "";

public:
    string dectohex(int num);
    int hextodec(string num);

    Numeral_16(string number) {
        this->hexadecimal = number;
    }

    Numeral_16(int number) {
        this->hexadecimal = dectohex(number);
    }

    Numeral_16() {
    }


    string getNumber() {
        return hexadecimal;
    }
    int getDeciNumber() {
        return hextodec(this->hexadecimal);
    }


    void setNumber(string number) {
        this->hexadecimal = number;
    }
    void setNumber(int number) {
        this->hexadecimal = dectohex(number);
    }

    Numeral_16 operator++(int number){
        number = hextodec(this->hexadecimal);
        string temp = this->hexadecimal;
        number++;
        this->hexadecimal = dectohex(number);
        return temp;
    }

    void operator+=(Numeral_16 hdNum) {
        int num1 = hextodec(this->hexadecimal);
        int num2 = num1 + hextodec(hdNum.hexadecimal);
        this->hexadecimal = dectohex(num2);
    }

    Numeral_16 operator+(Numeral_16 hdNum) {
        Numeral_16 tmp;
        int num;
        num = hextodec(this->hexadecimal) + hextodec(hdNum.hexadecimal);
        tmp.hexadecimal = dectohex(num);
        return tmp;
    }
};

inline string Numeral_16::dectohex(int num) {
    string hexadec;
    string c;

    while (num != 0) {
        int temp = 0;
        temp = num % 16;
        if (temp < 10) {
            c = temp + 48;
            hexadec.insert(0, c);
        }
        else {
            c = temp + 55;
            hexadec.insert(0, c);
        }
        num = num / 16;
    }
    return hexadec;
}

inline int Numeral_16::hextodec(string num) {
    int base = 1;
    int decimal = 0;
    for (int i = num.size() - 1; i >= 0; i--) {
        if (num[i] >= '0' && num[i] <= '9') {
            decimal += (num[i] - 48) * base;
            base = base * 16;
        }
        else if (num[i] >= 'A' && num[i] <= 'F') {
            decimal += (num[i] - 55) * base;
            base = base * 16;
        }
    }
    return decimal;
}