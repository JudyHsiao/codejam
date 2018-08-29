#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>

using namespace std;

void split(const string& s, char delim, vector<int>& result) {
    istringstream ss(s);
    string token;
    
    while(getline(ss, token, delim)) {
        result.push_back(stoi(token));
    }
    return;
}
void solve(map<int, int>& m, int offset){
    int n;

    scanf("%d", &n);
    if (n == -1) {
        return;
    }
    if (m.count(offset) == 0) {
        m[offset] = n;
    } else {
         m[offset] += n;
    }
    solve(m, offset -1);
    solve(m ,offset +1);

}

int main(){
    int kase = 0;
    int n;
    while (scanf("%d", &n) ==1 && n!= -1) {
        map<int, int> m;
        kase ++;
        m[0] = n;
        solve(m, -1);
        solve(m, 1);
        printf("Case %d:\n", kase);
        for(auto it = m.begin(); it!=m.end(); it++) {
            if (it!=m.begin()){
                cout << " " << it->second;
            } else {
                cout << it->second;
            }
        }
        cout << "\n\n";
    }

    return 0;
}