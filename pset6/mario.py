from cs50 import get_int

while True:
    x = get_int('Height: ')
    if x>=1 and x<=8:
        break;

for i in range(1,x+1):
    for j in range(x):
        if j+i>=x:
            print("#",end="")
        else:
            print(" ",end="")
    print("  ",end="")
    for j in range(x):
        if i-j>0:
            print("#",end="")
        else: break
    print()
