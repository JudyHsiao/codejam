#include<vector>
#include<set>
using namespace std;



class Solution {
public:
    class UnionFindSet{  
    public:
        UnionFindSet(int n):pset(n+1,0){
            for (int i = 0; i < pset.size(); i++) {
                pset[i] = i;
            }
        }

        int findSet(int i) {
            if (pset[i] != i)
                pset[i] = findSet(pset[i]);
            return pset[i];
        }
        bool unionSet(int i, int j) {
            int pi = findSet(i);
            int pj = findSet(j);
            if (pi == pj)
                return false;

            pset[pi] = pj;
            return true;
        }
        private:
            vector<int> pset;
    };
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        set<int> V;
        for (const auto & e: edges){
            V.insert(e[0]);
            V.insert(e[1]);
        }
        
       UnionFindSet u(V.size());
        
        for (const auto & e: edges){
            if (u.unionSet(e[0],e[1])==false)
                return e;
        }
        return {};
    }
};