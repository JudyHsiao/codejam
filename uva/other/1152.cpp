#include <cstdio>
#include <multiset>
using namespace std;

int A[4000], B[4000],C[4000], D[4000];
int X[16000000];


int main()
{   
    int kase;
    scanf("%d", &kase);
    while(kase) {
        int n;
        scanf("%d", &n);
        for(int i = 0; i < n ;i++) {
            scanf("%d %d %d %d", &A[i], &B[i], &C[i], &D[i]);
            i+=1;
        }  
        int k = 0;
        multiset<int> Y;
        for (int i =0; i < n ; i++) {
            for (int j =0 ; j < n ;j++) {
                X[k] = A[i]+B[j];
                Y.insert(C[i]+D[j]);
                k+=1;
            }
        }

        int ans = 0;
        for(int i = 0; i < n*n; i++) {
            ans+=Y.count(-X[i]);
        }
        printf("%d\n", ans);



        kase --;
    }


    return 0;
}