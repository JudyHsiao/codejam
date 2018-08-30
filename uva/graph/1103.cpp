#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

const int maxh = 200 + 5;
const int maxw = 50 * 4 + 5;

int H, W, pic[maxh][maxw], color[maxh][maxw];
char bin[256][5];

const char* code = "WAKJSD";
void decode(char ch, int row, int col) {
  for(int i = 0; i < 4; i++)
    pic[row][col+i] = bin[ch][i] - '0';
}

const int dr[] = {-1, 1, 0, 0};
const int dc[] = {0, 0, -1, 1};

// dfs from (row, col) and paint color c
void dfs(int row, int col, int c) {
  color[row][col] = c;
  for(int i = 0; i < 4; i++) {
    int row2 = row + dr[i];
    int col2 = col + dc[i];
    if(row2 >= 0 && row2 < H && col2 >= 0 && col2 < W && pic[row2][col2] == pic[row][col] && color[row2][col2] == 0)
      dfs(row2, col2, c);
  }
}

vector<set<int> > neighbors;
void check_neighbors(int row, int col){
    for(int i = 0; i < 4; i++) {
        int row2 = row + dr[i];
        int col2 = col + dc[i];
        if(row2 >= 0 && row2 < H && col2 >= 0 && col2 < W && pic[row2][col2] == 0 && color[row2][col2] != 1)
            neighbors[color[row][col]].insert(color[row2][col2]);
    } 
}


char recognize(int c){
    int cnt = neighbors[c].size();
    return code[cnt];
}


int main() {
    int kase = 0;
    char buf[maxw];
    strcpy(bin['0'], "0000");
    strcpy(bin['1'], "0001");
    strcpy(bin['2'], "0010");
    strcpy(bin['3'], "0011");
    strcpy(bin['4'], "0100");
    strcpy(bin['5'], "0101");
    strcpy(bin['6'], "0110");
    strcpy(bin['7'], "0111");
    strcpy(bin['8'], "1000");
    strcpy(bin['9'], "1001");
    strcpy(bin['a'], "1010");
    strcpy(bin['b'], "1011");
    strcpy(bin['c'], "1100");
    strcpy(bin['d'], "1101");
    strcpy(bin['e'], "1110");
    strcpy(bin['f'], "1111");


    while(scanf("%d%d", &H, &W) == 2 && H && W) {
        memset(pic, 0, sizeof(pic));
        for (int i=0; i < H; i++) {
            scanf("%s", buf);
            
            for(int j = 0; j <W; j++){
                char ch = buf[j];
                decode(buf[j], i+1, j*4+1);
            }
        }

        H += 2;
        W = W * 4 + 2;

        int cnt = 0;
        vector<int> cc; // connected components of 1
        memset(color, 0, sizeof(color));
        for(int i = 0; i <H; i++) {
            for(int j = 0; j <W; j++) {
                if (!color[i][j]) {
                    dfs(i,j, ++cnt);
                    if(pic[i][j] == 1) cc.push_back(cnt);
                }
            }
        }

        neighbors.clear();
        neighbors.resize(cnt+1);
        for(int i = 0; i < H; i++)
            for(int j = 0; j < W; j++)
                if(pic[i][j] == 1)
                    check_neighbors(i, j);

        vector<char> ans;
        for(int i = 0; i < cc.size(); i++)
              ans.push_back(recognize(cc[i]));
        sort(ans.begin(), ans.end());


        printf("Case %d: ", ++kase);
        for(int i = 0; i < ans.size(); i++) printf("%c", ans[i]);
        printf("\n");
    }
    return 0;
}