#include<cstdio>
#include <algorithm>
using namespace std;

int N, M, E, SR, SC, TR,TC;
const int maxn = 105;
int A[maxn][maxn];

int bfs() {
    
}

int main()
{
    int T;
    scanf("%d", &T);
    for(int t = 1; t<= T; t++ ){
        scanf("%d %d %d %d %d %d %d",&N, &M, &E, &SR, &SC, &TR, &TC);
        fill_n(&A[0][0], maxn * maxn, -100000);

        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                scanf("%d", &A[i][j]);
            }    
        }
        int e = bfs();
        printf("")

    }
}