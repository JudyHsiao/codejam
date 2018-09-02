#include <cstdio>
#include <vector>

using namespace std;

const int maxn = 100000+4;
const int INF = 1000000000;

struct Edge {
    int u,v,c;
    Edge(int u=0, int v=0, int c=0):u(u), v(v),c (c) {}
};

vector<Edge> edges;
vector<int>G[maxn];


void AddEdge(int u, int v, int c){
    edges.push_back(Edge(u,v,c));
    int idx = edges.size()-1;
    G[u].push_back(idx);
}

int n, vis[maxn];


int main() {
    int u, v, c, m;
    while (scanf("%d%d", &n, &m) ==2) {
        for (int i=0; i < n; i++)

    }


}