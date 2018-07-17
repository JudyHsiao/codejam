import io
import sys
import collections


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
    def sizeOfSet(self):
        for v in self.V:
            self.find(v)

        C = collections.Counter(self.parent.values())
        return len(C.keys())



# Simulate the redirect stdin.
if len(sys.argv) > 1:
    filename = sys.argv[1]
    inp = ''.join(open(filename, "r").readlines())
    sys.stdin = io.StringIO(inp)


def main():
    t = int(input())
    input()
    for i in range(t):
        E = []
        V = set()
        v = input()

        for c in "ABCDEFGHIJKLMNOPQRSTUVWXYZ":
            V.add(c)
            if c == v:
                break

        for line in sys.stdin:
            line = line.strip()
            if line == "":
                break
            E.append(line)
            V.add(line[0])
            V.add(line[1])
        U = UnionFind(V)
        for e in E:
            U.union(e[0], e[1])
        
        print(U.sizeOfSet())
        if i < t-1:
            print()




        


if __name__ == "__main__":
    main()