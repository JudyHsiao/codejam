#include <cstdio>
#include <cstring>
const int maxn = 10005;
int A[10005][10];

void init() {
    memset(A, 0, sizeof(A));
    for (int i = 1; i < maxn; i++) {
        for(int j = 0; j<10; j++)
            A[i][j]=A[i-1][j];

        int k = i;
        while(k>0) {
            A[i][k%10]++;
            k/=10;
        }
    }

}

int main(){
    init();
    int kase,n;
    scanf("%d",&kase);
    while(kase--){
        scanf("%d",&n);
        for (int i =0;i <10; i++)
            if (i <9) 
                printf("%d ",A[n][i]);
            else
                printf("%d\n",A[n][i]);
    }
    return 0;
}
