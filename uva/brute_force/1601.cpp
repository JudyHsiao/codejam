#include <cstdio>
#include <cstring>
using namespace std;

const int maxs = 20;
const int maxn = 150;

const int dx[] = {1,-1, 0, 0};
const int dy[] = {0,0, 1, -1};

int s[3], t[3]; 


int main() {
    int w, h, n;
    while(scanf("%d%d%d", &w, &h,&n) == 3 && n) {
        char maze[20][20];
        for (int i = 0 ;i < h; i++) {
            fgets(maze[i], 20, stdin);
        }

        int cnt, X[maxn], Y[maxn], id[maxs][maxs];
        cnt = 0; 
        for(int i = 0; i< h; i++) {
            for(int j =0; j<w; j++) {
                if (maze[i][j] != '#') {
                    X[cnt] = i;
                    Y[cnt] = j;
                    id[i][j] = cnt;
                    if (islower(maze[i][j]))
                        s[maze[i][j] - 'a']  = cnt;
                    else if (isupper(maze[i][j]))
                        t[maze[i][j] - 'A']  = cnt;
                    cnt +=1;
                }
            }
        }


        //build graph 
        for (int i = 0; i < cnt; i++) {
            
        }
    }
    return 0;
}