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


#G = collections.defaultdict(dict)
#V = list() or set()
def is_valid_order(G, V):
    visited={}
    for v in V:
        visited[v] = 0  #0:not visited 1:visiting 2: visited
    order = []
    for v in V:
        noCycle = topoSort(G, v, visited, order)
        if noCycle == False:
            return False

    return True