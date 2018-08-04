SUM = 0
MIN = 1
MAX = 2


class SegmentTree(object):
    def __init__(self, N):
        self.tree = [0] * (4*N*N)


    def build(self, code, A, i, j, x1, x2, y1, y2):
        if x1 == x2 and y1 == y2:
            if code == SUM: # RANGE SUM
                self.tree[i][j] = A[x1][y1]  
            else:
                self.tree[i][j] = (x1, y1)  # is RANGE_MIN/MAXIMUM, store index
        elif x1 == x2:
            
        else:
            self.build(code, A, 2*i, 2*j, x1, (x1+x2)//2, y1, (y1+y2) //2)
            self.build(code, A, 2*i+1, 2*j, (x1+x2)//2+1, x2, y1, (y1+y2) //2)
            self.build(code, A, 2*i, 2*j+1, x1, (x1+x2)//2, (y1+y2) //2+1, y2)
            self.build(code, A, 2*i+1, 2*j+1, (x1+x2)//2+1, x2, (y1+y2) //2+1, y2)

            NW = self.tree[2*i][2*j]
            NE = self.tree[2*i+1][2*j]
            SW = self.tree[2*i][2*j+1]
            SE = self.tree[2*i+1][2*j+1]


            if code == SUM:
                self.tree[i][j] = NW + NE + SW + SE
            else:
                NWValue = A[NW[0]][NW[1]]
                NEValue = A[NE[0]][NE[1]]
                SWValue = A[SW[0]][SW[1]]
                SEValue = A[SE[0]][SE[1]]
                if code == MIN: # RANGE_MIN
                    V = min(NWValue, NEValue, SWValue, SEValue)
                else:
                    V = max(NWValue, NEValue, SWValue, SEValue)

                if V == NWValue:
                    self.tree[i][j] = NW
                elif V == NEValue:
                    self.tree[i][j] = NE
                elif V == SWValue:
                    self.tree[i][j] = SW
                else:
                    self.tree[i][j] = SE
                
    
    def update(self, code, A, node, b, e, i, v):
        if i > e or i < b:
            return 
        if b == i and e == j:
            self.tree[node] = v
            A[i] = v
            return

        self.update(code, A, 2* node, b, (b+e)//2 , i ,v)
        self.update(code, A, 2* node +1, (b+e)//2 +1, e , i ,v)
        
        if code == SUM :
            self.tree[node] += (v - A[i]) 
            return
        elif code == MIN:
            if A[i] < self.tree[node]:
                self.tree[node] = A[i]
            return
        else:
            if A[i] > self.tree[node]:
                self.tree[node] = A[i]
            return
    def query(self, code, A, node, b, e, i, j):
        if i > e or j < b:
            return None
        if b >= i and e <= j:
            return self.tree[node]

        p1 = self.query(code, A, 2* node, b, (b+e)//2 , i ,j)
        p2 = self.query(code, A, 2* node +1, (b+e)//2 +1, e , i ,j)

        if p1 == None:
            return p2
        if p2 == None:
            return p1
        
        if code == SUM :
            return p1 + p2
        elif code == MIN:
            return p1 if A[p1] <= A[p2] else p2
        else:
            return p1 if A[p1] >= A[p2] else p2


def main():
    A = [8,7,3,9,5,1,10]
    SGT = SegmentTree(7)
    SGT.build(MIN, A, 1, 0, 6)
    print(SGT.query(MIN, A, 1, 0, 6, 1, 3))

if __name__ == "__main__":
    main()