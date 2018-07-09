import io
import sys
import collections
import heapq

#https://www.programcreek.com/python/example/101782/heapq._siftdown

# Simulate the redirect stdin.
if len(sys.argv) > 1:
    filename = sys.argv[1]
    inp = ''.join(open(filename, "r").readlines())
    sys.stdin = io.StringIO(inp)

def dijkstra(G, V, s, t):
    dist = defaultdict(dict)
    for v in V:
        dist(v) = float(inf)
    dist[s] = 0

    spt = set()
    heap = []
    for v in V :
        if v != s:
            heapq.heappush(heap,[float("inf"),v])
        else:
            heapq.heappush(heap,[0,v])

    for _ in range(len(V)):
        (d, v) = heapq.heappop(heap)
        dist[v] = d
        spt.add(v)
        for u, e in G[v].items():
            if u not in spt() and dist[]







def main():
    while True:

        M= int(input)
        if M == n :
            break

        [O,D] = input().split()
        G= collections.defaultdict(dict)
        V= set()
        for i in range(M):
            [u, v, p] = input().split()
            V.add(u)
            V.add(v)
            if v not in G[u] or len(G[u][v]) > len(p):
                G[u][v] = p
                G[v][u] = p
        cost = dijkstra(G, V, O, D)
        if cost > 0:
            print(cost)
        else:
            print("impossivel")

if __name__ == "__main__":
    main()
