#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

// 输出字符串s，长度不足len时补字符extra
void print(const string& s, int len, char extra) {
  cout << s;
  for(int i = 0; i < len-s.length(); i++)
    cout << extra;
}

int main(){
    int n;
    while(scanf("%d",&n) == 1) {
        vector<string> filenames;
        filenames.resize(n);
        int M = 0;
        for (int i =0; i <n; i++) {
            cin >> filenames[i];
            M = max(M, (int)filenames[i].length());
        }
        sort(filenames.begin(),filenames.end());
        printf("------------------------------------------------------------\n");

        int cols = (60 - M)/(M+2) +1;
        int rows = (n-1) / cols +1;

        for (int r =0; r < rows; r++) {
            for (int c =0; c< cols; c++) {
                int idx = c * rows +r;
                if (idx < n) {
                    print(filenames[idx],  c == cols-1 ? M : M+2 , ' ');
                }
            }
            cout << "\n";
        }
 
    }
}