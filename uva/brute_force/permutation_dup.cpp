#include <cstdio>
int A[20];
int B[20];
bool used[20];

void permutation(int n, int* B, int cur) {
    if (cur == n ) {
        for(int i = 0 ; i < n ; i++){
            printf("%d ", B[i]);
        }
        printf("\n");
        return;
    }

    for (int i = 0; i < n ;i++) {
        if (used[i] == false) {
            B[cur] = A[i];
            used[i] = true;
            permutation(n, B, cur+1);
            used[i] = false;
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int cnt = 1;
    for (int i = 0; i < 2*n ; i+=2) {
        A[i] = cnt;
        A[i+1] = cnt;
        cnt+=1;
        used[i]=false;
        used[i+1]=false;
    }

    permutation(2*n, B, 0);
}