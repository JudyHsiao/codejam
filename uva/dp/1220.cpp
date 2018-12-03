#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 200+5;
int N;
int cnt;
int n, d[maxn][2], f[maxn][2];

map<string, int> dict;
int ID(const string& s) {
  if(!dict.count(s)) dict[s] = cnt++;
  return dict[s];
}

int dp (int p,int k, const vector<int>* son) {
    f[p][k] = 1;
    d[p][k] = k;

    for(auto n: son[p]){
        if(k == 0) {
            d[p][0] += max(dp(n, 1, son), dp(n, 0, son));
            if(d[n][0] == d[n][1]) f[p][k] = 0;
            else if(d[n][0] > d[n][1] && !f[n][0]) f[p][k] = 0;
            else if(d[n][1] > d[n][0] && !f[n][1]) f[p][k] = 0;
        } else {
            d[p][1] += dp(n, 0, son);
            if (!f[n][0]) {
                f[p][1] = 0;
            }
        }
    }

    return d[p][k];
    
}

int main() {
    int boss;
    string s, s2;
    while(cin >> N && N) {
        cin >> s;
        cnt = 0;
        dict.clear();
        boss = ID(s);
        vector<int> son[maxn]; 
        memset(d, 0, sizeof(d));
        memset(f, 0, sizeof(f));
        for (int i =1 ; i < N ; i++) {
            cin >> s >> s2;
            son[ID(s2)].push_back(ID(s));
        }


        printf("%d ", max(dp(boss, 0, son), dp(boss, 1, son)));
        bool unique = false;
        if(d[0][0] > d[0][1] && f[0][0]) unique = true;
        if(d[0][1] > d[0][0] && f[0][1]) unique = true;
        if(unique) printf("Yes\n"); else printf("No\n");
    }
    return 0;
}