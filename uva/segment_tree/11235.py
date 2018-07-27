import io
import sys
import collections


# Simulate the redirect stdin.
if len(sys.argv) > 1:
    filename = sys.argv[1]
    inp = ''.join(open(filename, "r").readlines())
    sys.stdin = io.StringIO(inp)

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


def mostFrequent(A, sgt, F, L, R, s, t):
    fa = 0
    fb = 0
    fc = 0

    n = len(A)-1
    if L[s] != s:
        fa = min(R[s],t) - s +1

    if L[s] != s and R[t]!=t:
        b = sgt.query(MAX, F, 1, 0, n, R[s]+1, L[t]-1)
    elif L[s] != s:
        b = sgt.query(MAX, F, 1, 0, n, R[s]+1, t)
    elif R[t]!=t:
        b = sgt.query(MAX, F, 1, 0, n, s, L[t]-1)
    else:
        b = sgt.query(MAX, F, 1, 0, n, s, t)

    if b != None:
        fb = F[b]

    if R[t]!=t:
        fc = t - max(s, L[t]) +1

    
    #print(s,t, fa, fb, fc)

    return max(fa, fb ,fc)


def main():
    while True:
        T = input().split()
        if len(T) == 1:
            exit(0)
        n = int(T[0])
        q = int(T[1])

        A = [int(s) for s in input().split()]
        freq = collections.defaultdict(int)
        for a in A:
            freq[a]+=1
        F = [0] * len(A)
        L = [0] * len(A)
        R = [0] * len(A)
        
        for i, a in enumerate(A):
            F[i] = freq[a]
            if i == 0 or A[i]!=A[i-1]: 
                L[i] = i
            else:
                L[i] = L[i-1]
        
        for i in range(len(A)-1, -1, -1):
            if i == len(A)-1 or A[i] !=A[i+1]:
                R[i] = i
            else:
                R[i] = R[i+1]
        sgt = SegmentTree(n)
        sgt.build(MAX, F, 1, 0, n-1)
        #print(A)
        #print(F)
        #print(L)
        #print(R)
        for _ in range(q):
            [s, t] = [int(s) for s in input().split()]
            print(mostFrequent(A, sgt, F, L, R, s-1, t-1))


        




if __name__ == "__main__":
    main()

