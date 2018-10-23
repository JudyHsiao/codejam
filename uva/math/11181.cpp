#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

double p[20];
double q[20];
using namespace std;

void solve(int n, int r){
    std::vector<bool> v(n);
    std::fill(v.begin(), v.end(), false);
    std::fill(v.end() - r, v.end(), true);
    
    double tot=0;
    do {
        double r=1;
        for (int i = 0; i < n; ++i) {          
            if (v[i]) {
                r = r * p[i];
            } else {
                r = r * (1-p[i]);
            }
        }

        tot += r;
        for (int i = 0; i < n; ++i) {
             if (v[i]) {
                q[i] +=r;
             }
        }
        
    } while (std::next_permutation(v.begin(), v.end()));
    

    for(int i = 0; i < n; i++)
        q[i]/=tot;
}

int main(){
    int n, r;
    int kase =1;

    while( scanf("%d %d", &n, &r)==2 ) {
        if (n==0 && r==0) {
            return 0;
        }

        memset(p, 0, sizeof(p));
        memset(q, 0, sizeof(q));
        for (int i =0 ; i < n ; i++) {
            scanf("%lf", &p[i]);
        }
        
        solve(n, r);
        
        printf("Case %d:\n", kase++);
        for(int i = 0; i < n; i++)
            printf("%.6lf\n", q[i]);

    } 
     

    return 0;
}