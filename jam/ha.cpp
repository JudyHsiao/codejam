#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>

using namespace std;

bool compare(string &s1,string &s2) 
{ 
    return s1.size() < s2.size(); 
}

bool startsWith(const string& haystack, const string& needle) {
    return needle.length() <= haystack.length() 
        && equal(needle.begin(), needle.end(), haystack.begin());
}

int main(){
    int T;
    cin >> T;
    int t =1;
    while(T--) {
        int n, p;
        string prefixs[100+5];

        cin >> n >> p;

        for(int i = 0 ; i < p; i++) {
            cin >> prefixs[i];
        }
        // Function to perform sorting 
        sort(prefixs, prefixs+p, compare);
        long long total = pow(2, n);

        for(int i = 0; i < p ; i++) {
            bool visit = false;
            for (int j = 0; j< i ; j ++) {
                if (startsWith(prefixs[i], prefixs[j])){
                    visit = true;
                    break;
                }
            }
            if (visit == false) {
                int n1 = n - prefixs[i].length();
                total -= pow(2, n1);
            }
        }

        printf("Case #%d: %lld\n", t++, total);

    }
    return 0;
}