#include <iostream>
#include "Header.h"

using namespace std;

int main()
{
    liveWriteInNewFile("myFile.txt");
    copyPairStrings("myFile.txt", "fileOfPairStrings.txt");
    copyNonPairStrings("myFile.txt", "fileOfNonPairStrings.txt");
    sortFileByAlphabet("fileOfPairStrings.txt");
    sortFirstNStringsOfWordsByAlphabet("fileOfNonPairStrings.txt",100);
}