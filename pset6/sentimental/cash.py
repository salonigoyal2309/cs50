from cs50 import get_float
while True:
    x = get_float('Change owed: ')
    if isinstance(x,float) and x>0:
        break

x = x*100
cnt = 0
x = int(x)
while x>=25:
    x = x-25
    cnt = cnt+1

while x>=10:
    x = x-10
    cnt = cnt+1

while x>=5:
    x = x-5
    cnt = cnt+1

while x>=1:
    x = x-1
    cnt = cnt+1

print(cnt)
