SUM = 0
MIN = 1
MAX = 2


class SegmentTree(object):
    def __init__(self, N):
        self.tree = [0] * (4*N)


    def build(self, code, A, i, b, e):
        if b == e:
            if code == SUM: # RANGE SUM
                self.tree[i] = A[b]  
            else:
                self.tree[i] = b  # is RANGE_MIN/MAXIMUM, store index
        else:
            left  = 2 * i
            right = 2*i + 1
            self.build(code, A, left, b, (b+e)//2)
            self.build(code, A, right, (b+e)//2 +1, e)

            lContent = self.tree[left]
            rContent = self.tree[right]

            if code == SUM:
                self.tree[i] = lContent + rContent
            else:
                lValue = A[lContent]
                rValue = A[rContent]
                if code == 1: # RANGE_MIN
                    self.tree[i] = lContent if (lValue <= rValue) else rContent
                else:
                    self.tree[i] = lContent if (lValue >= rValue) else rContent

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