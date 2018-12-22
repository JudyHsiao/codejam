#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn = 1000+5;
const int maxm = 50+5;
char A[maxn][maxm];

char C[maxm][256];
char ans[maxm];
int main() {
    int kase;
    int n, m;
    int dist;
    scanf("%d", &kase);
    while(kase--) {
        scanf("%d%d", &n,&m);
        for (int i = 0; i < n ; i++) {
            scanf("%s", A[i]);
        }
        memset(C, 0, sizeof(C));
        memset(ans, 0 , sizeof(ans));
        dist = 0;
        for (int j = 0; j <m ; j++) {
            for (int i = 0; i < n ; i++) {
                char ch = A[i][j];
                C[j][ch]++;
            }
            vector<pair<int, char>> V; 
            for (int i = 0 ; i < 256; i++) {
                if (C[j][i] > 0 ) {
                    V.push_back({-C[j][i], i});
                }
            }
            sort(V.begin(), V.end());
            ans[j] = V[0].second;
            dist += n + V[0].first;
        }

        printf("%s\n",ans);
        printf("%d\n",dist);
    }
    return 0;
}