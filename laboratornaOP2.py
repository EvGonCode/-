print("Введіть перше число")
a = int(input())
print("Введіть друге число")
b = int(input())
print("Введіть третє число")
c = int(input())
if((a + b) % 2 == 0): print("Наявність парної суми : true") 
elif((a + c) % 2 == 0): print("Наявність парної суми : true") 
elif((b + c) % 2 == 0): print("Наявність парної суми : true") 
else: print("Наявність парної суми : false")