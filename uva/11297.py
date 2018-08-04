import io
import sys
import collections


# Simulate the redirect stdin.
if len(sys.argv) > 1:
    filename = sys.argv[1]
    inp = ''.join(open(filename, "r").readlines())
    sys.stdin = io.StringIO(inp)


def main():

    N = int(input())
    A=[]
    for _ in range(N):
        A.append([int(s) for s in input().split()])


    q = int(input())
    Q = []
    for _ in q:
        Q.append(input().split())
    
    for t in Q:
        if t[0] == 'q':
            sgt.query()
        else:
            sgt.update()


        


if __name__ == "__main__":
    main()