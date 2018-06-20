import sys

def main():

    t = 0
    for line in sys.stdin:
        t+=1
        [n, m, c] = [int(ch) for ch in line.split() if ch != ""]
        if n == 0 and m ==0 and c==0:
            exit(0)

        C = []
        for i in range(n):
            C.append(int(input().strip(("\n "))))

        O = []
        for i in range(m):
            O.append(int(input().strip(("\n "))))

        h = [0] * n
        total =0
        M = 0
        for  i in O:
            if h[i-1] == 0:
                h[i-1] = C[i-1]
                total += C[i-1]
            else:
                h[i-1] = 0
                total -= C[i-1]
            M = max(M, total)
        
        print("Sequence {}".format(t))
        if M > c:       
            print("Fuse was blown.")
        else:
            print("Fuse was not blown.")
            print("Maximal power consumption was {} amperes.".format(M))
        print()
 
    exit(0)
        


if __name__ == "__main__":
    main()