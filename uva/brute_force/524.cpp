#include <cstdio>
#include <cstring>
#include <bitset>

using namespace std;

bitset<36> primes;
int n;
int A[16];
int used[17];

void gen_primes() {
    primes.set(0, false); 
    primes.set(1, false); // except index 0 and 1
    for (int i =2 ; i < 36; i++) {
        if (primes.test((size_t)i)) {
            //printf("%d", i);
            int j = i + i;
            while (j < 36) {
                primes.set(j, false);
                j+=i;
            }
        }
    }
}

bool valid(int k, int i) {
    int s = i + A[k-1];
    if (k == n-1) {
        return primes.test((size_t)s) && primes.test((size_t)i +1);
    } else {
        return primes.test((size_t)s);
    }
}

void dfs(int k) {
    if (k == n) {
        for(int i = 0; i < n; i++) {
            if(i != 0) printf(" ");
            printf("%d", A[i]);
        }
        printf("\n");
    }

    for(int i=2; i<= n; i++) {
        if (used[i] == 0 && valid(k, i)) {
            used[i] = 1;
            A[k] = i;
            dfs(k+1);
            used[i] = 0;
        }
    }
}

int main() {
    primes.reset(); 
    primes.flip(); // set all numbers to 1
    
    gen_primes();

    int kase = 1;
    while(scanf("%d", &n) == 1 && n > 0) {
        if(kase > 0) 
            printf("\n");

        printf("Case %d:\n", kase++);

        memset(A, 0, sizeof(A));
        memset(used, 0, sizeof(0));

        
        A[0]=1;
        dfs(1);
        
    }
    return 0;
}