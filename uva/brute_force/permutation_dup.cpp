#include <cstdio>
#include <algorithm>
int A[20];
int B[20];
int used[20];

using namespace std;

void permutation(int n, int* B, int cur) {
    if (cur == n ) {
        for(int i = 0 ; i < n ; i++){
            printf("%d ", B[i]);
        }
        printf("\n");
        return;
    }

    for (int i = 0; i < n ;i++) {
        if(i==0 || A[i]!=A[i-1]) {   // 相同的數字 不再嘗試一次
            int c1 = 0, c2 = 0;
            for(int j =0; j <cur; j++)
                if(A[i]==B[j])
                    c1+=1;
            for(int j=0; j<n;  j++)
                if(A[i] == A[j])
                    c2+=1;
            if (c1 < c2){   //個數未用完
                B[cur] = A[i];
                permutation(n, B, cur+1);
            }
        }
    }
}

int main() {
  int i, n;
  scanf("%d", &n);
  for(i = 0; i < n; i++)
    scanf("%d", &A[i]);
  sort(A, A+n);
  permutation(n, B, 0);
  return 0;
}