#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

const int maxn = 105;
int G[maxn][maxn];
int visited[maxn];
int n, m;


bool dfs(int  v, vector<int>& topo) {
    if (visited[v] == 1) {
        return false;
    } 
    if (visited[v] == 2) {
        return true;
    } 
    visited[v] = 1;

    for (int u=0; u < n; u++){
        if (G[v][u] == 1) {
            dfs(u, topo);
        }
    }
    visited[v] = 2;
    topo.push_back(v);
    return true;
}
bool toposort( vector<int>& topo) {
    memset(visited, 0 , sizeof(visited));
    for (int i =0 ; i < n; i++){
        if (visited[i] == 0){
            bool noCycle = dfs(i , topo);
            if (noCycle == false) {
                return false;
            }
        }
    }

    return true;
}

int main(){
    int G[maxn][maxn];

    while(scanf("%d%d", &n, &m) == 2 && n) {
            memset(G, 0, sizeof(G));
            vector<int> topo;
            for(int i = 0; i < m; i++) {
                int u, v;
                scanf("%d%d", &u, &v); u--; v--;
                G[u][v] = 1;
            }
        if(toposort(topo)) {
            for(int i = n-1; i > 0; i--)
                printf("%d ", topo[i]+1);
            printf("%d\n", topo[0]+1);
        }
        else
        printf("No\n"); // 题目没说无解输出什么，应该是保证有解吧
  }
}

