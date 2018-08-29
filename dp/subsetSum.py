import io
import sys
import collections


def divisors(n):
    D = set()
    D.add(1)
    for i in range(2, n//2 +1):
        if n%i == 0 :
            D.add(i)
            D.add(n//i)
    return list(D)

def S(A, n ,k , memo):
    if k == 0:
        return True
    
    if n == 0 and k > 0:
        return False
    
    if (n, k) in memo:
        return memo[(n,k)]

    memo[(n,k)] = S(A, n-1, k) or S(A, n-1, k - A[n-1])

    return memo[(n,k)]


def main():
    memo = {} 
    n = int(input())  # read a line with a single integer
    A = divisors(n)
    b = S(A, 0, n, memo)
    print(b)
        


if __name__ == "__main__":
    main()