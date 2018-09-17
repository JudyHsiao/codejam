#include <cstdio>
#include <algorithm>

using namespace std;
int N,s1,v1,s2,v2;
int main()
{
    int n;
    scanf("%d", &n);
    for(int kase = 1; kase <=n; kase++) {
        scanf("%d %d %d %d %d", &N, &s1, &v1, &s2, &v2);
        if (s2 > s1) {
            int tmp = s1;
            s1 = s2;
            s2 = tmp;

            tmp = v1;
            v1 = v2;
            v2 = tmp;
        }
            
        long long best; 
        if (N/s1 >= 65536) {
            for (long long x = 0; x <=s2; x++) {
                long long y = (N - s1*x)/s2;
                best = max(best,  v1*x + v2*y);
            }

            for (long long y = 0; y <=s1; y++) {
                long long x = (N - s2*y)/s1;
                best = max(best,  v1*x + v2*y);
            }
        } else {
            for (long long x = 0; x <= N/s1; x++) {
                long long y = (N - s1*x)/s2;
                best = max(best,  v1*x + v2*y);
            }
        }

        printf("Case #%d: %lld\n", kase, best);
    }
    return 0;
}