import io
import sys
import collections
import heapq


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
    dist = collections.defaultdict(dict)
    for v in G.V:
        for c in "abcdefghijklmnopqrstuvwxyz":
            if v != s: 
                dist[v][c] = float("inf")
            else:
                dist[v][c] = 0
      


    Q = []
    heapq.heappush(Q, (0, s, ""))
    dist[s][""] = 0  
    while len(Q):
        #print(Q)
        d, u, word = heapq.heappop(Q)
        if len(word) == 0:
            c = ""
        else:
            c = word[0]
        if d == dist[u][c]:  
            for v, w in G.adj[u]:
                for ch in "abcdefghijklmnopqrstuvwxyz":
                    if ch != w[0]:
                        if dist[u][ch] + len(w) < dist[v][w[0]]:
                            dist[v][w[0]] = dist[u][ch] + len(w)
                            heapq.heappush(Q, (dist[v][w[0]], v, w))

    return dist



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

        if O not in G.V or D not in G.V:
            print("impossivel")    
            continue
            
        dist = dijkstra(G, O)
        d = float("inf")
        for ch in "abcdefghijklmnopqrstuvwxyz":
            d = min(d, dist[D][ch])
        
        if d < float("inf"):
            print(d)    
        else:
            print("impossivel")    
            

if __name__ == "__main__":
    main()
