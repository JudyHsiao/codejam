import sys


h = {}
def cycleL(n):
    l = 1

    while n != 1:
        if n%2 ==1:
            n = 3*n+1
        else:
            n = n//2
        l+=1
    return l

def main():

    for line in sys.stdin:
        [i, j] = [int(c) for c in line.split()]
        a, b = min(i,j), max(i,j)
        maxL = 0
        for k in range(a, b+1):
            if k not in h:
                h[k] = cycleL(k)
            maxL = max(maxL, h[k])

        print("{} {} {}".format(i, j, maxL))
    
    exit(0)
        


if __name__ == "__main__":
    main()