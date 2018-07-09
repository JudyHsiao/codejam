import io
import sys

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

def kruskal(G):
    U = UnionFind(G.V)
    mst = set()
    G.E.sort(key= lambda x: x[2])
    for e in G.E:
        (u, v, w) = e
        if U.union(u, v):
            mst.add(tuple(e))
    return mst

# Simulate the redirect stdin.
if len(sys.argv) > 1:
    filename = sys.argv[1]
    inp = ''.join(open(filename, "r").readlines())
    sys.stdin = io.StringIO(inp)

def main():
    while True:
        N = int(input())
        T = []
        for i in range(N-1):
            T.append( [int(s) for s in input().split()])
        k = int(input())
        K = []
        for i in range(k):
            K.append( [int(s) for s in input().split()])

        m = int(input())
        M = []
        for i in range(m):
            M.append( [int(s) for s in input().split()])

        G = Graph([i for i in range(1, N+1)] , M+K)
        #print(G.V)
        #print(G.E)

        mst = kruskal(G)
        print(sum([e[2] for e in T]))
        print(sum([e[2] for e in mst]))

        try:
            input()
            print()
        except:
            exit(0)


if __name__ == "__main__":
    main()
        
