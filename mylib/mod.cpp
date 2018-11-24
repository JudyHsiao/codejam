typedef unsigned long long ULL;

const ULL MOD = 1000000007;

void init_combination_mod() {
  const int maxn = 1000;
  const int MOD = 10056;
  int C[maxn+1][maxn+1];
  
  for(int i = 0; i <= maxn; i++) {
    C[i][0] = C[i][i] = 1;
    for(int j = 1; j < i; j++)
      C[i][j] = (C[i-1][j] + C[i-1][j-1]) % MOD;
  }
}

ULL pow_mod(ULL x, unsigned int y) 
{ 
    ULL res = 1;      // Initialize result 
  
    x = x % MOD;  // Update x if it is more than or  
                // equal to p 
  
    while (y > 0) 
    { 
        // If y is odd, multiply x with result 
        if (y & 1) 
            res = (res*x) % MOD; 
  
        y = y>>1; // y = y/2 
        x = (x*x) % MOD;   
    } 
    return res; 
} 

ULL factorial_mod(ULL n){
    ULL res = 1;
    for(ULL i = 1;i<=n;i++){
        res *= i%MOD;
        res = res % MOD;
    }
    return res;
}


int main() {
    ULL a = 18446744073709551615;
    ULL b =18446744073709551615;
    int n = 1000;

    int p = pow_mod(a % n, b);   // p = a^b %n
}