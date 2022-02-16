#include <string>
#include <vector>
using namespace std;


void liveWriteInNewFile(string path);
void copyPairStrings(string outputPath, string inputPath);
void copyNonPairStrings(string outputPath, string inputPath);
void sortFileByAlphabet(string path);
void sortFirstNStringsOfWordsByAlphabet(string path, int n);
vector<string> splitStringByWords(string s);
vector<string> sortVectorByAlphabet(vector<string> mass);
string convertVectorToString(vector<string> mass);
bool isEmpty(fstream& file);
