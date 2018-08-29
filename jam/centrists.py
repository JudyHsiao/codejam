import io
import sys
import collections

# 2018 i/o for women https://code.google.com/codejam/contest/8384486/dashboard
# Simulate the redirect stdin.
if len(sys.argv) > 1:
    filename = sys.argv[1]
    inp = ''.join(open(filename, "r").readlines())
    sys.stdin = io.StringIO(inp)

def create_alphabet_order(words):
    G= collections.defaultdict(dict)
    prefixSet= collections.defaultdict(list)
    V=set()
    for w in words:
        for i in range(len(w)+1):
            if i < len(w):
                V.add(w[i])
            k = w[:i]
            v = w[i:]
            if v!="":
                prefixSet[k].append(v)
                     
    for k in prefixSet:
        l = prefixSet[k]
        for i in range(len(l)):
            for j in range(i+1, len(l)):
                u = l[i][0]
                v = l[j][0]
                G[u][v] = 1
    return G,V

def topoSort(G, s,  visited, order):
        if visited[s]  == 2:  #visited
            return True
        if visited[s] == 1:   #visiting
            return False
        
        visited[s] = 1
        for u in G[s]:
            if u !=s:
                if topoSort(G, u, visited, order) == False:
                    return False
            
        visited[s] = 2
        order.insert(0,s)
        return True

def is_valid_order(A):
    G,V = create_alphabet_order(A)
    visited={}
    for v in V:
        visited[v] = 0  #0:not visited 1:visiting 2: visited
    order = []
    for v in V:
        noCycle = topoSort(G, v, visited, order)
        if noCycle == False:
            return False

    return True

def main():
    t = int(input())  # read a line with a single integer
    for i in range(1, t + 1):
        n = int(input())
        names = [s for s in input().split(" ")]

        if is_valid_order([names[1],names[0],names[2]]) or is_valid_order([names[2],names[0],names[1]]):
            one = 'YES'
        else:
            one = 'NO'

        if is_valid_order([names[0],names[1],names[2]]) or is_valid_order([names[2],names[1],names[0]]) :
            two = 'YES'
        else:
            two = 'NO'

        if is_valid_order([names[0],names[2],names[1]]) or is_valid_order([names[1],names[2],names[0]]) :
            three = 'YES'
        else:
            three = 'NO'
        print("Case #{}: {} {} {}".format(i, one, two, three))
        


if __name__ == "__main__":
    main()