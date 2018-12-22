#include <cstdio>
#include <cstring>
int main() {
    int kase ;
    char s[80];
    scanf("%d", &kase);

    while (kase --) {
        scanf("%s", s);
        int n = strlen(s);
        int score = 0;
        int ans = 0;
        for (int i  = 0 ; i < n ; i++) {
            if (s[i] == 'O') {
                score ++;
            } else {
                score = 0;
            }
            ans += score;
        }
        printf("%d\n", ans);
    }
    return 0;


}