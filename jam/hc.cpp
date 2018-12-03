
#include <cstdio>
using namespace std;

typedef unsigned long long LL;

const LL MOD = 1000000007;
const int maxn = 100000;
LL C[maxn+1][maxn+1];

void init_combination_mod() {
  
  for(int i = 0; i <= maxn; i++) {
    C[i][0] = C[i][i] = 1;
    for(int j = 1; j < i; j++)
      C[i][j] = (C[i-1][j] + C[i-1][j-1]) % MOD;
  }
}

LL pow_mod(LL x, unsigned int y) 
{ 
    LL res = 1;      // Initialize result 
  
    x = x % MOD;  // Update x if it is more than or  
                // equal to p 
  
    while (y > 0) 
    { 
        // If y is odd, multiply x with result 
        if (y & 1) 
            res = (res*x) % MOD; 
  
        // y must be even now 
        y = y>>1; // y = y/2 
        x = (x*x) % MOD;   
    } 
    return res; 
} 



LL factorial_mod(LL n){
    LL res = 1;
    for(LL i = 1;i<=n;i++){
        res *= i%MOD;
        res = res % MOD;
    }
    return res;
}


int main() {
    int T ;
    scanf("%d", &T);
    init_combination_mod();
    int t = 1;
    while (T--) {
        int n, m;
        scanf("%d%d",&n, &m);
        LL total = factorial_mod(2*n);
        int k = -1;
        for (int i = 1; i <= m ; i++) {
            if (k == -1) {
                LL p1 = C[m][i] * factorial_mod((n-i) *2 + i) % MOD;
                p1 = (p1 * pow_mod(2, i))% MOD;
                total = (total + MOD - p1 ) % MOD;  
            } else {
                LL p1 = C[m][i] * factorial_mod((n-i) *2 + i) % MOD;
                p1 = (p1 * pow_mod(2, i))% MOD;

                total = (total + p1) % MOD ;
            }  
            k*=-1;
        }

        printf("Case #%d: %lld\n", t++, total);
    }
    return 0;
}