#include <cstdio>
#include <vector>
using namespace std;

int main(){

    int k;
    
    while(scanf("%d", &k) ==1) {
        int cnt = 0;
        vector<pair<int, int>> ans;
        for (int y = 1; y<= 2*k; y++ ) {
            if (y-k>0 && k*y > y-k && k*y % (y-k) ==0) {
                int x = k*y / (y-k);
                cnt +=1;
                ans.push_back(make_pair(x, y));
            }   
        }
        printf("%d\n", cnt);
        for (int i = 0; i < ans.size(); i++) {
            int x = ans[i].first;
            int y = ans[i].second;
            printf("1/%d = 1/%d + 1/%d\n", k, x, y);
        }
    }
}