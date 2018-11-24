#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int maxn = 5000+5;
const int INF = 1000000000;
char p[maxn], q[maxn];
int sp[26], sq[26], ep[26], eq[26]; // sp[i] start positions of character i in p
int d[maxn][maxn], c[maxn][maxn]; // c[i][j]: how many "incomplete" colors in the mixed sequence
int n;
int m;

int cost( int i, int j) {
    int res = 0;
    for (int ch = 0 ; ch < 26; ch++){
       
        if (sp[ch]<=i || sq[ch]<=j)
            res ++;
            
        if ((ep[ch]>0 || eq[ch]>0) && ep[ch]<=i && eq[ch] <=j){
            res --;
        }
    }

    return res;
}


void initCost() {
    
    for (int i = 0; i <=n; i++) {
        for (int j = 0; j <=m; j++) {
            c[i][j] = cost( i, j);
            printf("c[%d][%d] =%d\n", i, j , c[i][j]);
        }
    }
    
}

int main () {
    int T;
    scanf("%d", &T);
    while(T--) {
        p[0] = ';';
        q[0] = ';';
        scanf("%s", p+1);
        scanf("%s", q+1);
        n = strlen(p);
        m = strlen(q);

        printf("n:%d\n",n);
        printf("m:%d\n",m);

        for (int i = 1; i <=n; i++) p[i]-= 'A';
        for (int i = 1; i <=m; i++) q[i]-= 'A';

        for (int i = 0; i < 26; i++) {
            sp[i] = sq[i] = INF;
            ep[i] = eq[i] =0;
        }

        for (int i = 1; i <=n; i++) {
            sp[p[i]] = min(i, sp[p[i]]);
            ep[p[i]] = i;
        }

        for(int i = 1; i <= m; i++) {
            sq[q[i]] = min(sq[q[i]], i);
            eq[q[i]] = i;
        }
/*
        for (int ch = 0 ; ch < 26; ch++){
            if (ep[ch] >0 || eq[ch] >0)
                printf("%c: sp=%d ep=%d  sq=%d eq=%d\n", ch+'A',sp[ch], ep[ch], sq[ch], eq[ch] );
        }
*/
        int t = 0;
        memset(c, 0, sizeof(c));
        memset(d, 0, sizeof(d));

        initCost();

        for (int i = 0; i <=n; i++) {
            for (int j = 0; j <=m; j++) {
                if(!i && !j) continue;

                 // calculate d
                int v1 = INF, v2 = INF;
                if(i) v1 = d[i-1][j] + c[i-1][j]; // remove from p
                if(j) v2 = d[i][j - 1] + c[i][j - 1]; // remove from q
                d[i][j] = min(v1, v2); 
            } 
        }

        printf("%d\n", d[n][m]);
    }

    return 0;

}