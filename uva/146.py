import io
import sys
import collections


# Simulate the redirect stdin.
if len(sys.argv) > 1:
    filename = sys.argv[1]
    inp = ''.join(open(filename, "r").readlines())
    sys.stdin = io.StringIO(inp)

def next_permutation(A):
    for i in range(len(A)-1, -1 ,-1):
        for j in range(i, -1, -1):
            if A[j] < A[i]:
                #print(i, j, A[i], A[j], A)
                A[i],A[j] = A[j], A[i]
                #print(i, j, A[i], A[j], A)
                A[j+1:] = A[j+1:][::-1]
                return A
    
    return None




def main():
   for line in sys.stdin:
        line = line.strip()
        if line == "#":
           exit(0)
        
        tmp =  next_permutation(list(line))
        if tmp == None:
            print("No Successor")
        else:
            print("".join(tmp))
        


if __name__ == "__main__":
    main()
