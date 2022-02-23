import Functions


MainFile = "testFile.txt"
PairFile = "pairStrings.txt"
NonPairFile = "nonPairStrings.txt"
n = 0
Functions.liveWriteInFile(MainFile)
n = Functions.requestN()

Functions.copyPairStringsInFile(MainFile, PairFile)
Functions.copyNonPairStringsInFile(MainFile, NonPairFile)
print("\nОсновний файл")
Functions.printFile(MainFile)

print("\nФайл з парними рядками")
Functions.printFile(PairFile)

print("Файл з непарними рядками")
Functions.printFile(NonPairFile)

Functions.sortFileByStrings(PairFile)
print("Файл з парними рядками відсортований")
Functions.printFile(PairFile)

Functions.sortFirstNStringsnFile(NonPairFile, n)
print("Файл з непарними рядками відсортований")
Functions.printFile(NonPairFile)