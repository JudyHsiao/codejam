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
        names = [s for s in input().split(" ")]


        print("Case #{}: {} {} {}".format(i, one, two, three))
        


if __name__ == "__main__":
    main()