#include <cstdio>
#include <cstring>


int n;
int A[10];
bool is_sorted() {
    for (int i = 0; i < n-1; i++) {
        if (A[i] >= A[i+1])
            return false;
    }
    return true;
}

int h() {
  int cnt = 0;
  for(int i = 0; i < n-1; i++)
    if(A[i]+1 != A[i+1]) cnt++;
  if(A[n-1] != n) cnt++;
  return cnt;
}

bool dfs(int d,int maxd) {

    if(d*3 + h() > maxd*3) return false;

    if (is_sorted())
        return true;

    int b[10], olda[10];
    memcpy(olda, A, sizeof(A));
    for(int i = 0; i < n ; i++) {
        for (int j = i; j <n ;j++) {
            int cnt = 0;
            for (int k = 0; k < n; k++) {
                if(k < i || k > j) b[cnt++] = A[k];
            }
            for (int k = 0; k <= cnt; k++) {
                int cnt2 = 0;
                for (int p = 0; p < k; p++) 
                    A[cnt2++] = b[p];
                for (int p = i; p <= j; p++)
                    A[cnt2++] = olda[p];
                for(int p = k; p < cnt; p++) 
                    A[cnt2++] = b[p];

                if(dfs(d+1, maxd))
                    return true;
                memcpy(A, olda, sizeof(A));
            }
        }
    }
    return false; 
}


int solve() {
    if (is_sorted())
        return 0;
    int max_ans = 5;
    for (int maxd=1; maxd < max_ans; maxd++)
        if (dfs(0, maxd))
            return maxd;
    return max_ans;
    
}

int main(int argc, char const *argv[])
{   int kase = 0; 
    while(scanf("%d", &n) && n ){
        for (int i=0; i< n; i++) {
            scanf("%d", &A[i]);
        }
        printf("Case %d: %d\n", ++kase, solve());
    }
    
    return 0;
}
