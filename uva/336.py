import io
import sys
import collections


# Simulate the redirect stdin.
if len(sys.argv) > 1:
    filename = sys.argv[1]
    inp = ''.join(open(filename, "r").readlines())
    sys.stdin = io.StringIO(inp)

def bfs(G, V, s, ttl):
    q= collections.deque()
    q.append(s)
    dis = {}
    for v in V:
        dis[v] = -1
    dis[s] = 0
    while len(q) > 0 :
        n = q.popleft()
        for v in G[n]:
            if dis[v] == -1 :
                dis[v] = dis[n]+1
                q.append(v)

    count = 0
    for d in dis.values():
        if d == -1 or d > ttl:
            count +=1
    return count


def main():
    case = 1 
    while True:
        NC = int(input())
        if NC == 0:
            exit(0)
        A=[]
        while True:
            A += [int(s) for s in input().split() if s !=""]
            if A[-1] == 0 and A[-2] == 0:
                input()
                break
        G = collections.defaultdict(dict)
        V = set()
        for i in range(0, 2*NC, 2):
            a = A[i]
            b = A[i+1]
            G[a][b] = 1
            G[b][a] = 1
            V.add(a)
            V.add(b)
        Q=A[2*NC:]
        for i in range(0, len(Q)-2, 2):
            s= Q[i]
            ttl = Q[i+1]
            n = bfs(G, V, s, ttl)
            print("Case {}: {} nodes not reachable from node {} with TTL = {}.".format(case, n, s, ttl))
            case +=1





 
if __name__ == "__main__":
    main()   