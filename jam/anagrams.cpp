#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

void all_substrings(const string s, vector<string>& sub) {
    for (int l = 1 ; l <= s.length(); l ++) {
        for (int i = 0 ; i <= s.length()-l ; i++) {
            sub.push_back(s.substr(i, l));
        }
    }

}

int main() {
    int T;
    int n;
    string A, B;
    int kase = 1;
    cin >> T;
    while (T--) {
        cin >> n;
        cin >> A;
        cin >> B;

        vector<string> subA;
        all_substrings(A, subA);
        vector<string> subB;
        all_substrings(B, subB);

        set<string> subBSet;
        for (auto s: subB) {
            sort(s.begin(), s.end());
            subBSet.insert(s);
        }

        int ans =0 ;
        for (auto s: subA) {
            sort(s.begin(), s.end());
            if (subBSet.count(s)) {
                ans += 1;
            }
        }

        printf("Case #%d: %d\n",kase++, ans);
    }


}