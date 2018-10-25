#include<cstdio>
#include<cstring>


int main() {
    char s[100+5];

    while(scanf("%s", s) == 1) {

        int n = strlen(s);
        float a = 0;
        float b = 0;
        for(int i= 0; i< n; i++) {
            if (s[i] == '0') {
                b++;
            }
            if (i+1<n && s[i] == '0' && s[i+1] == '0' ) {
                a++;
            }
        }
        if (s[0] == '0' && s[n-1] =='0') {
            a++;
        }
        //printf("%f %f %f %f\n", a, b, a/b, b/n);

        if (a*n > b*b) {
            printf("SHOOT\n");
        } else if (a*n < b*b) {
            printf("ROTATE\n");
        } else {
            printf("EQUAL\n");
        }
    }
    return 0;
}