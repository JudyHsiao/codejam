import io
import sys
import collections


# Simulate the redirect stdin.
if len(sys.argv) > 1:
    filename = sys.argv[1]
    inp = ''.join(open(filename, "r").readlines())
    sys.stdin = io.StringIO(inp)

def valid(A):
    S = []
    for a in A:
        #print(a)
        if a =='(' or a =='[':
            S.append(a)
        elif a ==']':
            if len(S) == 0 or  '[' != S.pop():
                return False
        elif a ==')':
          if len(S) == 0 or  '(' != S.pop():
                return False

    if len(S) ==0:
        return True

    return False

def main():

    t = int(input())  # read a line with a single integer
    for i in range(1, t + 1):
        A = list(input())
        ans = valid(A)
        if ans == True:
            print("Yes")
        else:
            print("No")
        
        


if __name__ == "__main__":
    main()