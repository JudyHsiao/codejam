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
    
    def largestSet(self):
        for v in self.V:
            self.find(v)
        
        try:
            C = collections.Counter(self.parent.values())
            return max(C.values())
        except:
            return 0





# Simulate the redirect stdin.
if len(sys.argv) > 1:
    filename = sys.argv[1]
    inp = ''.join(open(filename, "r").readlines())
    sys.stdin = io.StringIO(inp)


def isConnected( A, B):
    d = (A[0] - B[0]) * (A[0] - B[0]) + (A[1] - B[1]) * (A[1] - B[1])

    if d >= (A[2] - B[2]) * (A[2] - B[2]) and d <= (A[2] + B[2]) * (A[2] + B[2]):
        return True

    return False



def main():
   while True:
        
        n = int(input())
        if n == -1 :
            exit(0)
        
        R = []
        for i in range(n):
            R.append([float(s) for s in input().split() if s!= ""])
        U=UnionFind([i for i in range(n)])
        for i in range(n):
            for j in range(i+1, n):
                if isConnected(R[i], R[j]):
                    U.union(i, j)

        l = U.largestSet() 
        
        if l > 1 or l ==0:
            print("The largest component contains {} rings.".format(l))
        else:  
            print("The largest component contains {} ring.".format(l))






        


if __name__ == "__main__":
    main()