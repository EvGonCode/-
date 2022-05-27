#include <iostream>
#include<vector>
#include<random>
#include<ctime>
#include"Header.h"




using namespace std;

vector<Cone> getConesListFromConcole() {
	int size;
	cout << "Enter size of list: "; cin >> size; cout << endl;
	vector<Cone> list;
	int botX, botY, botZ, topX, topY, topZ, radius;
	for (int i = 0; i < size; i++) {
		cout << i + 1 << ")" << endl;
		cout << "Enter center x: "; cin >> botX; cout << endl;
		cout << "Enter center y: "; cin >> botY; cout << endl;
		cout << "Enter center z: "; cin >> botZ; cout << endl;
		cout << "Enter vortex point x: "; cin >> topX; cout << endl;
		cout << "Enter vortex point y: "; cin >> topY; cout << endl;
		cout << "Enter vortex point z: "; cin >> topZ; cout << endl;
		cout << "Enter radius: "; cin >> radius; cout << endl;

		list.push_back(Cone(botX, botY, botZ, topX, topY, topZ, radius));
	}
	return list;
}

void printListOfCones(vector<Cone> list) {
	for (int i = 0; i < list.size(); i++) {
		cout << "Cone " << i+1 << ")" << "\n";
		list[i].printCone();
	}
}

void printSpecificCone(vector<Cone> list) {
	Cone cone = list[0];
	
	for (int i = 0; i < list.size(); i++) {
		if (list[i].getGeneratrix() > cone.getGeneratrix()) {
			cone = list[i];
		}
	}

	cout << "Cone with the biggest generatrix: \n";
	cone.printCone();
}