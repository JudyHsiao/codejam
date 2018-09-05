#include <cstdio>
using namespace std;

int A[20];
int B[20];
bool used[20];
void print_subset(int n, int* B, int cur) {
    for (int i =0; i < cur; i++) {
        printf("%d ", B[i]);
    }
    printf("\n");

    for (int i= 0; i < n; i++) {
        if (cur == 0 || A[i] > B[cur - 1]) {
            used[i] = true;
            B[cur] = A[i];
            print_subset(n, B, cur + 1);
            used[i] = false;
        } 

    }
}



int main() {
  int n;
  scanf("%d", &n);
  for(int i =0; i< n; i++) {
      A[i] = i+1;
      used[i] = false;
  }
  print_subset(n, B, 0);
  return 0;
}