import collections
import heapq

class Graph:
    def __init__(self, V):
        self.V = V
        self.adj = collections.defaultdict(list)

    def addEdge(self, src, dest, weight):
        newNode = [dest, weight]
        self.adj[src].append(newNode)
 
        # Since graph is undirected, add an edge 
        # from dest to src also
        newNode = [src, weight]
        self.adj[dest].append(newNode)
    
    
def dijkstra(G, s):
    dist = {}
    for v in G.V:
        dist[v] = float("inf")
    dist[s] = 0

    parent = {}

    Q = []
    heapq.heappush(Q, (dist[s], s))
    while len(Q):
        d, u = heapq.heappop(Q)
        if d == dist[u] :  
            for v, w in G.adj[u]:
                if dist[u] + w < dist[v]:
                    dist[v] = dist[u] + w
                    parent[v] = u
                    heapq.heappush(Q, (dist[v], v))

    return dist, parent






graph = Graph(
    [0,1,2,3,4,5,6,7,8]
)

graph.addEdge(0, 1, 4)
graph.addEdge(0, 7, 8)
graph.addEdge(1, 2, 8)
graph.addEdge(1, 7, 11)
graph.addEdge(2, 3, 7)
graph.addEdge(2, 8, 2)
graph.addEdge(2, 5, 4)
graph.addEdge(3, 4, 9)
graph.addEdge(3, 5, 14)
graph.addEdge(4, 5, 10)
graph.addEdge(5, 6, 2)
graph.addEdge(6, 7, 1)
graph.addEdge(6, 8, 6)
graph.addEdge(7, 8, 7)

dist, parent = dijkstra(graph, 0)

print(dist)