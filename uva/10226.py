import io
import sys
import collections


# Simulate the redirect stdin.
if len(sys.argv) > 1:
    filename = sys.argv[1]
    inp = ''.join(open(filename, "r").readlines())
    sys.stdin = io.StringIO(inp)


def main():
    t = int(input())
    input()
    for i in range(t):
        T= collections.defaultdict(int)
        total = 0
        for line in sys.stdin:
            tree = line.strip()
            if tree == "":
                break;
            T[tree]+=1
            total+=1
        
        ans = []
        for k, v in T.items():
            ans.append((k, 100*v/total))
        
        ans.sort()
        for a in ans:
            print("{} {:.4f}".format(a[0], a[1]))
        if i < t-1:
            print()

            



if __name__ == "__main__":
    main()