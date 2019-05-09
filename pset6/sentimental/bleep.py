from cs50 import get_string
from sys import argv


def main():
    if len(argv)!=2:
        print('Usage: python bleep.py dictionary')
        exit(1)

    l = []
    r = []
    fptr = open(argv[1],"r")

    for x in fptr:
        l.append(x.rstrip("\n"))
        fptr.close

    for i in l:
        r.append(i.upper())

    print('What message would you like to censor?')
    x = get_string()
    l2 = x.split()

    for i in l2:
        if i in l or i in r:
            for j in range(len(i)):
                print('*',end="")
        else:
            print(i,end="")
        print(" ",end="")
    print()
    return 0




if __name__ == "__main__":
    main()
