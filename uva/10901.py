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
        [n, t, m] = [ int(s) for s in input().split()]
        L = collections.deque()
        R = collections.deque()
        for j in range(m):
            [n, side] = [for s in input().split()]
            if side == 'left':
                L.append(int(n))
            else:
                R.append(int(n))

        A = list(input())
        ans = valid(A)
        if ans == True:
            print("Yes")
        else:
            print("No")
        
        


if __name__ == "__main__":
    main()