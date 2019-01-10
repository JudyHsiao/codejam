#include <vector>
#include <set>
using namespace std;


struct UnionFind {
    UnionFind(int n):pset(n) {
        for (int i = 0; i < n; i++)
            pset[i]= i;
    };
    int find (int x) {
        if (pset[x] !=x)
            pset[x] = find(pset[x]);
        
        return pset[x];
    }
    
    bool Union(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px == py)
            return false;
        pset[px] = py;
        return true;
    }
    
    int numOfComponents() {
        for(int i= 0; i < pset.size(); i++)
            find(i);
        
        set<int> s(pset.begin(), pset.end());
        return s.size();
    }
    
    vector<int> pset;
};