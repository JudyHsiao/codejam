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
        
        cnt=[0]*P
        for i in range(N):
            for j in range(P):
                if A[i][j] == '1':
                    cnt[j]+=1

        best=["0"]*P
        complains=[0]*P
        new_complains=[]
        for i in range(P):
            if cnt[i] > N//2:
                best[i] = '1'
                complains[i] = N - cnt[i]
                new_complains.append((cnt[i], i))
            else:
                complains[i] = cnt[i]
                new_complains.append((N - cnt[i], i))



        new_complains.sort(key=lambda x:x[0])

        
        i = 0
        ans = float("inf")
        while i <= P:
            for p in itertools.combinations(new_complains, i):
                tea, total_complains = apply(best, complains, p)

                if "".join(tea) not in F:
                    if total_complains < ans:
                        ans = total_complains
            i+=1
        print("Case #{}: {}".format(t, ans))






        #print("Case #{}: {}".format(t, count))
        


if __name__ == "__main__":
    main()