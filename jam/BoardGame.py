import io
import sys
import collections
import itertools


# Simulate the redirect stdin.
if len(sys.argv) > 1:
    filename = sys.argv[1]
    inp = ''.join(open(filename, "r").readlines())
    sys.stdin = io.StringIO(inp)

def main():
    T = int(input())  # read a line with a single integer
    for t in range(1, T + 1):
        n = int(input())
        A = [int(s) for s in input().split(" ")]
        B = [int(s) for s in input().split(" ")]

        cnt = 0.0
        win = 0.0


        A.sort(reverse=True)
        #print(A)
        best = [0]*3
        for i,a in enumerate(A[0:2*n]):
            best[i%2]+=a
        best[2] = sum(A[2*n:3*n])

        bala=[sum(B[0:n]), sum(B[n:2*n]), sum(B[2*n:3*n])]
        cnt = 0.0
        win = 0.0

        print(best)
        print(bala)
        for C in itertools.permutations(best,3):
            cnt +=1
            tmp = 0
            for i in range(3):
                if C[i] > bala[i]:
                    tmp +=1
            if tmp >=2:
                win +=1

            
        print("Case #{0:1d}: {1:1.9f}".format(t, win/cnt))
        


if __name__ == "__main__":
    main()