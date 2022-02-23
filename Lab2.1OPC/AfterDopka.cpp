#include <iostream>
#include "Header.h"
#include <Windows.h>

using namespace std;

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);


    string mainFile = "myFile.txt";
    string pairFile = "fileOfPairStrings.txt";
    string nonPairFile = "fileOfNonPairStrings.txt";
    int n;
    n = requestN();
    liveWriteInNewFile(mainFile);
    copyPairStrings(mainFile, pairFile);
    copyNonPairStrings(mainFile, nonPairFile);

    cout << "Головний файл" << endl;
    printFile(mainFile);

    cout << "Файл з парними рядками" << endl;
    printFile(pairFile);

    cout << "Файл з непарними рядками" << endl;
    printFile(nonPairFile);

    sortFileByAlphabet(pairFile);
    sortFirstNStringsOfWordsByAlphabet(nonPairFile,n);

    cout << "Файл з парними рядками відсортований" << endl;
    printFile(pairFile);

    cout << endl;

    cout << "Файл з непарними рядками відсортований" << endl;
    printFile(nonPairFile);
}