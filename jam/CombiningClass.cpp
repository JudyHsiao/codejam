#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 400000+5;
int L[maxn], R[maxn], K[100000+5];
int N, Q;

long long f(int x) {
    long long count = 0;
    for (int i= 1; i <=N; i++) {
        if (R[i] >=x ) {
            count += R[i] - max(x, L[i]) +1;
        }
    }
    //printf("f(%d)=%lld\n",x,count );
    return count;
}

int solve(int k){
    int lo = 0;
    int hi = 1000000000;

    while(lo < hi) {
        int mid = lo + (hi - lo)/2;
        if (f(mid) >= k && f(mid+1) <k) {
            return mid;
        }  
        if (f(mid) >= k ) {
            lo = mid +1;
        } else {
            hi = mid;
        }
    }
    return lo;
}

void genXY(int* x, int a, int b, int c, int m) {
    for (int i = 3; i <= N; i++) {
        x[i] = ((long long)(a%m) * x[i-1] %m + (long long)(b%m) * x[i-2] %m + c) %m;
    }
}

void genZ(int* x, int a, int b, int c, int m) {
    for (int i = 3; i <= Q; i++) {
        x[i] = ((long long)(a%m) * x[i-1] %m + (long long)(b%m) * x[i-2] %m + c) %m;
    }
}

int main(){
    int T;

    int a,b,c,m;
    int x[maxn], y[maxn], z[maxn];
    scanf("%d", &T);

    for (int t=1; t<=T; t++) {
        scanf("%d %d",&N, &Q);
        scanf("%d %d %d %d %d %d", &x[1], &x[2], &a, &b, &c, &m);
        genXY(x, a,b,c,m);
        scanf("%d %d %d %d %d %d", &y[1], &y[2], &a, &b, &c, &m);
        genXY(y, a,b,c,m);
        scanf("%d %d %d %d %d %d", &z[1], &z[2], &a, &b, &c, &m);
        genZ(z, a,b,c,m);

        for(int i = 1; i <=N; i++) {
            L[i] = min(x[i], y[i])+1;
            R[i] = max(x[i], y[i])+1;
            //printf("[%d, %d]\n", L[i], R[i]);
        }
        for(int i = 1; i <=Q; i++) {
            K[i] = z[i] +1;
        }

        long long ans = 0;
        for (int i = 1; i <=Q; i ++) {
            ans += solve(K[i])*i;
        }
        printf("Case #%d: %lld\n", t, ans);
    }
    return 0;
}