import io
import sys

# Simulate the redirect stdin.
if len(sys.argv) > 1:
    filename = sys.argv[1]
    inp = ''.join(open(filename, "r").readlines())
    sys.stdin = io.StringIO(inp)

def main():
    maxn = 100005
    ans = [0] * maxn

    for m in range(1, maxn):
        x = m
        y = m
        while x > 0 :
            y+=x%10
            x= x //10

        if y<maxn and ans[y] == 0:
            ans[y] = m

    T = int(input())
    for _ in range(T):
        n = int(input())
        print(ans[n])

    return 0

if __name__ == "__main__":
    main()