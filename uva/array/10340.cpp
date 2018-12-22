#include <iostream>

using namespace std;

int main(){
    string s, t;

    while (cin >>s >>t) {
        int i = 0; 
        int  j = 0;
        string tmp;
        while (j < t.length() && i < s.length()) {
            if (s[i] == t[j]) {
                tmp.push_back(t[j]);
                i++; 
                j++;
            } else {
                j++;
            }
        }
        if (tmp == s) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
    return 0;

}

