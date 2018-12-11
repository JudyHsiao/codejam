#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
int C, S, Q;
const int maxn = 100 +5;
const int INF = 1000000000;
int d[maxn][maxn];
int main () {
    int u, v, w;
    int kase = 1;
    while (scanf("%d%d%d", &C,&S,&Q) == 3 && C) {
        if (kase > 1)
            printf("\n");

        printf("Case #%d\n", kase++);
        for(int i = 0; i < C; i++) {
            d[i][i] = 0;
            for(int j = i+1; j < C; j++) { d[i][j] = d[j][i] = INF; }
        }
        for (int i =0 ; i < S ; i++) {
            scanf("%d%d%d", &u,&v,&w);
            u--;
            v--;
            d[u][v] = w;
            d[v][u] = w;
        }

        for (int k = 0 ; k < C; k++) {
            for (int i = 0 ; i < C; i++) {
                for (int j = 0; j < C; j++) {
                    if (d[i][k] < INF && d[k][j] < INF)
                        d[i][j] = min(d[i][j], max(d[i][k], d[k][j]));
                }
            }
        }

        for (int i =0 ; i < Q ; i++) {
            scanf("%d%d", &u,&v);
            u--;
            v--;
            if (d[u][v] == INF)
                printf("no path\n");
            else
                printf("%d\n", d[u][v]);
        }
    }
    return 0;
}