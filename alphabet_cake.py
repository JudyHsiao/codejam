import io
import sys
import collections


# Simulate the redirect stdin.
if len(sys.argv) > 1:
    filename = sys.argv[1]
    inp = ''.join(open(filename, "r").readlines())
    sys.stdin = io.StringIO(inp)

def fill_alphabet(A, R, C):
    for r in range(R):
        for c in range(C):
            if A[r][c] == '?'


def main():
    t = int(input())  # read a line with a single integer
    for i in range(1, t + 1):
        [R, C] = [int(s) for s in input().split(" ")]
        A = []  
        for r in range(R):
            A.append(list(input()))
        
        fill_alphabet(A)
        
        


        #print("Case #{}: {} {} {}".format(i, one, two, three))
        


if __name__ == "__main__":
    main()