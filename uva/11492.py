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

class Graph:
    def __init__(self):
        self.V = set()
        self.adj = collections.defaultdict(list)

    def addEdge(self, src, dest, word):
        newNode = [dest, word]
        self.adj[src].append(newNode)
 
        # Since graph is undirected, add an edge 
        # from dest to src also
        newNode = [src, word]
        self.adj[dest].append(newNode)

def dijkstra(G, s):
    dist = {}
    for v in G.V:
        dist[v] = [float("inf"), ""]
    dist[s] = [0,""]

    parent = {}

    Q = []
    heapq.heappush(Q, (dist[s][0], s, ""))
    while len(Q):
        print(Q)
        d, u, word = heapq.heappop(Q)
        if d == dist[u] :  
            for v, w in G.adj[u]:
                if dist[u] + len(w) < dist[v]:
                    dist[v] = dist[u] + len(w)
                    parent[v] = u
                    heapq.heappush(Q, (dist[v], v, w))

    return dist, parent



def main():
    while True:
        M = int(input())
        if M == 0 :
            break

        [O,D] = input().split()
        G = Graph()
        for i in range(M):
            [u, v, w] = input().split()
            G.addEdge(u,v,w)
            G.V.add(u)
            G.V.add(v)

        dist, parent = dijkstra(G, O)
        if dist[D] < float("inf"):
            print(dist[D])    
        else:
            print("impossivel") 
            

if __name__ == "__main__":
    main()
