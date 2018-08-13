import sys
import sys



def main():
    t = int(input())  # read a line with a single integer
    for i in range(t):
        input()
        P =  [int(s) for s in input().split(" ") if s != ""]
        K = [0] * len(P)
        for k, v in enumerate(P):
            K[v-1] = k

        V =  [s for s in input().split(" ") if s != ""]
        for k in K:
            print(V[k])
        if i < t-1:
            print()
    exit(0)




if __name__ == "__main__":
    main()