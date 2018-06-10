import io
import sys
import collections

# Kickstart Practice Round 2018
# https://code.google.com/codejam/contest/4374486/dashboard
# Simulate the redirect stdin.
if len(sys.argv) > 1:
    filename = sys.argv[1]
    inp = ''.join(open(filename, "r").readlines())
    sys.stdin = io.StringIO(inp)
def sort_tickets(tickets):
    [start, end] = zip(*tickets)
    c = collections.Counter(start+end)
    a = c.most_common()[-1][0]
    b = c.most_common()[-2][0]

    h ={}
    for i, name in enumerate(start):
        h[name] = i

    if a in h:
        s = a
    else:
        s = b


    ans = []
    for i in range(len(start)):
            k = h[s]
            ans.append(tickets[k])
            s = tickets[k][1]
    
    A = []
    for a in ans:
        A.append(a[0]+'-'+a[1])
    
    return A
    

def main():
    t = int(input())  # read a line with a single integer
    for i in range(1, t + 1):
        n = int(input())
        tickets=[]
        for j in range(n):
            start = input()
            end = input()
            tickets.append((start, end))
        ans = sort_tickets(tickets)


        print("Case #{}: {}".format(i, ' '.join(ans)))
        


if __name__ == "__main__":
    main()