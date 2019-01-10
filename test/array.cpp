#include <iostream>

using namespace std;
int main() {
    const size_t m = 3, n =4;
    int ia[m][n] = {
        {0,1,2,3},
        {4,5,6,7},
        {8,9,10,11}
    };

    for (size_t i = 0 ; i != m; i++) {
        for (size_t j = 0 ; j !=n; j++) {
            cout << ia[i][j];
        }
    }
    cout << endl;



    using int_array = int[4];
    for(const int_array &p:ia) {
        for (int c:p) {
            cout << c;
        }
    }
    cout << endl;

    for (const auto &row: ia)   // control varibal must be reference
        for (auto v:row) 
            cout << v;
    cout << endl;



    

}