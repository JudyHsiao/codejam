#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 10000;
int main() {
    int N, Q;
    int kase = 0;
    while (scanf("%d%d", &N, &Q)==2 && N) {
        printf("CASE# %d:\n", ++kase);
        int a[maxn];
        for (int i = 0; i < N; i++) {
            scanf("%d", &a[i]);
        }

        sort(a, a+N);
        int q;
        for (int i = 0;i <Q; i++) {
            scanf("%d", &q);
            int p = lower_bound(a, a+N, q) - a;
            if(a[p] == q) {
                printf("%d found at %d\n", q, p+1);
            }else{
                 printf("%d not found\n", q);
            }
        }
    }

    return 0;
}