def isItSimple(x):
    for i in range (2, x - 1):
        if(x % i == 0): return False
    return True

def findRoot(x):
    y = 0
    while(x != 0):
        y += x % 10
        x = int(x/10)
    if(y % 10 != y):
        y = findRoot(y)
    return int(y)


result = []
start = int (100)
finish = int (200)
for i in range (start, finish):
        if(isItSimple(i)):
            result.append(findRoot(i))
print(result)

