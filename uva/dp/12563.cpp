#include <cstdio>
#include <vector>
using namespace std;


const int maxn = 50 + 5;
const int INF = 1000000000;

int n, t, len[maxn], d[maxn][maxn*180+678]; 
int main() {
    int T;
    
    scanf("%d", &T);
    int kase =1;
    while (T--) {
        scanf("%d%d",&n, &t);
        for (int i = 0; i < n; i++){
            scanf("%d", &len[i]);
        }
        for (int i =0; i<= n; i++) {
            for (int j = 1; j < t; j++) {
                d[i][j] = -INF;
            }
            d[i][0] = 0;
        }

        
        int ans  =  0;
        int maxt = 0;
        for (int i = n-1; i>=0; i--) {
            for (int j = 0; j < t; j++) {
                d[i][j] = d[i+1][j];   //注意 易錯 不要放在if裡面
                if (j >= len[i]&&  d[i+1][j - len[i]] >=0) {
                    d[i][j] = max(d[i][j], d[i+1][j - len[i]] + 1);                 
                }
            }
        }

        for(int i =t-1; i>=0; i--) {
            if (d[0][i] == ans) {
                printf("Case %d: %d %d\n", kase++, ans+1  ,i+678);
                break;
            }

        }   
    }
    return 0;

}