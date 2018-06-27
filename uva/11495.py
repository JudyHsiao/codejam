import io
import sys
import collections


# Simulate the redirect stdin.
if len(sys.argv) > 1:
    filename = sys.argv[1]
    inp = ''.join(open(filename, "r").readlines())
    sys.stdin = io.StringIO(inp)

swap = 0
def merge(A, B):
    C = []
    i = 0
    j = 0 
    while i < len(A) and j < len(B):
        if A[i] <= B[j]:
            C.append(A[i])
            i+=1
        else:
            global swap
            swap+=len(A)-i
            C.append(B[j])
            j+=1


    if i < len(A):
        C = C + A[i:]

    if j < len(B):
        C = C + B[j:]
    return C

def merge_sort(A):

    if len(A) <= 1:
        return A
    
    n = len(A)
    a = merge_sort(A[:n//2])
    b = merge_sort(A[n//2:])
    return merge(a, b)


def main():
    while True:
        A=[int(s) for s in input().split()]
        if A[0] == 0:
            exit(0)
        global swap 
        swap = 0
        merge_sort(A[1:]) 
        if swap %2 ==1:
            print("Marcelo")
        else:
            print("Carlos")


if __name__ == "__main__":
    main()
