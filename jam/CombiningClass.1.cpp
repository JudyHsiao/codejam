#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int maxn = 400000+5;
int L[maxn], R[maxn], K[100000+5];
int N, Q;

#define LSOne(S) (S & (-S))
typedef long long ll;

vector<ll> fwt1, fwt2;




int solve(const vector<pair<int,int>>& I){
    int h=0;
    long long total = 0;
    for (int x = 0; x < I.size(); x +=2) {
        h+=I[x].second;
        if (I[x+1].second == 1) {
            int w=I[x].first - I[x+1].first ;
            
            total+=h*w;
            
        }
        
        
        
        
    }
    
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

        vector<pair<int,int>> I;
        I.resize(N);
        for(int i = 1; i <=N; i++) {
            L[i] = min(x[i], y[i])+1;
            R[i] = max(x[i], y[i])+1;
            I.push_back(make_pair(L[i], 1));
            I.push_back(make_pair(R[i], -1));
        }

        sort(I.begin(), I.end());
        reverse(I.begin(), I.end());

        vector <pair<int,int>> queries;
        for(int i = 1; i <=Q; i++) { 
            queries.push_back(make_pair(z[i] +1, i));
        }

        sort(queries.begin(), queries.end());

        solve(I);

        long long ans = 0;
        for (int i = 1; i <=Q; i ++) {
            ans += K[i]*i;
        }
        printf("Case #%d: %lld\n", t, ans);

    }
    return 0;
}