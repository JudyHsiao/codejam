import io
import sys
import collections

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


# Simulate the redirect stdin.
if len(sys.argv) > 1:
    filename = sys.argv[1]
    inp = ''.join(open(filename, "r").readlines())
    sys.stdin = io.StringIO(inp)


def main():
    
    while True:
        n = int(input())
        U = UnionFind([i for i in range(1, n+1)])
        A = []
        B = []
        for i in range(n):
            A.append(input())
        for i in range(n):
            B.append(input())
        
        ans = True
        Map = {} 
        for i in range(n):
            if A[i] == B[i]:
                continue
            
            if A[i].isdigit() and B[i].isdigit():
                U.union(int(A[i]), int(B[i]))
            elif  A[i].isdigit():
                k = int(A[i])
                v = B[i]
                if k not in Map:
                    Map[k] = v
                else:
                    if Map[k]!=v:
                        ans = False
                        break
            elif B[i].isdigit():
                k = int(B[i])
                v = A[i]
                if k not in Map:
                    Map[k] = v
                else:
                    if Map[k]!=v:
                        ans = False
                        break
            else:
                ans = False
                break
                
        if ans == True:
            for v in U.V:
                p = U.find(v)
                if v in Map and p not in Map:
                    Map[p] = Map[v]

            for v in U.V:
                p = U.find(v)
                if p in Map and v in Map:
                    if Map[p] != Map[v]:
                        ans = False
                elif p in Map:
                    Map[v] = Map[p]
                elif v in Map:
                    Map[p] = Map[v]

        if ans == True:
            print("YES")
            K = sorted(Map.keys())
            for k in K:
                print("{} {}".format(k, Map[k]))
        else:
            print("NO")


        try:
            input()
        except:
            exit(1)
        
        print()





 
if __name__ == "__main__":
    main()   