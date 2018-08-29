import io
import sys
import collections
import itertools
import heapq


# Simulate the redirect stdin.
if len(sys.argv) > 1:
    filename = sys.argv[1]
    inp = ''.join(open(filename, "r").readlines())
    sys.stdin = io.StringIO(inp)

def apply(tea, A):
    complains = 0

    for i in range(len(A)):
        for  j in range(len(tea)):
            if tea[j] != A[i][j]:
                complains +=1

    return complains

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
        for i in range(P):
            if cnt[i] > N//2:
                best[i] = '1'
                complains[i] = N - cnt[i]
            else:
                complains[i] = cnt[i]

        heap=[]
        visited = set()
        heapq.heappush(heap, (sum(complains), best))
        visited.add(tuple(best))
        while (len(heap)):
            (total_complains, tea) = heapq.heappop(heap)
            if "".join(tea) not in F:
                ans = total_complains
                break
            
            for i in range(P):
                b = tea[::]
                b[i] = '0' if tea[i] =='1' else '1'
                total_complains = apply(b, A)
                if tuple(b) not in visited:
                    heapq.heappush(heap, (total_complains, b))
                    visited.add(tuple(b))

        print("Case #{}: {}".format(t, ans))
        


if __name__ == "__main__":
    main()