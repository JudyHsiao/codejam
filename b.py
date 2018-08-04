import io
import sys
import collections
import bisect


# Simulate the redirect stdin.
if len(sys.argv) > 1:
    filename = sys.argv[1]
    inp = ''.join(open(filename, "r").readlines())
    sys.stdin = io.StringIO(inp)

def solve(p, h, x, y):
    idx_t = [i for i in range(1, len(p))]
    idx_t.sort(key= lambda i: p[i])

    Tx = [p[idx_t[0]]]
    Ty = [h[idx_t[0]]]
    for i in range(1, len(idx_t)):
        xa = Tx[-1]
        ya = Ty[-1]

        xb = p[idx_t[i]]
        yb = h[idx_t[i]]

        if xa + ya >= xb + yb :
            continue         
        else:
            if xb - yb <= xa - ya:
                Tx.pop()
                Ty.pop()
            Tx.append(xb)
            Ty.append(yb)

    count = 0
    for i in range(1, len(x)) :
        xx = x[i]
        k = bisect.bisect_left(Tx, xx)
        for j in range(max(0,k-10), min(k+10, len(Tx))):
        #for j in range(len(Tx)):
            pp = Tx[j]
            if Ty[j] >= abs(xx- pp) + y[i]:
                count+=1
                break
    return count

def main():
    T = int(input())  # read a line with a single integer
    for t in range(1, T + 1):
        [N, K] = [int(s) for s in input().split()]
        [p1, p2, A1, B1, C1, M1] = [int(s) for s in input().split()]
        [h1, h2, A2, B2, C2, M2] = [int(s) for s in input().split()]
        [x1, x2, A3, B3, C3, M3] = [int(s) for s in input().split()]
        [y1, y2, A4, B4, C4, M4] = [int(s) for s in input().split()]

        p= [0] * (N+1)
        p[1] = p1
        p[2] = p2
        for i in range(3, N+1):
            p[i] = (A1 * p[i - 1] + B1 * p[i - 2] + C1) % M1 + 1

        h = [0] * (N+1)
        h[1] = h1
        h[2] = h2
        for i in range(3, N+1):
            h[i] = (A2 * h[i - 1] + B2 * h[i - 2] + C2) % M2 + 1

        x = [0] * (K+1)
        x[1] = x1
        x[2] = x2
        for i in range(3, K+1):
            x[i] = (A3 * x[i - 1] + B3 * x[i - 2] + C3) % M3 + 1

        y = [0] * (K+1)
        y[1] = y1
        y[2] = y2
        for i in range(3, K+1):
            y[i] = (A4 * y[i - 1] + B4 * y[i - 2] + C4) % M4 + 1
        
        count = solve(p, h, x, y)

        print("Case #{}: {}".format(t, count))
        


if __name__ == "__main__":
    main()