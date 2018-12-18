#include <cstdio>
#include <string>
using namespace std;
char A[10+5][10+5];

int main() {
    int r, c;
    int kase=1;
    while(scanf("%d%d",&r, &c)==2 && r ) {
        for (int i = 0; i < r; i++) {
            scanf("%s", A[i]);
        }

        int cnt = 0;
        int start =-1;
        if (kase > 1)
            printf("\n");
        printf("puzzle #%d:\n",kase++);
        printf("Across\n");
        for (int i = 0; i < r; i++) {
            string buf;
            for (int j = 0; j < c ; j++) {
                if (A[i][j] == '*') {
                    if (buf.length()> 0) {
                        printf("  %d.%s\n", start, buf.c_str());
                        buf = "";
                        start = -1;
                    }
                } else {
                    if (i == 0 || A[i-1][j] =='*' || j ==0 || A[i][j-1] =='*' ){
                        cnt++;
                        if (start == -1)
                            start = cnt;
                    }
                    buf.push_back(A[i][j]);
                }
            }
            if (buf.length()> 0) {
                printf("  %d.%s\n", start, buf.c_str());
                buf = "";
                start= -1;
            }
        }
        printf("Down\n");
        cnt = 0;
        start =-1;
        for (int i = 0; i < r; i++) {
            string buf;
            for (int j = 0; j < c ; j++) {
                if (i == 0 || A[i-1][j] =='*' || j ==0 || A[i][j-1] =='*' ){
                        if (A[i][j] != '*'){
                            cnt++;
                            if ( (i == 0 || A[i-1][j] =='*') && start == -1 )
                                start = cnt;
                        }
                }
                if (start > -1) {
                    for(int k = i; k < r; k++) {
                        if (A[k][j] == '*') {
                            if (buf.length()> 0) {
                                printf("  %d.%s\n", start, buf.c_str());
                                buf = "";
                                start = -1;
                                break;
                            }
                        } else {
                            buf.push_back(A[k][j]);
                        }
                    }
                    if (buf.length()> 0) {
                        printf("  %d.%s\n", start, buf.c_str());
                        buf = "";
                        start= -1;
                    }
                }
            }
        }
    }
}