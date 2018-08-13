import io
import sys
import collections


# Simulate the redirect stdin.
if len(sys.argv) > 1:
    filename = sys.argv[1]
    inp = ''.join(open(filename, "r").readlines())
    sys.stdin = io.StringIO(inp)

def main():

    t = int(input())  # read a line with a single integer
    for i in range(1, t + 1):
        n = int(input())
        H={}
        for j in range(n):
            [k,v] = [s for s in input().strip().split(" ")]
            H[k] = int(v)
        m = int(input())
        cost = 0
        for j in range(m):
            s = input()
            for c in s:
                if c in H:
                    cost +=H[c]

        print("{0:.2f}$".format(cost/100))
        
        


if __name__ == "__main__":
    main()