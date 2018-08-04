import io
import sys
import collections


# Simulate the redirect stdin.
if len(sys.argv) > 1:
    filename = sys.argv[1]
    inp = ''.join(open(filename, "r").readlines())
    sys.stdin = io.StringIO(inp)

def countOdds(A, s ,t):
    o = 0
    for i in range(s, t+1):
        if A[i] %2 ==1:
            o+=1
    return o


def main():
    T = int(input())  # read a line with a single integer

    for t in range(1, T + 1):
        
        [N, O, D] = [int(s) for s in input().split()]
        [X1, X2, A, B, C, M, L] = [int(s) for s in input().split()]
        X = [0] * (N+1)
        X[1] = X1
        X[2] = X2
        S = [0] * (N+1)
        for i in range(3,N+1):
            X[i] = (A*X[i-1] + B*X[i-2] + C) % M 

        for i in range(1, N+1):
            S[i] = X[i] + L
        
        PS = [0] * (N+1)
        PS[1] = S[1]
        for i in range(2, N+1):
            PS[i] = PS[i-1] + S[i]

        A=[]
        for i in range(1, N+1):
            for j in range(i, N+1):
                A.append((PS[j]- PS[i-1], i, j))

        A.sort(reverse=True)
        found = False
        for [s, i, j ] in A:
            if s <= D:
                o = countOdds(S, i ,j)
                if o <= O:
                    print("Case #{}: {}".format(t, s))
                    found = True
                    break
        if found == False:
            print("Case #{}: IMPOSSIBLE".format(t))
        


if __name__ == "__main__":
    main()