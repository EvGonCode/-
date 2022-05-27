#include "Header.h"
#include <iostream>
#include <windows.h>
#include <fstream>
#include <vector>
#include <iomanip>


using namespace std;


void addNewAmpoulesToStorageList(vector<StoredAmpoule>* list) {
	string answer;
	while (1) {
		StoredAmpoule ampoule;
		cout << "Enter name: ";
		cin >> ampoule.name; cout << endl;
		cout << "Enter hours of shelf life after opening: " << endl;
		while (1) {
			cout << "Hours: ";
			cin >> ampoule.openDuration.tm_hour; cout << endl;
			if (ampoule.openDuration.tm_hour > 23 or ampoule.openDuration.tm_hour < 0) {
				cout << "Ampouls shelf life after opening must be among 0 and 23 hours!" << endl << "Try another value" << endl;
			}
			else {
				break;
			}
		}
		while (1) {
			cout << "Minutes: ";
			cin >> ampoule.openDuration.tm_min; cout << endl;
			if (ampoule.openDuration.tm_min > 59 or ampoule.openDuration.tm_min < 0) {
				cout << "Hour contents max 59 and min 0 minutes!" << endl << "Try another value" << endl;
			}
			else {
				break;
			}
		}
		cout << "Enter shelf life while closed(in years): ";
		cin >> ampoule.ShelfLifeDurationYears; cout << endl;
		list->push_back(ampoule);



		cout << "Enter one more?(Yes/No): ";
		cin >> answer; cout << endl;
		if (answer == "No" or answer == "no" or answer == "-") break;
	}
}

int getFileSize(ifstream* file) {
	int current_ptr = file->tellg();
	file->seekg(0, ios::end);
	int size = file->tellg();
	file->seekg(current_ptr, ios::beg);
	return size;
}

string readString(ifstream* file) {
	int size;
	file->read((char*)&size, sizeof(size));
	char* buf = new char[size + 1];
	buf[size] = '\0';
	file->read(buf, size);
	string str = buf;
	delete[] buf;
	return str;
}

void writeString(ofstream* file, string str) {
	int size = str.size();
	file->write((char*)&size, sizeof(size));
	file->write(str.c_str(), size);
}

void addStoredAmpoulesListToFile(string filename, vector<StoredAmpoule> list, bool deleteOld) {
	ofstream fout;
	if (deleteOld) {
		fout.open(filename, ios_base::binary);
	}
	else {
		fout.open(filename, ios_base::binary | ios_base::app);
	}

	for (int i = 0; i < list.size(); i++) {
		writeString(&fout, list[i].name);
		fout.write((char*)&(list[i].openDuration), sizeof(list[i].openDuration));
		fout.write((char*)&(list[i].ShelfLifeDurationYears), sizeof(list[i].ShelfLifeDurationYears));
	}

	fout.close();
}

void getStoredAmpoulesListFromFile(string filename, vector<StoredAmpoule>* list) {
	ifstream fout;
	fout.open(filename, ios_base::binary);

	StoredAmpoule ampoule;
	int file_size = getFileSize(&fout);


	while (fout.tellg() < file_size) {
		ampoule.name = readString(&fout);
		fout.read((char*)&(ampoule.openDuration), sizeof(ampoule.openDuration));
		fout.read((char*)&(ampoule.ShelfLifeDurationYears), sizeof(ampoule.ShelfLifeDurationYears));
		list->push_back(ampoule);
	}

	fout.close();
}

void printStorage(vector<StoredAmpoule> list) {
	char str [100];
	for (int i = 0; i < list.size(); i++) {
		strftime(str, sizeof(str), "Shelf life after opening: %H:%M", &list[i].openDuration);

		cout << i + 1 << ") " << endl;

		cout << "Name: " << list[i].name << endl
		 << str << endl 
			<< "Shelf life while closed: " << list[i].ShelfLifeDurationYears << "y" 
			<< endl;
	}
}


void addOpenedAmpoulesToOpenedList(vector<StoredAmpoule> storedList, vector<OpenedAmpoule> *openedList) {
	OpenedAmpoule openedAmpoule;
	int time;
	for (int i = 0; i < storedList.size(); i++) {
		cout << i + 1 << ") " << storedList[i].name << endl;

		cout << "Hours after opening(-1 if closed): ";
		cin >> time; cout << endl;
		if (time < 0 or time >= 24) continue;
		openedAmpoule.whenOpened.tm_hour = time;

		cout << "Enter minutes afet opening: ";
		cin >> time; cout << endl;
		if ((int)(time / 60) + openedAmpoule.whenOpened.tm_hour > 24) continue;
		openedAmpoule.whenOpened.tm_hour += (int)(time / 60);
		openedAmpoule.whenOpened.tm_min = time % 60;

		openedAmpoule.name = storedList[i].name;

		openedList->push_back(openedAmpoule);
	}
}


int tmToMinutes(tm time) {
	return (time.tm_hour * 60) + time.tm_min;
}

tm minutesTotm(int minutes) {
	tm time = { 0,0,0,0,0,0 };
	time.tm_hour = (int)(minutes / 60);
	time.tm_min = minutes % 60;
	return time;
}

void addNotOverdueAmpoulesFromOpenedListToFile(vector<StoredAmpoule> storedList, vector<OpenedAmpoule> openedList, string filename) {
	if (openedList.size() != 0) {
		ofstream fout;
		fout.open(filename, ios_base::binary);
		int idOpen = 0;
		int t1;
		int t2;

		for (int i = 0; i < storedList.size(); i++) {
			if (storedList[i].name == openedList[idOpen].name) {
				t1 = tmToMinutes(storedList[i].openDuration);
				t2 = tmToMinutes(openedList[idOpen].whenOpened);
				if (t1 > t2) {
					openedList[idOpen].endOFShelfLife = minutesTotm(t1 - t2);

					writeString(&fout, openedList[idOpen].name);
					fout.write((char*)&(openedList[idOpen].whenOpened), sizeof(openedList[idOpen].whenOpened));
					fout.write((char*)&(openedList[idOpen].endOFShelfLife), sizeof(openedList[idOpen].endOFShelfLife));

					idOpen++;
				}
			}
		}

		fout.close();
	}
}


void getOpenedAmpoulesListFromFile(vector<OpenedAmpoule> *openedList, string filename) {
	ifstream fout;
	fout.open(filename, ios_base::binary);

	OpenedAmpoule ampoule;
	int file_size = getFileSize(&fout);


	while (fout.tellg() < file_size) {
		ampoule.name = readString(&fout);
		fout.read((char*)&(ampoule.whenOpened), sizeof(ampoule.whenOpened));
		fout.read((char*)&(ampoule.endOFShelfLife), sizeof(ampoule.endOFShelfLife));
		openedList->push_back(ampoule);
	}

	fout.close();
}

void printOpenedAmpoulesList(vector<OpenedAmpoule> openedList) {
	char str[100];
	for (int i = 0; i < openedList.size(); i++) {
		cout << i + 1 << ") " << endl <<
			"Name: " << openedList[i].name << endl;
		    printf("Opened: %d:%d", openedList[i].whenOpened.tm_hour, openedList[i].whenOpened.tm_min); cout << " ago" << endl;
			printf("Must be uset in: %d:%d", openedList[i].endOFShelfLife.tm_hour, openedList[i].endOFShelfLife.tm_min); cout << endl;
	}
}

bool isAddingNewOpenedAmpoulesNeeded() {
	cout << "Is adding new opened ampouls needed?(Yes/No): ";
	string answer;
	cin >> answer; cout << endl;

	if (answer == "Yes" or answer == "yes" or answer == "Y" or answer == "y" or answer == "+") {
		return true;
	}

	return false;
}

bool isAddingNewAmpoulesNeeded() {
	string answer;
	cout << "Want to add new ampoules?(Yes/No): ";
	cin >> answer;
	if (answer == "Yes" or answer == "yes" or answer == "Y" or answer == "y" or answer == "+") {
		return true;
	}

	return false;
}

bool isDeletingInfoInFileNeeded() {
	string answer;
	cout << "Want to delete previous ampouls from file?(Yes/No)" << endl;
	cin >> answer;
	if (answer == "Yes" or answer == "yes" or answer == "Y" or answer == "y" or answer == "+") {
		return true;
	}

	return false;
}
