#include <vector>
using namespace std;

typedef vector<long long> vec;
typedef vector<vec> mat;
const int MOD =1000000007;


mat mul(const mat& A, const mat& B) {
    mat C(A.size(), vec(B[0].size()));
    for (int i = 0; i < A.size(); i++) {
        for (int j = 0; j < B[0].size(); j++) {
            for (int k = 0 ; k < B.size(); k++) {
                    C[i][j]= (C[i][j]+ A[i][k]*B[k][j])%MOD;
                }
        }
    }
    return C;
}
    
mat pow(mat A, int n) {
    mat B (A.size(), vec(A.size()));
    for (int i = 0; i<A.size(); i++) {
        B[i][i] = 1;
    }
    
    while (n > 0 ) {
        if (n&1)
            B= mul(B,A);
        A = mul(A,A);
        n = n/2;
    }
    return B;
}