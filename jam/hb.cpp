#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

char s[5000000+5];
int psum[5000000+5];

int main() {
    int T;
    scanf("%d", &T);
    //printf("T:%d\n", T);
    int t = 1;

    while (T--) {
        int n ;
        scanf("%d", &n);
        //memset(s, 0, sizeof(s));
        //memset(psum, 0, sizeof(psum));
        scanf("%s", s);
        for (int i = 1; i <= n; i++) {
            psum[i] = psum[i-1] + s[i-1]-'0';
            //printf("%d ", psum[i]);
        }

        int l = ceil((float)n/2);

        int best = 0;
        for (int i = l; i <=n; i++) {
            best = max(best,psum[i]- psum[i-l]);
        }

        printf("Case #%d: %d\n", t++, best);

    }
    return 0;

}