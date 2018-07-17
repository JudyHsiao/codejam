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


# Simulate the redirect stdin.
if len(sys.argv) > 1:
    filename = sys.argv[1]
    inp = ''.join(open(filename, "r").readlines())
    sys.stdin = io.StringIO(inp)


def main():
    t = int(input())
    input()

    for i in range(t):
        n = int(input())
        yes = 0
        no = 0
        U = UnionFind([i for i in range(1, n+1)])
        Q =[]
        for line in sys.stdin:
            line = line.strip()
            if line == "":
                break
            
            A = line.split()
            if A[0] == 'c':
                U.union(int(A[1]), int(A[2]))
            else:
                r1 = U.find(int(A[1]))
                r2 = U.find(int(A[2]))
                if r1 == r2:
                    yes += 1
                else:
                    no += 1
        print("{},{}".format(yes, no))
        if i < t-1:
            print()



 
if __name__ == "__main__":
    main()   