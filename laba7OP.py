def artifitialGenerate(listLen):
    list = []
    for i in range(0, listLen):
        print("Введіть "),
        print((i+1)),
        print("-й елемент масиву: ")
        list.append(int(input()))
    return list


def changeBigAndSmall(list):
    if(len(list) == 1): return list
    elif(len(list) == 2):
        if(list[0] >= 0 and list[1] >= 0):
            list[0] += list[1]
            list[1] = list[0] - list[1]
            list[0] = list[0] - list[1]
            return list
        return list
    for i in range(0, len(list)):
        if(list[i] >= 0):
            small = list[i]
            smallIndex = i
            big = small
            bigIndex = smallIndex
            for j in range(0, len(list)):
                if(list[j] >= 0):
                    if(small > list[j]):
                        small = list[j]
                        smallIndex = j
                    elif(big < list[j]):
                        big = list[j]
                        bigIndex = j
            list[smallIndex] += list[bigIndex]
            list[bigIndex] = list[smallIndex] - list[bigIndex]
            list[smallIndex] = list[smallIndex] - list[bigIndex]
            return list
    return list


print("Введіть кількість елементів массиву: ")
listLen = int(input()) 
list = artifitialGenerate(listLen)

print("Згенерований массив:")
print(list)
print("Оброблений масив:")
print(changeBigAndSmall(list))

