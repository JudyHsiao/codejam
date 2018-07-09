class UnionFind:
    def __init__(self, V):
        self.V = V
        self.parent = {}
        self.rank = {}
        for v in V:
            self.parent[v] = v
            self.rank[v] = 0

    def find(self, v):
        if self.parent[v] != v:
            self.parent[v] = self.find(self.parent[v])
        
        return self.parent[v] 

    def union(self, u, v):
        r1 = self.find(u)
        r2 = self.find(v)
        if r1 == r2:
            return False   # union fail: u v already belong to the same set
        
        if self.rank[r1] > self.rank[r2]:
            self.parent[r2] = r1
        elif self.rank[r1] < self.rank[r2]:
            self.parent[r1] = r2
        else:
            self.rank[r1]+=1
            self.parent[r2] = r1
        
        return True

class Graph:
    def __init__(self, V, E):
        self.V = V
        self.E = E
        self.graph = [[0 for column in range(vertices)] 
                      for row in range(vertices)]


def kruskal(G):
    U = UnionFind(G.V)
    mst = set()
    G.E.sort()
    for e in G.E:
        (w, u, v) = e
        if U.union(u, v):
            mst.add(e)
    return mst

graph = Graph(
    ['A', 'B', 'C', 'D', 'E', 'F', 'G'],
    [
(7, 'A', 'B'),
(5, 'A', 'D'),
(7, 'B', 'A'),
(8, 'B', 'C'),
(9, 'B', 'D'),
(7, 'B', 'E'),
(8, 'C', 'B'),
(5, 'C', 'E'),
(5, 'D', 'A'),
(9, 'D', 'B'),
(7, 'D', 'E'),
(6, 'D', 'F'),
(7, 'E', 'B'),
(5, 'E', 'C'),
(7, 'E', 'D'),
(8, 'E', 'F'),
(9, 'E', 'G'),
(6, 'F', 'D'),
(8, 'F', 'E'),
(11, 'F', 'G'),
(9, 'G', 'E'),
(11, 'G', 'F'),
]
)

print(kruskal(graph))