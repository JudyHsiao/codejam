typedef unsigned long long ULL;


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