import os.path
import copy

def liveWriteInFile(fileName):
    if(os.path.exists(fileName)):
        print(r"Файл з таким ім'ям вже існує, продовжити запис/почати спочатку?(1/2)")
        choise = int(input())
        if choise == 1:
            file = open(fileName, "a", encoding = "utf-8")
            try:
                print("Початок запису в файл")
                print("Введіть текст, або пустий рядок для завершення:")
                while (True):
                    s = input()
                    if (len(s) == 0):
                        break;
                    file.write(s)
                    file.write("\n")
            except:
                print("Помилка при введенні тексту")
            file.close()
            print("Кінець введення")


        else:
            file = open(fileName, "w", encoding="utf-8")
            try:
                print("Початок запису в файл")
                print("Введіть текст, або пустий рядок для завершення:")
                while (True):
                    s = input()
                    if (len(s) == 0):
                        break;
                    file.write(s)
                    file.write("\n")
            except:
                print("Помилка при введенні тексту")
            file.close()
            print("Кінець введення")


    else:
        file = open(fileName, "w", encoding="utf-8")
        try:
            print("Початок запису в файл")
            print("Введіть текст, або пустий рядок для завершення:")
            while (True):
                s = input()
                if (len(s) == 0):
                    break;
                file.write(s)
                file.write("\n")
        except:
            print("Помилка при введенні тексту")
        file.close()
        print("Кінець введення")

def sortArrOfWords(string):
    isChanged = True
    while(isChanged):
        isChanged = False
        for i in range(len(string)-1):
            cur = copy.copy(string[i])
            next = copy.copy(string[i+1])
            innerChange = False
            for j in range(min(len(cur), len(next))):
                if ord(cur[j]) > ord(next[j]):
                    string[i+1] = cur
                    string[i] = next
                    isChanged = True
                    innerChange = True
                    break
                elif ord(cur[j]) != ord(next[j]):
                    break
            if(innerChange == False and len(cur) > len(next)):
                if (isFirstStartFromAnother(cur, next)):
                    string[i + 1] = cur
                    string[i] = next
                    isChanged = True


def isFirstStartFromAnother(stringFirst, stringAnother):
    for i in range(len(stringAnother)):
        if(ord(stringFirst[i]) != ord(stringAnother[i])):
            return False
    return True

def sortFileByStrings(fileName):
    file = open(fileName, "r", encoding="utf-8")
    strings = file.readlines()
    file.close()
    sortArrOfWords(strings)
    file = open(fileName, "w", encoding="utf-8")
    for i in range(len(strings)):
        file.write(strings[i])
        if (strings[i][-1] != '\n'):
            file.write('\n')
    file.close()

def sortFirstNStringsnFile(fileName, n):
    file = open(fileName, "r", encoding="utf-8")
    strings = file.readlines()
    file.close()
    for i in range(min(n, len(strings))):
        buffer = (strings[i].split("\n")[0]).split(" ")
        sortArrOfWords(buffer)
        strings[i] = arrToString(buffer)
    file = open(fileName, "w", encoding="utf-8")
    for i in range(len(strings)):
        file.write(strings[i])
        if(i + 1< len(strings)):
            file.write("\n")
    file.close()


def printFile(fileName):
    try:
        file = open(fileName, "r", encoding="utf-8")
        print(file.read())
        file.close()
    except:
        print("Поилка у виведенні данних із файлу")

def arrToString(arr):
    string = ""
    for i in range(len(arr)-1):
        string += arr[i] + " "
    string += arr[len(arr)-1]
    return string

def copyPairStringsInFile(fileNameOut, fileNameIn):
    fOut = open(fileNameOut, "r", encoding="utf-8")
    fIn = open(fileNameIn, "w", encoding="utf-8")

    s = fOut.readlines()

    for i in range(len(s)):
        if i % 2 != 0:
            fIn.write(s[i])

    fOut.close()
    fIn.close()


def copyNonPairStringsInFile(fileNameOut, fileNameIn):
    fOut = open(fileNameOut, "r", encoding="utf-8")
    fIn = open(fileNameIn, "w", encoding="utf-8")

    s = fOut.readlines()

    for i in range(len(s)):
        if i % 2 == 0:
            fIn.write(s[i])

    fOut.close()
    fIn.close()


def requestN():
    print("Введіть змінну n: ", end = "")
    n = int(input())
    print()
    return n
