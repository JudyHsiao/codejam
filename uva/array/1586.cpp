#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main(){
    char A[5][6];
    char op;
    int kase = 1;
    while (gets(&A[0][0])) {
        if (strcmp(A[0], "Z") ==0)
            return 0;
        for (int i = 1; i < 5; i++) {
            gets(&A[i][0]);
            if (strlen(A[i]) <5) {
                A[i][4]=' ';
                A[i][5] = 0;
            }
        }

        int r = 0, c= 0;
        for (int i = 0; i < 5 ; i++)
            for (int j =0; j < 5 ; j++)
                if (A[i][j] == ' ') {
                    r = i;
                    c = j;
                }
        if (kase > 1) {
            printf("\n");
        }
        printf("Puzzle #%d:\n", kase++);
        bool no_conf = false;
        while(scanf("%c",&op) == 1) {
            if (no_conf == true) {
                if (op == '0') {
                    getchar();
                    break;
                } else {
                    continue;
                }
            }
            if (op == 'A') {
                if (r == 0) {
                    printf("This puzzle has no final configuration.\n");
                    no_conf = true;
                    continue;
                }
                swap(A[r-1][c], A[r][c]);
                r--;

            } else if (op == 'R') {
                if (c == 4) {
                    printf("This puzzle has no final configuration.\n");
                    no_conf = true;
                    continue;
                }
                swap(A[r][c+1], A[r][c]);
                c++;

            } else if (op == 'B') {
                if (r == 4) {
                    printf("This puzzle has no final configuration.\n");
                    no_conf = true;
                    continue;
                }
                swap(A[r+1][c], A[r][c]);
                r++;

            } else if (op == 'L') {
                if (c == 0) {
                    printf("This puzzle has no final configuration.\n");
                    no_conf = true;
                    continue;
                }
                swap(A[r][c-1], A[r][c]);
                c--;
            } else if (op == '0') {
                for (int i = 0; i < 5; i++)
                    printf("%s\n", A[i]);
                getchar();
                break;
            }

        } 
    }
    return 0;
}