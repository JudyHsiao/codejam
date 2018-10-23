#include <cstdio>
#include <map>
#include <vector>

using namespace std;

const int maxn = 7000 +5;
int A[maxn];


int main() {
    int T;
    scanf("%d", &T);
    for (int t = 1; t <=T ; t++) {
        int n;
        map <int, int> h;
        scanf("%d", &n);
        long nZero = 0;
        long nNonZero = 0;

        for (int i =0 ; i < n ; i++){
            scanf("%d", &A[i]);
            if (A[i] == 0) {
                nZero++;
            } else {
                nNonZero++;
            }

            if (h.count(A[i]) == 0 ) {
                h[A[i]] = 1;
            } else {
                h[A[i]]+=1;
            }
        }

        long long ans = 0;
        if (nZero >= 2) {
            ans += nZero * (nZero-1) /2 * nNonZero;
        }

        if (nZero >= 3) {
            ans += nZero * (nZero-1) *  (nZero -2)/6 ;
        }


        sort(A, A+n);
        for (int i = 0; i < n; i++) {
            h[A[i]] -=1;

            vector<int> tmp;
            for (int j = i+1; j < n; j++) {
                h[A[j]] -=1;
                tmp.push_back(A[j]);
                long long z = (long)A[i]*A[j];
                if (z <=200000 && z > 0) {
                    int c = h[z];
                    //printf("z: %lld c: %d\n",z, c);
                    ans+=c;
                }
            }
            for (auto k :tmp){
                    h[k]+=1;
            }
        }
        /*
        for (int i =0 ; i < n ; i++){
            printf("%d ", A[i]);
        }
        */

        printf("Case #%d: %lld\n", t, ans);
    }
    return 0;
}