#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

const int maxn = 400000+5;
int L[maxn], R[maxn], K[100000+5];
int N, Q;
int t;


void solve(const vector<pair<int,int>>& I,const vector <pair<long long,int>>& QQ ){
    double h=1;
    long long total = 0;
    int j = 0;
    int i = 1;
    int start = 0;
    while(i < I.size()) {
        while(I[i].first == I[i-1].first) {
            h+=I[i].second;
            if (i == I.size()-1)
                break;
            i++;
        }
        int w =  I[start].first - I[i].first ;
        
        long long count = 1ll * h * w;
        //cout<< "w:" << w << " h:" << h <<endl;

        while(j < QQ.size() && QQ[j].first <= total + count) {
            //cout<< "q:" <<  QQ[j].first << " sum:" << total + count <<endl;
            
            int k = I[start].first +1 - (int)ceil((QQ[j].first - total) / h);
            //cout << "k:" << k << endl;
            K[QQ[j].second] = k;
            j++;

            if (j == QQ.size())
                return;
        }
        
        h+=I[i].second;
        total += count;
        start = i;
        i++;
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

    for ( t=1; t<=T; t++) {
        scanf("%d %d",&N, &Q);
        scanf("%d %d %d %d %d %d", &x[1], &x[2], &a, &b, &c, &m);
        genXY(x, a,b,c,m);
        scanf("%d %d %d %d %d %d", &y[1], &y[2], &a, &b, &c, &m);
        genXY(y, a,b,c,m);
        scanf("%d %d %d %d %d %d", &z[1], &z[2], &a, &b, &c, &m);
        genZ(z, a,b,c,m);

        vector<pair<int,int>> I;
        for(int i = 1; i <=N; i++) {
            L[i] = min(x[i], y[i])+1;
            R[i] = max(x[i], y[i])+1;
            //cout << "L:" << L[i]  << " R:" << R[i] << endl;
            I.push_back(make_pair(L[i]-1, -1));
            I.push_back(make_pair(R[i], 1));
        }

        sort(I.begin(), I.end());
        reverse(I.begin(), I.end());
        /*
        for(int i = 0; i <I.size(); i++) { 
            cout <<"["<< I[i].first << "," << I[i].second <<"]\n";
        }
        */
        

        vector <pair<long long,int>> queries;
        for(int i = 1; i <=Q; i++) { 
            queries.push_back(make_pair(z[i] +1, i));
        }

        sort(queries.begin(), queries.end());
        
        cout << "Q:" ;
        for(int i = 0; i <Q; i++) { 
            cout << queries[i].first << " ";
        }
        cout << endl;
        

        memset(K, 0 , sizeof(K));
        solve(I, queries);

        long long ans = 0;
        for (int i = 1; i <=Q; i ++) {
            ans += 1LL* K[i]*i;
        }
        printf("Case #%d: %lld\n", t, ans);

    }
    return 0;
}