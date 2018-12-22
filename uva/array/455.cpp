#include <cstdio>
#include <cstring>

int find_period(char* s) {
    int n = strlen(s);
    for (int i = 1; i<=n; i++) {
        if(n%i == 0) {
            bool is_periodic = true;
            for (int k = 0; k < n; k++) {
                if (s[k%i] != s[k]) {
                    is_periodic = false;
                    break;
                }
            }
            if (is_periodic)
                return i;
        }
    }
    return -1;

}
int main() {
    char s[80+5];
    int n ;
    scanf("%d",&n);
    while(n--) {
        scanf("%s", s);
        int k = find_period(s);
        printf("%d\n", k);
        if (n)
            printf("\n");
    }
}