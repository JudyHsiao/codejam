#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <list>
#include <cstring>
#include <algorithm>

int G[256][256];
int best;
char A[26];
char Ans[26];
int used[256];
int n;
using namespace std;

void split(const string& s, char delim, vector<string>& result) {
    istringstream ss(s);
    string token;
    
    while(getline(ss, token, delim)) {
        result.push_back(token);
    }
    return;
}
int bandwidth(int k) {
    int b[k];
    memset(b, 0, sizeof(b));
    for (int i=0; i <k; i++) {
        for(int j = i+1; j <k ; j++) {
            if (G[A[i]][A[j]] == 1) {
                b[i] = max(b[i], j-i);
            }
        }
    }

    return *max_element(b, b+k);

}

void dfs(int k, const set<char>& V) {
    if (k == V.size()) {
        int b = bandwidth(k);
        if (best == -1 || b < best) {
            best = b;
            memcpy(Ans, A, n);
        }
        return;
    }

    for(auto v:V) {
        if (used[v] == 0) {
            A[k]= v;
            used[v] =1;
            int b = bandwidth(k+1);  //0 ~ k 有值, 長度為k+1
            if (best == -1 || b < best ) {
                dfs(k+1, V);
            }
            used[v] = 0;
        } 
    }

}
using namespace std;
int main(){
    string s;
    while (getline(cin, s) && s!="#") {
        memset(G, 0, sizeof(G));
        set<char> V;
        vector<string> r;
        split(s, ';', r);
        for (auto c:r) {
            char u = c[0];
            for(int i =2; i < c.length(); i++) {
                char v = c[i];
                V.insert(v);
                V.insert(u);
                G[u][v] = 1;
                G[v][u] = 1;
            }
        }
        memset(A, 0 , sizeof(A));
        memset(Ans, 0, sizeof(Ans));
        memset(used, 0 , sizeof(used));
        n = V.size();
        best = -1;
        dfs(0, V);

        for(int i =0 ; i< n; i++) {
            printf("%c ", Ans[i]);
        }
        printf("-> %d\n", best);
    }


}