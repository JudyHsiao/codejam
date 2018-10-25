#include <cstdio>
#include <cmath>
const int maxn = 100000+5;
long long a[maxn];
using namespace std;
int main() {
    int n ;
    while (scanf("%d", &n) ==1 && n) {
        
        for (int i = 0 ; i < n ;i++) {
            scanf("%lld", &a[i]);
        }
        long long ans = 0;
        for (int i = 0 ; i < n ;i++) {
           ans += fabsl(a[i]);
           if (i+1< n) {
               a[i+1] = a[i+1]+ a[i];
           }
        }
        printf("%lld\n", ans);
    }

}