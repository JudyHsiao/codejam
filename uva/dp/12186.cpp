#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 100000+5;
int N, T;

int dp (int p,const vector<int>* son) {
    if(son[p].empty()) {
        return 1;
    }

    vector<int> d;
    for (auto n: son[p]){
        d.push_back(dp(n, son));
    }
    sort(d.begin(), d.end());
    int c = (son[p].size() * T -1) /100 +1;
    int ans = 0;
    for (int i =0; i < c; i++) {
        ans+=d[i];
    } 

    return ans;
}

int main() {
    int boss = 0;
    while(scanf("%d%d", &N, &T) == 2 && N && T) {
        vector<int> son[maxn]; 
        for (int i =1 ; i <= N ; i++) {
            scanf("%d", &boss);
            son[boss].push_back(i);
        }

        printf("%d\n", dp(0, son));
    }
    return 0;
    
}