#https://code.google.com/codejam/contest/3264486/dashboard

import io
import sys
import collections


# Simulate the redirect stdin.
if len(sys.argv) > 1:
    filename = sys.argv[1]
    inp = ''.join(open(filename, "r").readlines())
    sys.stdin = io.StringIO(inp)

def flip(C, k):
    C = list(C)
    ans = 0
    i = 0
    while i < len(C) -k+1:
        if C[i] == '-':
            ans +=1
            for j in range(k):
                if C[i+j] == '+':
                    C[i+j] = '-'
                else:
                     C[i+j] = '+'
        i+=1


    if '-' in C:
        return "IMPOSSIBLE"

    return ans


def main():
    t = int(input())  # read a line with a single integer
    for i in range(1, t + 1):
        [C, k] = [s for s in input().split(" ")]
        ans = flip(C, int(k))


        print("Case #{}: {}".format(i, ans))
        


if __name__ == "__main__":
    main()