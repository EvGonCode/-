#include <iostream>
#include<vector>
#include"Header.h"



using namespace std;

int main()
{
	vector<Cone> listOfCones = getConesListFromConcole();
	printListOfCones(listOfCones);
	cout << endl;
	printSpecificCone(listOfCones);
}

