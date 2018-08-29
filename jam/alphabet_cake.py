import io
import sys
import collections
import copy

#https://code.google.com/codejam/contest/5304486/dashboard#s=p0
# Simulate the redirect stdin.
if len(sys.argv) > 1:
    filename = sys.argv[1]
    inp = ''.join(open(filename, "r").readlines())
    sys.stdin = io.StringIO(inp)

def count_todo(M, startR, endR,  startC, endC):
    count = 0
    for r in range(startR, endR):
        for c in range(startC, endC):
            if M[r][c] == '?':
                count +=1
    return count

def get_alphabets(M, startR, endR,  startC, endC):
    A = set()
    for r in range(startR, endR):
        for c in range(startC, endC):
            if M[r][c] != '?':
                A.add(M[r][c])
    return A

def fill_alphabet(M, startR, endR,  startC, endC):

    count = count_todo(M, startR, endR,  startC, endC)
    if count == 0:
        return

    alphabets = get_alphabets(M, startR, endR,  startC, endC)
    if len(alphabets) == 1:
        ch = alphabets.pop()
        for i in range(startR, endR) :
            for j in range(startC, endC):
                if M[i][j] == '?':
                    M[i][j] = ch
        return 
    r = startR+1
    while r < endR :
        A = get_alphabets(M, startR, r, startC, endC)
        B = get_alphabets(M, r, endR, startC, endC)
        if len(A & B) == 0 and len(A) > 0 and len(B) > 0:
            break
        r+=1

    c = startC+1
    while c < endC:
        A = get_alphabets(M, startR, r, startC, c)
        B = get_alphabets(M, startR, r, c, endC)
        if len(A & B) == 0 and len(A) > 0 and len(B) > 0:
            break
        c+=1
    fill_alphabet(M, startR, r,  startC, c)
    fill_alphabet(M, startR, r,  c, endC)

    c = startC+1
    while c < endC:
        A = get_alphabets(M, r, endR, startC, c)
        B = get_alphabets(M, r, endR, c, endC)
        if len(A & B) == 0 and len(A) > 0 and len(B) > 0:
            break
        c+=1
    fill_alphabet(M, r, endR,  startC, c)
    fill_alphabet(M, r, endR,  c, endC)



def main():
    t = int(input())  # read a line with a single integer
    for i in range(1, t + 1):
        [R, C] = [int(s) for s in input().split(" ")]
        A = []  
        for r in range(R):
            A.append(list(input()))
        
        fill_alphabet(A, 0, R, 0 , C)
        print("Case #{}:".format(i))
        for r in range(R):
            print("{}".format("".join(A[r])))

        


if __name__ == "__main__":
    main()