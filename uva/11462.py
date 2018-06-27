import io
import sys
import collections


# Simulate the redirect stdin.
if len(sys.argv) > 1:
    filename = sys.argv[1]
    inp = ''.join(open(filename, "r").readlines())
    sys.stdin = io.StringIO(inp)


def main():
    while True:
        t = int(input())
        if t == 0 :
            exit(0)
        A=[int(s) for s in input().split()]
        B=[0] * 101
        for i in A:
            B[i] +=1

        L= []
        for k,v in enumerate(B):
            if v > 0:
                L += [str(k)] * v
        print(" ".join(L))


        


if __name__ == "__main__":
    main()