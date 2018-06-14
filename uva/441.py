import sys
import itertools

def main():
    L =[]
    for line in sys.stdin:
        L.append(line)
    
    for i, line in enumerate(L):
        A = [s for s in line.strip("\n").split(" ") if s !=""]
        if A[0] == 0:
            exit(0)
        A = A[1:]
        for p in itertools.combinations(A, 6):
            print("{}".format(" ".join(p)))
        if i < len(L) -1:
            print()
        

    exit(0)




if __name__ == "__main__":
    main()