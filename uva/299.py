import io
import sys
import collections


# Simulate the redirect stdin.
if len(sys.argv) > 1:
    filename = sys.argv[1]
    inp = ''.join(open(filename, "r").readlines())
    sys.stdin = io.StringIO(inp)

def bubble_sort(A):
    swap = 0
    for i in range(len(A)):
        for j in range(i, len(A)):
            if A[i] > A[j]:
                A[i], A[j] = A[j], A[i]
                swap+=1
    
    return swap


def main():
    t = int(input())
    for i in range(t):
        n = int(input())
        A = [int(s) for s in input().split()]
        swap = bubble_sort(A) 
        print("Optimal train swapping takes {} swaps.".format(swap))


if __name__ == "__main__":
    main()

