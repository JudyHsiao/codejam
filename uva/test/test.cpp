#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;
int main() {

    int a;
    int b;
    scanf("%d", &a);
    scanf("%d", &b);


    int dp[a][b];
    memset(dp, 0, sizeof(dp));

    for (int i =0 ;i <a; i ++){
        for (int j =0 ;j <b; j ++)
            printf("%d", dp[i][j]);
        printf("\n");
    }

    




}