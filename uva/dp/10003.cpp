#include <cstdio>
#include <algorithm>
#include <climits>
#include <cstring>
using namespace std;

const int maxn = 50+5;
int p[maxn];
int dp[maxn][maxn];

int cal (int i, int j){
    if (j == i+1) {
        dp[i][j] = 0;
        return 0;
    }

    if ( dp[i][j] > 0 ) {
        return dp[i][j];
    }

    int best = INT_MAX;
    for (int k = i+1; k <j ; k++) {
        best = min(best, p[j] - p[i] + cal(i, k) + cal(k, j));
    }
    dp[i][j] = best;
    return dp[i][j];
}

int main() {
    int l;
    int n;
    
    while (scanf("%d",&l) == 1 && l) {
        scanf("%d", &n);
        p[0] = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &p[i]);
        }
        p[n+1] = l;
        sort(p,p+n+2);
        memset(dp, 0, sizeof(dp));    
        int ans = cal(0, n+1);
        printf("The minimum cutting is %d.\n", ans);
    }
    return 0;
}