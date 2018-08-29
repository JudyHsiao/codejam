#include <cstdio>
#include <cstring>

const int maxn = 100+5;
char pic[maxn][maxn];

int m, n, visited[maxn][maxn];

void dfs(int r, int c) {
    if (r < 0 || r >= m || c <0 || c>= n )
        return;
    if (visited[r][c] > 0 || pic[r][c] != '@')
        return;
    
    visited[r][c] = 1;
    for (int dr = -1; dr <=1; dr++) {
        for (int dc = -1; dc<=1; dc++) {
            dfs(r+dr, c+dc);
        }
    }
}

int main(){
    while (scanf("%d %d", &m, &n) ==2 && m &&n){

        for (int i =0; i<m; i++) {
            scanf("%s", pic[i]);
        }
        memset(visited, 0, sizeof(visited));
        int cnt =0;
        for (int i = 0; i <m ; i++){
            for (int j =0; j <n; j++){
                if(pic[i][j] == '@' && visited[i][j]==0) {
                    dfs(i,j);
                    cnt +=1;
                }
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}