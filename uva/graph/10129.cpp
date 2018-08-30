#include <cstdio>
#include <vector>
#include <cstring>
#include <climits>

using namespace std;


typedef pair<int, int> ii;
typedef vector<ii> vii;


void dfs(vector<vii>& G, int s, vector<int>& visited){
    if (visited[s] == 1) {
        return;
    }

    visited[s] = 1;
    for (auto p: G[s]) {
        //printf("%d\n", p.first);
        dfs(G, p.first, visited);
    }
}

int main() {
    int T, N;
    scanf("%d", &T);
    char s[1005];

    while (T--) {
        vector<int> start[26];
        vector<int> end[26];

        scanf("%d", &N);
        for (int i=0; i < N ; i++) {
            scanf("%s", s);
            char c1 = s[0], c2 = s[strlen(s)-1];
            start[c1 - 'a'].push_back(i);
            end[c2 - 'a'].push_back(i);
        }


        vector<vii> G(N, vii());
        vector<int> deg(N,0);

        for (int i = 0; i < 26; i++) {
            for (auto u:end[i]) {
                for (auto v:start[i]) {
                    deg[u] -=1;
                    deg[v] +=1;
                    G[u].push_back(ii(v,1));
                }
            }
        }



        int s = INT_MAX;
        for(int i =0; i < N ; i++) {
            //printf("deg[%d]: %d\n", i , deg[i]);
            if (deg[i] <= 0) {
                s = i ;
                break;
            }
        }

        if (s == INT_MAX) {
            printf("x");
            printf("The door cannot be opened.\n");
            continue;
        }


        vector<int> visited(N,0); 
        dfs(G, s, visited);

        bool connected = true;
        for(auto i:visited){
            if (i == 0) {   
                connected = false;
                break;
            }
        }
        
        if (connected == false) {
            printf("The door cannot be opened.\n");
        } else {
            printf("Ordering is possible.\n");
        }
    }

    return 0;
}