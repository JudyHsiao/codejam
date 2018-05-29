import io
import sys
import collections


# Simulate the redirect stdin.
if len(sys.argv) > 1:
    filename = sys.argv[1]
    inp = ''.join(open(filename, "r").readlines())
    sys.stdin = io.StringIO(inp)

def understudy(n, P):
    P = sorted(P)
    ans = 1.0
   
    for i in range(n):
        tmp = P[i] * P[len(P)-i-1]
        ans = ans * (1-tmp)

    return ans

def main():
    t = int(input())  # read a line with a single integer
    for i in range(1, t + 1):
        n = int(input())
        P = [float(s) for s in input().split(" ")]
        ans = understudy(n, P)

        print("Case #{}: {}".format(i, ans))
        


if __name__ == "__main__":
    main()