from cs50 import get_string
import sys

def main():

    if len(sys.argv)!=2:
        print("Usage: ./caesar k")
        sys.exit(1)

    s = get_string('plaintext: ')

    print('ciphertext: ',end="")

    for x in s:

        if not x.isalpha():
            print(x,end="")
            continue

        if x.isupper():
            offset = 65
        else:
            offset = 97

        y = ord(x) - offset
        y = (y+int(sys.argv[1]))%26

        x = chr(y+offset)

        print(x,end="")

    print()
    return 0







if __name__ == "__main__":
    main()
