import io
import sys
import collections


# Simulate the redirect stdin.
if len(sys.argv) > 1:
    filename = sys.argv[1]
    inp = ''.join(open(filename, "r").readlines())
    sys.stdin = io.StringIO(inp)

def myPrint(s, M , extra):
    print(s, end='')
    for _ in range(M-len(s)):
        print(extra, end='')


def main():
    try:
        while(1):
            n = int(input())
            filenames=[]
            M = 0
            for i in range(n):
                filenames.append(input())
                M= max(M,len(filenames[i]))

            cols = (60 - M)//(M+2) +1
            rows = (n-1) // cols +1

            filenames.sort()
            print("------------------------------------------------------------")
            for r in range(rows):
                for c in range(cols):
                    i = c* rows +r
                    if i < n :
                        myPrint(filenames[i], M if c == cols-1 else M+2, ' ' )
                print()
                


    except EOFError:
        return 0
        


if __name__ == "__main__":
    main()