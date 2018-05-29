import io
import sys

#https://code.google.com/codejam/contest/8384486/dashboard
# Simulate the redirect stdin.
if len(sys.argv) > 1:
    filename = sys.argv[1]
    inp = ''.join(open(filename, "r").readlines())
    sys.stdin = io.StringIO(inp)

def cal_err(dist, opt):
    err = 0
    for i in range(len(dist)):
        err += (dist[i]-opt[i])**2
    return err


def burger_opt(k, opt):
    dist = [0]*k

    rank=[]
    for i in range(k):
        rank.append((opt[i], i))  # 0 2 1 1 2  => [(0,0) ,(2,1) , (1,2) , (1,3), (2,4) ]

    rank.sort()  # [(0,0), (1,2) , (1,3), (2,4) ,(2,1) ]

    j = 0
    for i in range(k//2):
        idx = rank[j][1]
        dist[idx] = i
        j += 1
        idx = rank[j][1]
        dist[idx] = i
        j += 1

    if j < k:
        idx = rank[j][1]
        dist[idx] = (k-1)//2

    err = cal_err(dist, opt)

    return err


def main():
    t = int(input())  # read a line with a single integer
    for i in range(1, t + 1):
        n = int(input())
        opt = [int(s) for s in raw_input().split(" ")]
        err = burger_opt(n, opt)

        print("Case #{}: {}".format(i, err))
        


if __name__ == "__main__":
    main()

    