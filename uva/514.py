import io
import sys
import collections


# Simulate the redirect stdin.
if len(sys.argv) > 1:
    filename = sys.argv[1]
    inp = ''.join(open(filename, "r").readlines())
    sys.stdin = io.StringIO(inp)

def marshal(A, n):
    T = [i for i in range(1,n+1)]

    S=[]
    i = 0
    j = 0
    while i < n:
        #print(A[i], T[j], S)
        if j<n and A[i] == T[j]:
            i+=1
            j+=1
            continue
        if len(S):
            if A[i] == S[-1]:
                i+=1
                S.pop()
                continue
        if j >=n:
            return False
        S.append(T[j])
        j+=1

    return True

 
def main():
    while True:
        n = int(input())
        if n == 0:
            exit(0)
        for line in sys.stdin:
            line = line.strip()
            if line == "0":
                break
            A = [int(s) for s in line.split()]
            ans = marshal(A, n)
            if ans == True:
                print("Yes")
            else:
                print("No")
        print()

        
           
if __name__ == "__main__":
    main()