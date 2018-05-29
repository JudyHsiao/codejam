import io
import sys
import collections
import math


# Simulate the redirect stdin.
if len(sys.argv) > 1:
    filename = sys.argv[1]
    inp = ''.join(open(filename, "r").readlines())
    sys.stdin = io.StringIO(inp)


def isone(l,k):
    if k == int(math.ceil(l/2)):
        return False
    elif k <= l//2:
        return isone(l//2, k)
    else:
        return not isone(l//2, l-k+1)
    
def googol(k):
    l = 0
    while l <= k:
        l = 2*l+1

    if isone(l, k):
        return 1
    else:
        return 0


def main():
    t = int(input())  # read a line with a single integer
    for i in range(1, t + 1):
        k = int(input())
        ans = googol(k)

        print("Case #{}: {}".format(i, ans))
        


if __name__ == "__main__":
    main()