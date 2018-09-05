#include <cstdio>
#include <cstring>
#include <string>

using namespace std;
char A[80];
int n, L;

bool valid(int cur, char ch) {
    int l = cur+1;

    for (int j=1; j<=l/2; j++) {
        int equal = 1;
        for (int k =0 ;  k<j; k++) {
            if (A[l-j + k] != A[l-2*j+k]) {
                equal = 0;
                break;
            }
        }
        if (equal == 1) {
            return false;
        }
    }
    return true;
}


int cnt = 0;
int  dfs(int k) {
    if ( cnt++ == n ) {
        for(int i = 0; i<k ; i++) {
            printf("%c", A[i]);
        }
        printf("\n");
        return 0;
    }

    
    for (char ch = 'A'; ch < 'A'+ L; ch++) {
        A[k] = ch;
        if (valid(k, ch)) {
            if (!dfs(k+1))
                return 0;
        }
    }
    return 1;
}

int main() {
    while(scanf("%d%d",&n, &L)==2 && n && L){
        cnt = 0;
        memset(A, 0, sizeof(A));
        dfs(0);
    }
    return 0;
}