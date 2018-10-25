#include<cstdio>
#include <algorithm>
using namespace std;

int A[6][6];

int main()
{
    
    fill_n(&A[0][0], 6 * 6, -3);

    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            printf("%d", A[i][j]);
        
        }
        printf("\n");
    }
    return 0;
    
}