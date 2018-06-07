import io
import sys
import collections

#https://code.google.com/codejam/contest/8274486/dashboard#s=p0
# Simulate the redirect stdin.
if len(sys.argv) > 1:
    filename = sys.argv[1]
    inp = ''.join(open(filename, "r").readlines())
    sys.stdin = io.StringIO(inp)
def sale(n, prices):
    h = collections.defaultdict(list)
    ans = []
    for i, p in enumerate(prices):
        h[p].append(i)

    for i, p in enumerate(prices):
        if i in h[p]:
            ans.append(str(p))
            o = p / 3 * 4
            h[o].pop()

    return ans

def main():
    t = int(input())  # read a line with a single integer
    for i in range(1, t + 1):
        n = int(input())
        prices = [int(s) for s in input().split(" ")]
        ans = sale(n, prices)


        print("Case #{}: {}".format(i, " ".join(ans)))
        


if __name__ == "__main__":
    main()