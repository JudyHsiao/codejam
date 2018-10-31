#include<cstdio>
#include <algorithm>
#include <queue>

using namespace std;

int N, M, E, SR, SC, TR,TC;
const int maxn = 105;
int A[maxn][maxn];
int V[maxn][maxn];

struct Node {
    int r, c;
    int e;

    bool operator < (const Node& rhs) const{
        return e < rhs.e;
    }
    Node (int r, int c, int e):r(r),c(c),e(e){};

};

const pair<int,int> dir[4] = {{0,1}, {0,-1}, {1,0} ,{-1, 0}};

int bfs() {
    priority_queue<Node> q;
    Node s(SR,SC,E);
    q.push(s);

    while(!q.empty()){
        Node n = q.top();
        q.pop();
        A[n.r][n.c] = 0;
        V[n.r][n.c] = 1;
        //printf("(%d, %d)\n", n.r, n.c);
        if (n.r == TR && n.c == TC) {
            return n.e;
        }
        for (int i =0; i< 4 ;i ++) {
            int r = n.r +dir[i].first;
            int c = n.c +dir[i].second;
            if (A[r][c] > -100000 && V[r][c] == 0) {
                if (n.e + A[r][c] >=0 ) {
                    Node v(r, c, n.e + A[r][c]);
                    q.push(v);
                }
            }
            
        }
    }
    return -1;
}

int main()
{
    int T;
    scanf("%d", &T);
    for(int t = 1; t<= T; t++ ){
        scanf("%d %d %d %d %d %d %d",&N, &M, &E, &SR, &SC, &TR, &TC);
        fill_n(&A[0][0], maxn * maxn, -100000);
        memset(V, 0, sizeof(V));
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                scanf("%d", &A[i][j]);
            }    
        }
/*
        printf("N:%d M:%d E:%d SR:%d SC:%d TR:%d TC:%d\n",N, M, E, SR, SC, TR, TC);
        for (int i = 0; i <= N+1; i++) {
            for (int j = 0; j <= M+1; j++) {
                printf("%8d ", A[i][j]);
            }    
            printf("\n");
        }
*/
        int e = bfs();
        printf("Case #%d: %d\n",t, e);
    }
    return 0;
}