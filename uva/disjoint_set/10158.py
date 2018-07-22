import io
import sys
import collections

# war

# Simulate the redirect stdin.
if len(sys.argv) > 1:
    filename = sys.argv[1]
    inp = ''.join(open(filename, "r").readlines())
    sys.stdin = io.StringIO(inp)


class UnionFind:
    def __init__(self, V):
        self.parent = {}
        self.rank = {}
        for v in V:
            self.parent[v] = v
            self.rank[v] = 0

    def find(self, x):
        if x == -1:
            return -1

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



def setFriends(U, E, x, y):
    if areEnemies(U, E, x, y):
        return False

    px = U.find(x)
    py = U.find(y)

    qx = U.find(E[px])
    qy = U.find(E[py])

    U.union(px, py)

    if qx == -1 :
        E[px] = qy
    elif qy == -1:
        E[py] = qx
    else:
        U.union(qx, qy)


def setEnemies(U, E, x, y):
    if areFriends(U, E, x, y):
        return False
    
    px = U.find(x)
    py = U.find(y)

    qx = U.find(E[px])
    qy = U.find(E[py])

    if qx == -1 and qy == -1:
        E[px] = py
        E[py] = px
    elif qx == -1:
        E[px] = py
        U.union(qy, px)
    elif qy == -1:
        E[py] = px
        U.union(qx, py)
    else:
        U.union(qx, py)
        U.union(qy, px)



def areFriends(U, E, x, y):
    return U.isSameSet(x, y)
    

def areEnemies(U, E, x, y):
    px = U.find(x)
    py = U.find(y)

    qx = U.find(E[px])
    qy = U.find(E[py])

    if U.isSameSet(px, qy) or U.isSameSet(py, qx):
        return True

    return False




def main():
    n = int(input())
    V = [i for i in range(n)]
    U = UnionFind(V)
    E = [-1] * n
    while True:
        [c, x, y] = [int(s) for s in input().split() if s!= ""]
        
        if c ==0 and x == 0 and y ==0:
            return 0
        if c == 1:
            res = setFriends(U, E, x, y)
            if res == False:
                print("-1")

        elif c == 2:
            res = setEnemies(U, E, x, y)
            if res == False:
                print("-1")

        elif c == 3:
            if areFriends(U, E, x, y):
               print("1")
            else:
                print("0")
        else: 
            if areEnemies(U, E, x, y):
                print("1")
            else:
                print("0") 




if __name__ == "__main__":
    main()