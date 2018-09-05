#include <cstdio>
#include <cstring>
#include <string>

using namespace std;
char A[80];
int n, L;

bool valid(int k, char ch) {
    string tmp(A, k);
    tmp.push_back(ch);
    int length = tmp.length();
    for (int i = 1; i < length/2; i++) {
        string s = tmp.substr(length - i, i);
        string t = tmp.substr(length - i*2, i);
        if (s ==t) {
            return false;
        }
    }
    return true;
}

void dfs(int k, int l) {
    for(int i = 0; i<k ; i++) {
        printf("%c", A[i]);
    }
    for (char ch = 'A'; ch < 'A'+l; ch++) {
        if (valid(k, ch)) {
            A[k] = ch;
            dfs(k+1, l);
            A[k]=0;
        }
    }

}

int main() {
    while(scanf("%d%d",&n, &L)==2 && n && L){
        for (int l = 1; l <=L; l++) {
            memset(A, 0, sizeof(A));
            dfs(0, l);
        }
    }
    
}