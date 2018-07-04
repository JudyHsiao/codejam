import io
import sys
import collections


# Simulate the redirect stdin.
if len(sys.argv) > 1:
    filename = sys.argv[1]
    inp = ''.join(open(filename, "r").readlines())
    sys.stdin = io.StringIO(inp)

def prec(c):
    if c == '+' or c == '-':
        return 1
    elif c == '*' or c == '/':
        return 2
    else:
        return 0

def infixToPostfix(A):
    ans = []
    S = []
    for c in A:
        if c in ["1","2", "3", "4", "5","6","7", "8","9","0"]:
                ans.append(c)
        elif c == '(':
            S.append(c)
        elif c == ')':
            while len(S) > 0:
                b = S.pop()
                if b =='(':
                    break
                ans.append(b)
        else:
            while len(S) > 0 and prec(S[-1]) >= prec(c):
                ans.append(S.pop())
            S.append(c)
    
    while len(S) > 0:
        ans.append(S.pop())
    return "".join(ans)



def main():

    t = int(input())  # read a line with a single integer
    input()
    for i in range(t):
        A=[]
        for line in sys.stdin:
            c = line.strip()
            if c =="":
                break
            A.append(c)

        print(infixToPostfix(A))
        if i < t -1:
            print()

            
    exit(0)


                

        
        


if __name__ == "__main__":
    main()