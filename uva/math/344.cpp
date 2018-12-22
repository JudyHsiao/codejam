#include <cstdio>

int main() {
    int k, n;
    int i, v, x, c, l;
    while(scanf("%d", &k) == 1 && k) {
        i = 0;
        v = 0;
        x = 0;
        c = 0;
        l = 0;
        printf("%d: ",k);
        for(int j = 1; j <=k ; j ++) {
            n = j;
            while(n) {
                if (n >= 100) {
                    c++;
                    n-=100;
                } else if (n >= 90) {
                    x++;
                    c++;
                    n-=90;
                } else if (n >=50) {
                    l++;
                    n-=50;
                } else if (n>=40) {
                    l++;
                    x++;
                    n-=40;
                } else if (n>=10) {
                    x++;
                    n-=10;
                } else if (n >= 9) {
                    i++;
                    x++;
                    n-=9;
                } else if (n >=5) {
                    v++;
                    n-=5;
                } else if (n>=4) {
                    i++;
                    v++;
                    n-=4;
                } else if (n>=1) {
                    i++;
                    n-=1;
                }
            }
        }
        printf("%d i, %d v, %d x, %d l, %d c\n",i,v,x,l,c);
    }
    return 0;
}