#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<iostream>
using namespace std;

struct factor {
    int a;
    int n;
    factor(int a, int n):a(a),n(n){}
};



void prime_factor_decomposition(int n, vector<factor> &factors) {
    int m = floor(sqrt(n) + 0.5);
    for (int i = 2; i < m; i++) {
        int e = 0;
        while (n % i == 0) {
            e++;
            n /= i;
        }
        if (e > 0) {
            factors.push_back(factor(i, e));
        }

        if (n ==1) {
            break;
        }
    }
    if (n > 1) {
         factors.push_back(factor(n, 1));
    }

}

bool is_prime(int n) {
  int m = floor(sqrt(n) + 0.5);
  for(int a = 2; a <= m; a++)
    if(n % a == 0) return false;
  return true;
}

void printFactor(vector<factor> F) {
    for (auto f =F.begin(); f !=F.end(); f++){
        if (f!=F.begin())
            printf(" * %d^%d", f->a, f->n);
        else
            printf("%d^%d", f->a, f->n);
    }
    printf("\n");
}

long long solve(int n) {
    if (n ==1) {
        return 2;
    }

    vector<factor> f;
    prime_factor_decomposition(n, f);

    long long ans =0;

    if (f.size() <= 1) {
        return (long long) n+1; 
    } else {
        
        for (int i = 0; i < f.size(); i++) {
            ans += pow(f[i].a,f[i].n);
        }
    }
    return ans;
}



int main() {
    int kase = 1;
    int n;
    while(scanf("%d", &n) ==1 && n) {
        printf("Case %d: %lld\n", kase++, solve(n));
    }

}