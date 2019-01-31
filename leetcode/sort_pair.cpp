#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

struct Comp {
  bool operator() (const pair<int,int>& lhs, const pair<int,int>& rhs) const
  {return lhs.first < rhs.first;}
};
int main() {
    vector<pair<int,int>> A = {{2,0},{3,1},{1,2},{1,3},{4,4}};
    set<pair<int,int>> q(A.begin(), A.end());

    int n = A.size() ;
    for (int i = 0; i < n-1 ; i++) {
        q.erase(A[i]);
        auto it = q.lower_bound(A[i]);
        if (it != q.end())
           printf("i:%d, it[0]:%d it[1]:%d\n", i, it->first, it->second);
    }

    
    return 0;

}