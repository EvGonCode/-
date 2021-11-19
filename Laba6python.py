def getFirst(x):
    if(x % 10 == x):
        return x
    else:
        x = int(x / 10)
        x = findFirst(x)
    return x
print("Введіть перше натуральне число")
a = int(input())
print("Введіть друге натуральне число")
b = int(input())
print("Введіть третє натуральне число")
c = int(input())
print("Сума перших цифр трьох натуральних чисел: ", end = "")
print(getFirst(a) + getFirst(b) + getFirst(c))

