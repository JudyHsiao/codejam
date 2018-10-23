typedef unsigned long long ULL;



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

int pow_mod(ULL a, ULL b, int n) {
  if(!b) return 1;
  int k = pow_mod(a, b/2, n);
  k = k * k % n;
  if(b % 2) k = k * a % n;
  return k;
}

int main() {
    ULL a = 18446744073709551615;
    ULL b =18446744073709551615;
    int n = 1000;

    int p = pow_mod(a % n, b, n);   // p = a^b %n
}