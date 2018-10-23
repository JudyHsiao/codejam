#include<cmath>

const int maxn = 200000 +5;
long double logF[maxn+1];

long double logC(int n, int m) {
     return logF[n] - logF[m] - logF[n-m];
}

int main() {
    logF[0] = 0;

    for(int i =1; i <=maxn; i++) {
        logF[i] = logF[i-1] + log(i);
    }
}