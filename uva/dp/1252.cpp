#include<cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 128;
const int maxm = 11;

int kase, n, m;
char objects[maxn][maxm+100];

int vis[1 << maxm][1<<maxm], d[1<<maxm][1<<maxm];
int cnt[1<<maxm][1<<maxm];
void init() {
    for (int s = 0; s < (1<<m); s++){
        for (int a = s; a; a=(a-1)&s)
            cnt[s][a] = 0;
        cnt[s][0] = 0;
    }

    for(int i = 0; i < n; i++) {
        int feature = 0;
        for (int f = 0; f < n; f++) {
            if (objects[i][f] == '1')
                feature |= (1<<f);
        }
        for(int s = 0; s<(1<<m); s++) {
            cnt[s][s&feature]++;
        }
    }
}

int main() {
    memset(vis, 0, sizeof(vis));
    while(scanf("%d%d", &m, &n)==2 && n) {
        ++kase;
        for(int i = 0; i < n; i++) scanf("%s", objects[i]);
        init();
        printf("%d\n", dp(0, 0));
    }
}
