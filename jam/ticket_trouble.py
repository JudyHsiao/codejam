import io
import sys
import collections

# 2017 io for women https://code.google.com/codejam/contest/12224486/dashboard#s=p0&a=2
# Simulate the redirect stdin.
if len(sys.argv) > 1:
    filename = sys.argv[1]
    inp = ''.join(open(filename, "r").readlines())
    sys.stdin = io.StringIO(inp)

def guess(F,S, tickets):
    count = 0
    for i in range(1,S+1):
        h = {}
        for t in tickets:
            if t[0] == i:
                if t not in h:
                    h[t] = True
            elif t[1] == i:
                if (t[1],t[0]) not in h:
                    h[(t[1],t[0])] = True

        #print(h)
        count = max(count, len(h))
    return count

def main():
    t = int(input())  # read a line with a single integer
    for i in range(1, t + 1):
        [F,S] = [int(s) for s in input().split(" ")]
        tickets=[]
        for j in range(F):
            [r,c] = [int(s) for s in input().split(" ")]
            tickets.append( (r,c))
        
        #print(tickets)
        ans = guess(F,S, tickets)
        
        print("Case #{}: {}".format(i, ans))
        


if __name__ == "__main__":
    main()