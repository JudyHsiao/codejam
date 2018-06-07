import io
import sys
import collections

# 2017 io for women https://code.google.com/codejam/contest/12224486/dashboard#s=p0&a=2
# Simulate the redirect stdin.
if len(sys.argv) > 1:
    filename = sys.argv[1]
    inp = ''.join(open(filename, "r").readlines())
    sys.stdin = io.StringIO(inp)

def printGrid(D, M):
    for i in range(D):
        print("".join(M[i]))

def initM(D):
    I = []
    if D == 50:
        for i in range(25):
            I.append(['I','/','O','O']*12+['O',"O"])
            I.append(['O']*50)

    if D ==15:
        for i in range(15):
            I.append(['I','/', 'O','/']*3 +['I','/','O'])
    return I



def wordsearch(D, T):
    M = initM(D)
    if D == 50:
        toDel = 300 - T
        i = 0
        j = 0
        while toDel >0 and i < D: 
            while toDel >0 and j < D:
                if M[i][j] == '/':
                     M[i][j] = 'O'
                     toDel-=1
                j+=1
            j = 0
            i+=1
    if D == 15:
        toDel = 287 - T
        i = 1
        j = 0
        while toDel > 3 and i < D-1:
            while toDel > 3 and j < D:
                if M[i][j] == '/':
                    M[i][j] = 'O'
                    toDel-=3
                j+=1
            j = 0
            i+=1
        
        i = 0
        j = 0
        while toDel >0 and i <=14:
            while toDel > 0 and j < D:
                if M[i][j] == '/':
                    M[i][j] = 'O'
                    toDel-=1
                j+=1
            j = 0
            i = 14


    return M


def main():
    t = int(input())  # read a line with a single integer
    for i in range(1, t + 1):
        [D,T] = [int(s) for s in input().split(" ")]
        ans = wordsearch(D,T)

        print("Case #{}:".format(i))
        printGrid(D, ans)
        


if __name__ == "__main__":
    main()