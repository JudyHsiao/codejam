#include<cstdio>
#include <vector>
#include <stack>

using namespace std;
int main() {
    int n;
    int kase = 0;
    while (scanf("%d", &n) ==1 && n) {
        if (kase > 0) {
            printf("\n");
        } 
        kase++;
        int d;
        vector <int> A;
        vector <int> B;
        A.resize(n);
        B.resize(n);

        while (scanf("%d", &d) ==1 && d) {
            A[0] =d;
            B[0] =1;
            for (int i =1 ; i < n ;i++){
                    scanf("%d", &d);
                    A[i] = d;
                    B[i] = i+1;
            }

            int i =0, j= 0;
            bool ok= true;
            stack <int> S;
            while(i < n || j< n || !S.empty()) {
                if (A[i] == B[j]) {
                    i+=1;
                    j+=1;
                } else if (!S.empty() && A[i] == S.top()){

                    i+=1;
                    S.pop();
                } else if (j < n ) {
                    S.push(B[j]);
                    j+=1;
                } else {
                    ok = false;
                    break;
                }   
            }
            printf("%s\n", ok ? "Yes": "No");
        }
    }

    return 0;
}