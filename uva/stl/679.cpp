#include <cstdio>
#include <cstring>

const int maxD = 20;
int s[1<<maxD];
int main()
{
    int D, I;
    int n;
    scanf("%d", &n);
    
    while (scanf("%d %d",&D,&I) ==2 ) {
        memset(s, 0, sizeof(s));
        int k;
        int n = (1<<D) -1;

        for (int i =0; i <I; i++) {
            k=1;
            while(k<=n) {
                s[k] = !s[k];
                k =s[k]?k*2:k*2+1;
            }
        }
        printf("%d\n", k/2);

    } 
    return 0;
}