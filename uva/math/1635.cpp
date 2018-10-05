#include<cmath>
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;



const int maxn = 100000 + 5;
int bad[maxn];

struct factor {
    int a;
    int n;
    factor(int a, int n):a(a),n(n){}
};

void prime_factor_decomposition(int n, vector<factor> &factors) {
    int m = floor(sqrt(n) + 0.5);
    for (int i = 2; i <= m; i++) {
        int e = 0;
        while (n % i == 0) {
            e++;
            n /= i;
        }
        if (e > 0) {
            factors.push_back(factor(i, e));
        }

        if (n ==1) {
            break;
        }
    }
    if (n > 1) {
         factors.push_back(factor(n, 1));
    }

}

int main() {
    int n, m, kase = 0;

    while(cin >>n >>m){
        vector<factor> prime_factors;
        prime_factor_decomposition(m, prime_factors);
        memset(bad, 0 , sizeof(bad));
        n--;

        for(auto f:prime_factors) {
           int e = 0;   // 記錄連乘績約分的結果
           for(int k = 1; k < n; k++) {
               int x = n - k +1;
               while (x%f.a == 0) {
                   x/=f.a;
                   e++;
               }
               x = k;
               while(x%f.a == 0) {
                   x/=f.a;
                   e--;
               }
               if(e < f.n){
                   bad[k] = 1;
               }
           }
        }

        vector<int> ans;
        for(int k =1; k < n; k++) {
            if(!bad[k])
                ans.push_back(k+1);
        }
        cout << ans.size() <<"\n";
        if(!ans.empty()) {
            cout << ans[0];
            for(int i = 1; i < ans.size(); i++) cout << " " << ans[i];
        }
        cout << "\n";
    }
    return 0;
}