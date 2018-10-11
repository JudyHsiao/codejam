#include <cstdio>
#include <cstring>

const int maxn = 1000;
const int MOD = 10056;
int f[maxn+1];
int C[maxn+1][maxn+1];


void init() {
  for(int i = 0; i <= maxn; i++) {
    C[i][0] = C[i][i] = 1;
    for(int j = 1; j < i; j++)
      C[i][j] = (C[i-1][j] + C[i-1][j-1]) % MOD;
  }
}

int main() {

    memset(f, 0 , sizeof(f));
    init();
    f[0] = 1;
    f[1] = 1;
    for (int i = 2 ; i <= 1000 ; i++ ) {
        for (int j =1; j <=i; j++) {
            f[i] = ( f[i] + C[i][j] * f[i-j] ) % MOD;
        }
    }
    int T, n;
    scanf("%d", &T);
    for(int kase = 1; kase <= T; kase++) {
        scanf("%d", &n);
        printf("Case %d: %d\n", kase, f[n]);
    }
    return 0;
}