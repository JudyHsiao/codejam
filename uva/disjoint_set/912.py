import io
import sys
import collections


# Simulate the redirect stdin.
if len(sys.argv) > 1:
    filename = sys.argv[1]
    inp = ''.join(open(filename, "r").readlines())
    sys.stdin = io.StringIO(inp)

class UnionFind:
    def __init__(self, V):
        self.parent = {}
        for v in V:
            self.parent[v] = v

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

        if r1 in set('ABCD'):
            self.parent[r2] = r1
        else:
            self.parent[r1] = r2
            
        return True


def main():
    case = 0
    while True:
        try:
            m = int(input().strip())
            A = []
            for _ in range(m):
                A.append(input().strip())
            B = []
            for _ in range(m):
                B.append(input().strip())
            if case > 0 :
                print()
            N = set()
            for i in range(m):
                N.add(A[i])   
                N.add(B[i])

            U = UnionFind(N)
            ans = True
            for i in range(m):
                p1 = U.find(A[i])
                p2 = U.find(B[i])
                if p1 in set('ABCD') and p2 in set('ABCD'):
                    if p1 != p2:
                        ans = False
                        break
                else:
                    U.union(p1, p2)

            

            if ans == False:
                print("NO")
            else:
                print("YES")
                K = sorted(U.parent.keys())
                for k in K:
                    p = U.find(k)
                    if k !=p and p in set('ABCD'):
                        print("{} {}".format(k,p))
                
            
            input()
            case+=1
        except:
            return 0
        
        



        
        


if __name__ == "__main__":
    main()