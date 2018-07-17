class UnionFind:
    def __init__(self, V):
        self.V = set(V)
        self.parent = {}
        self.rank = collections.defaultdict(int)
        for v in V:
            self.parent[v] = v
            self.rank[v] = 0

    def find(self, v):
        self.V.add(v)

        if v not in self.parent:
            self.parent[v] = v

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
    
    def sizeOfSet(self):
        for v in self.V:
            self.find(v)
        C = collections.Counter(self.parent.values())
        return len(C.keys())
