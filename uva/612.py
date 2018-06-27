import io
import sys
import collections


# Simulate the redirect stdin.
if len(sys.argv) > 1:
    filename = sys.argv[1]
    inp = ''.join(open(filename, "r").readlines())
    sys.stdin = io.StringIO(inp)

def count_inversion(A):
    swap = 0
    for i in range(len(A)):
        for j in range(i, len(A)):
            if A[i] > A[j]:
                swap+=1
    
    return swap


def main():
    t = int(input())
    for i in range(t):
        input()
        [n, m] = [int(s) for s in input().split()]
        L = []
        for j in range(m):
            line = input()
            swap = count_inversion(list(line))
            L.append((swap, line)) 
        #print(L)
        L = sorted(L, key=lambda x: x[0])
        #print(L)
        for l in L:
            print(l[1])
        print()


if __name__ == "__main__":
    main()
