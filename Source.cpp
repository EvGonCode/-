#include <iostream>
#include <string>
#include <fstream>
#include "Header.h"
#include <Windows.h>
#include <vector>
#include <random>
#include <ctime>

using namespace std;

void liveWriteInNewFile(string path) {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	fstream write;
	write.open(path);

	if (isEmpty(write)) {
		write.close();
		cout << "Файл пустий" << endl;
		
		write.open(path, ofstream::out | ofstream::trunc);
		try {

			string s;
			cout << "Введіть текст або натисніть Enter для завершення" << endl;
			while (true) {
				getline(cin, s);
				if (s.length() == 0) {
					break;
				}
				write << s << "\n";
			}

		}
		catch (exception e) {
			cout << "Помилка при записуванні тексу в файл: " << e.what();
		}
	}
	else {
		write.close();

		string choose;
		while (true) {
			cout << "У файлі вже є записи, видалити іх?(+/-)" << endl;
			cin >> choose;
			cin.ignore();
			if (choose == "+" or choose == "так" or choose == "Так") {
				write.open(path, ofstream::out | ofstream::trunc);
				try {

					string s;
					cout << "Введіть текст або натисніть Enter для завершення" << endl;
					while (true) {
						getline(cin, s);
						if (s.length() == 0) {
							cout << "Void string";
							break;
						}
						write << s << "\n";
					}

				}
				catch (exception e) {
					cout << "Помилка при записуванні тексу в файл: " << e.what();
				}
				break;
			}

			else if (choose == "-" or choose == "ні" or choose == "Ні") {
				cout << "Початок введення з кінця файлу" << endl;

				write.open(path, ios::app);
				try {

					string s;
					cout << "Введіть текст або натисніть Enter для завершення" << endl;
					while (true) {
						getline(cin, s);
						if (s.length() == 0) {
							break;
						}
						write << s << "\n";
					}

				}
				catch (exception e) {
					cout << "Помилка при записуванні тексу в файл: " << e.what();
				}
				break;
			}
			else {
				cout << "Помилка при введенні параметру, спробуйде ще раз" << endl;
			}
		}
	}

	
	write.close();
}

void copyPairStrings(string outputPath, string inputPath) {
	fstream output;
	fstream input;
	output.open(outputPath);
	input.open(inputPath, ofstream::out | ofstream::trunc);

	bool isPairString = false;
	string s;
	while (!output.eof()) {
		getline(output, s);
		if (isPairString) {
			if (!output.eof()) {
				input << s << "\n";
			}
			else {
				input << s;
			}
			isPairString = false;
		}
		else {
			isPairString = true;
		}
	}
	output.close();
	input.close();
}

void copyNonPairStrings(string outputPath, string inputPath) {
	fstream output;
	fstream input;
	output.open(outputPath);
	input.open(inputPath, ofstream::out | ofstream::trunc);

	bool isPairString = false;
	string s;
	while (!output.eof()) {
		getline(output, s);
		if (!isPairString) {
			if (!output.eof()) {
				input << s << "\n";
			}
			else {
				input << s;
			}
			isPairString = true;
		}
		else {
			isPairString = false;
		}
	}
	output.close();
	input.close();
}

void sortFileByAlphabet(string path) {
	fstream file;
	file.open(path);
	vector<string> mass;

	while (!file.eof()) {
		string s;
		getline(file, s);
		if (s.length() != 0) {
			mass.push_back(s);
		}
	}
	file.close();

	mass = sortVectorByAlphabet(mass);

	file.open(path, ofstream::out | ofstream::trunc);
	for (int i = 0; i < mass.size(); i++) {
		if (i + 1 != mass.size()) {
			file << mass[i] + "\n";
		}
		else {
			file << mass[i];
		}
	}
	file.close();
}

void sortFirstNStringsOfWordsByAlphabet(string path, int n) {
	fstream file;
	file.open(path);
	vector<string> mass;

	while (!file.eof()) {
		string s;
		getline(file, s);
		if (s.length() != 0) {
			mass.push_back(s);
		}
	}
	file.close();

	for (int i = 0; i < n and i < mass.size(); i++) {
		vector<string> splittedstr = splitStringByWords(mass[i]);
		splittedstr = sortVectorByAlphabet(splittedstr);
		mass[i] = convertVectorToString(splittedstr);
	}

	file.open(path, ofstream::out | ofstream::trunc);

	for (int i = 0; i < mass.size(); i++) {
		if (i + 1 != mass.size()) {
			file << mass[i] << "\n";
		}
		else {
			file << mass[i];
		}
	}
	file.close();
}

vector<string> splitStringByWords (string s) {
	cout << "String is: " << s << endl;
	vector<string> mass;
	string buffer = "";
	for (int i = 0; i < s.length(); i++) {
		if (s.at(i) != ' ' and i + 1 != s.length()) {
			buffer += s.at(i);
		}
		else {
			if (i + 1 == s.length()) {
				buffer += s.at(i);
			}
			mass.push_back(buffer);
			cout << "Splitted Word: " << buffer << endl;
			buffer = "";
		}
	}
	return mass;
}

vector<string> sortVectorByAlphabet(vector<string> mass) {
	string buffer;
	bool ischanged = true;
	bool innerIschanged = false;

	while (ischanged) {
		ischanged = false;
		for (int i = 0; i < mass.size() - 1; i++) {
			innerIschanged = false;
			string current = mass[i];
			string next = mass[i + 1];
			for (int j = 0; j < current.size() and j < next.size(); j++) {
				if (int(tolower(current.at(0))) > int(tolower(next.at(0)))) {
					mass[i] = next;
					mass[i + 1] = current;
					ischanged = true;
					innerIschanged = true;
					break;
				}
			}
			if (current.size() > next.size() and innerIschanged == false) {
				bool currentBeginsFromNext = true;
				for (int j = 0; j < next.size(); j++) {
					if (tolower(current.at(j)) != tolower(next.at(j))) {
						currentBeginsFromNext = false;
						break;
					}
				}
				if (currentBeginsFromNext) {
					mass[i] = next;
					mass[i + 1] = current;
					ischanged = true;
				}
			}
		}
	}
	return mass;
}

string convertVectorToString(vector<string> mass) {
	string s = "";

	for (int i = 0; i < mass.size(); i++) {
		if (i + 1 != mass.size()) {
			s += mass[i] + " ";
		}
		else {
			s += mass[i];
		}
	}
	return s;
}

bool isEmpty(fstream& file)
{
	return file.peek() == std::ifstream::traits_type::eof();
}
