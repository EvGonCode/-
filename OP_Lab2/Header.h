
#include <iostream>
#include <windows.h>
#include <vector>

using namespace std;

struct StoredAmpoule {
	string name = "None";
	tm openDuration = { 0,0,0,0,0,0 };
	int ShelfLifeDurationYears = 0;
};

struct OpenedAmpoule {
	string name;
	tm whenOpened = { 0,0,0,0,0,0 };
	tm endOFShelfLife = { 0,0,0,0,0,0 };
};


void addNewAmpoulesToStorageList(vector<StoredAmpoule>* list);

void addStoredAmpoulesListToFile(string filename, vector<StoredAmpoule> list, bool deleteOld);

void getStoredAmpoulesListFromFile(string filename, vector<StoredAmpoule>* list);

void writeString(ofstream* file, string str);

string readString(ifstream* file);

void printStorage(vector<StoredAmpoule> list);

bool isAddingNewAmpoulesNeeded();

bool isDeletingInfoInFileNeeded();

void addOpenedAmpoulesToOpenedList(vector<StoredAmpoule> storedList, vector<OpenedAmpoule>* openedList);

int tmToMinutes(tm time);

tm minutesTotm(int  minutes);

void addNotOverdueAmpoulesFromOpenedListToFile(vector<StoredAmpoule> storedList, vector<OpenedAmpoule> openedList, string filename);

void getOpenedAmpoulesListFromFile(vector<OpenedAmpoule>* openedList, string filename);

void printOpenedAmpoulesList(vector<OpenedAmpoule> openedList);

bool isAddingNewOpenedAmpoulesNeeded();
