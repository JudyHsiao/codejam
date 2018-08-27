import io
import sys
import collections


# Simulate the redirect stdin.
if len(sys.argv) > 1:
    filename = sys.argv[1]
    inp = ''.join(open(filename, "r").readlines())
    sys.stdin = io.StringIO(inp)

def main():
    T = int(input())  # read a line with a single integer
    for t in range(1, T + 1):
        [N, K] = [int(s) for s in input().split(" ")]
        A = [int(s) for s in input().split(" ")]

        A.sort()
        #print(A)
        day = 0
        i = 0 
        count = 0

        while i < N:
            j=0
            while j < K and i < N:
                if A[i] > day:
                    j+=1
                    count+=1
                    i+=1
                else:
                    i+=1
            day +=1

        print("Case #{}: {}".format(t, count))
        


if __name__ == "__main__":
    main()