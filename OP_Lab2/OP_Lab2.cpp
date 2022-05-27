#include "Header.h"
#include <iostream>
#include <ctime>
#include <vector>
using namespace std;

int main(){

	string fileNameStoredAmpoules = "storedAmpoules";
	string fileNameOpenedAmpoules = "openedAmppoules";

	vector<StoredAmpoule> StorageList;
	vector<StoredAmpoule> downloadStorageList;
	vector<OpenedAmpoule> Openedlist;
	vector<OpenedAmpoule> downloadOpenedlist;


	if (isAddingNewAmpoulesNeeded()) {
		addNewAmpoulesToStorageList(&StorageList);

		addStoredAmpoulesListToFile(fileNameStoredAmpoules, StorageList, isDeletingInfoInFileNeeded());
	}
	
	getStoredAmpoulesListFromFile(fileNameStoredAmpoules, &downloadStorageList);
	

	cout << "Updated stored ampoules file: \n";
	printStorage(downloadStorageList);

	cout << endl;

	if (isAddingNewOpenedAmpoulesNeeded()) {
		addOpenedAmpoulesToOpenedList(downloadStorageList, &Openedlist);
		addNotOverdueAmpoulesFromOpenedListToFile(downloadStorageList, Openedlist, fileNameOpenedAmpoules);
	}

	getOpenedAmpoulesListFromFile(&downloadOpenedlist, fileNameOpenedAmpoules);

	cout << "Updated opened ampoules file: \n";
	printOpenedAmpoulesList(downloadOpenedlist);



}
