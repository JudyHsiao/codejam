import io
import sys
import collections


# Simulate the redirect stdin.
if len(sys.argv) > 1:
    filename = sys.argv[1]
    inp = ''.join(open(filename, "r").readlines())
    sys.stdin = io.StringIO(inp)

def match(a, b):
    if a[0] == b[0] or a[1] == b[1]:
        return True
    return False


def play(P):

    i = 0
    while i < len(P):
        if i >= 3:
            if match(P[i][-1], P[i-3][-1]):
                c = P[i].pop()
                if len(P[i]) == 0:
                    del P[i]
                P[i-3].append(c)
                i-=3
                continue
        if i > 0:
            if match(P[i][-1],P[i-1][-1]):
                c = P[i].pop()
                if len(P[i]) == 0:
                    del P[i]
                P[i-1].append(c)
                i-=1
                continue
        i+=1
    
    return P
 



def main():
    while True:
        line1 = input()
        if line1.strip() == "#":
            exit(1)
        line2 = input()

        cards = line1.split() + line2.split()        
        P = [[0] for i in range(52)]
        for i in range(52):
            P[i][0] = cards[i]
        
        P= play(P)
        L = []
        for p in P:
            L.append(str(len(p)))
        if len(P) > 1:
            print("{} piles remaining: {}".format(len(P), " ".join(L)))
        else:
            print("{} pile remaining: {}".format(len(P), " ".join(L)))
        
        


if __name__ == "__main__":
    main()