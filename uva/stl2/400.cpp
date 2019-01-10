#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;
const int maxcol = 60;
const int maxn = 100+5;
string filenames[maxn];
void print(const string& s, int n, char ch ) {
    cout << s ;
    for (int i = 0; i < n -s.length(); i++)
        cout << ch;
}
int main() {
    int n;
    while(cin >> n) {
        string::size_type M = 0;

        for (int i = 0 ; i < n; i++) {
            cin >> filenames[i];
            M = max(M, filenames[i].length());
        }

        int cols = (maxcol - M)/(M+2) + 1;
        int rows = ceil(static_cast<float> (n) / cols);
        print("", 60, '-');    
        cout << "\n";
        sort(filenames, filenames+n);
        for (int r = 0 ; r < rows; r++) {
            for (int c = 0 ; c< cols; c++) {
                int idx = c * rows + r;
                if (idx < n)
                    print(filenames[idx], c== cols-1? M:M+2, ' ' );
            }
            cout <<"\n";
        }     
    }
    return 0;
}