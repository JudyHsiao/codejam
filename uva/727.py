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
    input()
    for i in range(1, t + 1):
        ans = []
        S =[]
        left = []
        op=None
        right = []
        while True:
            c = input()
            if c == "":
                print("".join(ans))
                break
            if c == "(":
                continue:
            elif c is in ["1","2", "3", "4", "5","6","7", "8","9","0"]:
                if op ==None:
                    left.append(c)
                else:
                    right.append(c)
        
        


if __name__ == "__main__":
    main()