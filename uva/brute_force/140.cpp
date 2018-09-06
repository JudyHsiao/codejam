#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <set>

int G[256][256];
int best;
char A[26];
int used[256];
int n;

void split(const string& s, char delim, vector<string>& result) {
    istringstream ss(s);
    string token;
    
    while(getline(ss, token, delim)) {
        result.push_back(token);
    }
    return;
}


void dfs(int k, set<char> V) {
    if (k == V.size()) {

        return;
    }
    for (auto ch:V) {

    }
}
using namespace std;
int main(){
    string s;
    while (getline(cin, s) && s!="#") {
        memset(G, sizeof(G), 0);
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
        memset(used, 0 , sizeof(used));
        n = V.size();
        dfs(0, V);
    }


}