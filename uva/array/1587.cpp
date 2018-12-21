#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    int w, h;
    
    while (scanf("%d%d", &w, &h) == 2) {
        vector<int> s;
        s.push_back(w);
        s.push_back(h);
        for (int i = 0 ; i < 5 ; i++) {
            scanf("%d%d", &w, &h);
            s.push_back(w);
            s.push_back(h);
        }
        sort(s.begin(),s.end());
        if (s[0] == s[1] && s[1] == s[2] && s[2] == s[3] && s[4] == s[5] && s[5] == s[6] && s[6] == s[7] && s[8] == s[9] && s[9] == s[10] && s[10] == s[11])
            printf("POSSIBLE\n");
        else
            printf("IMPOSSIBLE\n");
    }
    return 0;
}