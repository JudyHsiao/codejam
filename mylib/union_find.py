class UnionFind:
    def __init__(self, V):
        self.parent = {}
        self.rank = collections.defaultdict(int)
        for v in V:
            self.parent[v] = v
            self.rank[v] = 0

    def find(self, x):
        #if x == -1:
        #    return -1

        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])   
        return self.parent[x] 
    
    def isSameSet(self, x, y):
        return self.find(x) == self.find(y)

    def union(self, x, y):
        r1 = self.find(x)
        r2 = self.find(y)
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
