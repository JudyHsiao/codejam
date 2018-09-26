#include <cstdio>
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;
const int maxn = 35;



void print(int* a, int  n) {
    for (int i=0; i < n ; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void flip(int* a,  int n, int p) {
    for (int i= 0; i < p-i; i++) {
        swap(a[i], a[p-i]);
    }
    printf("%d ", n-p);
}

int main() {
    int n;
    int a[maxn];
    int b[maxn];
    string s;
    while (getline(cin, s)) {
        cout << s << "\n";
        stringstream ss(s);
        n = 0;
        while (ss >> a[n]) {
            b[n] = a[n];
            n ++;
        }
        sort(b, b+n);

        
        for (int j = n-1; j>=0; j--) {
            int v = b[j];
            //cout << "v:" << v << "\n";
            if (a[j] != v) {
                if(a[0] != v) {
                    int* pos = find(a, a+j+1, v);
                    //cout << "find: " << *pos <<"\n";
                    int i = distance(a, pos);
                    //cout << "i: " << i <<"\n";
                    flip(a, n, i);
                }
                flip(a, n, j);
            }
        }
        //print(a, n);
        //print(b, n);
        printf("0\n");
    }
}

