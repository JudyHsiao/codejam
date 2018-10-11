#include <cstdio>
#include <cstring>
#include <cmath>

int f[30+5];
int g[30+5];

int main(){
    int n;

    memset(f, 0 , sizeof(f));
    memset(g, 0, sizeof(g));
    g[0] = 1;
    g[1] = 2;
    g[2] = 4;

    for(int i = 3; i <=30; i++) {
        for (int j= 2; j <= i-2; j++) {
            f[i] +=g[j-2]* pow(2, i-j-2); 
        }
        f[i] +=pow(2, i-3);
        g[i] = pow(2, i) - f[i];
    }


    while(scanf("%d", &n) == 1 && n) {
        printf("%d\n", f[n]);
    }
    return 0;
}