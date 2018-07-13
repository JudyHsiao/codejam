import io
import sys
import collections

# all the possible permutation of the Euler Path in lexicographic order.

# Simulate the redirect stdin.
if len(sys.argv) > 1:
    filename = sys.argv[1]
    inp = ''.join(open(filename, "r").readlines())
    sys.stdin = io.StringIO(inp)

def dfs(G, s, path ,used):
    if len(used) == 16:
        print("".join(path))
        return

    for v in G[s]:
        if (s,v) not in used:
            path.append(str(v))
            used.add((s,v))
            used.add((v,s))
            dfs(G, v, path, used)
            used.remove((s,v))
            used.remove((v,s))
            path.pop()


def main():
    G = {
        1:[2,3,5],
        2:[1,3,5],
        3:[1,2,4,5],
        4:[3,5],
        5:[1,2,3,4]
    }

    used=set()
    path=["1"]
    dfs(G, 1 ,path, used)

if __name__ == "__main__":
    main()
