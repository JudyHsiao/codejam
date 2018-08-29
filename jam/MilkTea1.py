import io
import sys
import collections
import itertools


# Simulate the redirect stdin.
if len(sys.argv) > 1:
    filename = sys.argv[1]
    inp = ''.join(open(filename, "r").readlines())
    sys.stdin = io.StringIO(inp)

def apply(A, complains, p):
    count = sum(complains)
    B = A[::]
    for c, i in p:
        count = count + c - complains[i]
        if A[i] == '0':
            B[i] = '1'
        else:
            B[i]= '0'

    return B, count

def main():
    T = int(input())  # read a line with a single integer
    for t in range(1, T + 1):
        [N, M, P] = [int(s) for s in input().split(" ")]
        A=[]
        for i in range(N):
            A.append(input())
        F=set()
        for i in range(M):
            F.add(input())
        
        best = float("INF")
        fmt = '{' + "0:0" + str(P)+"b}"
        for i in range(2**P):
            s= fmt.format(i, '0'+str(P)+'b')
            cnt = 0
            if s not in F:
                for j in range(N):
                    for k in range(P):
                        if A[j][k] != s[k]:
                            cnt +=1 
                if cnt < best:
                    best = cnt

        print("Case #{}: {}".format(t, best))
        


if __name__ == "__main__":
    main()