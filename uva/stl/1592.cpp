#include <cstdio>
#include <map>
#include <iostream>
#include <sstream>
#include <vector>
#include <array>

using namespace std;

template <typename T>
string join(const T& v, const string& delim) {
    ostringstream s;
    for (const auto& i : v) {
        if (&i != &v[0]) {
            s << delim;
        }
        s << i;
    }
    return s.str();
}

int main(){

    int n, m;
    string s;
    while(getline(cin, s)){
        istringstream ss1(s);
        if(!(ss1 >> n >> m)) break;
        map <string, vector<pair<int,int>>> dict;
        map<pair<int, int>, vector<int>> ans;
        bool is_PNF = true;
        for (int i =0; i < n; i++) {
            getline(cin, s);
            istringstream ss(s);
            string token;
            int j = 0 ;
            while(getline(ss, token, ',')) {
                if (is_PNF == true) {
                    auto it = dict.find(token);
                    if (it!=dict.end()) {
                        auto v = it->second;
                        for (auto p:v) {
                            int r = p.first;
                            int c = p.second;
                            if (c == j) {
                                ans[make_pair(r+1,i+1)].push_back(j+1);
                                if (ans[{r+1,i+1}].size() >=2 ) {
                                    is_PNF = false;
                                }
                            }
                        }
                    }
                    dict[token].push_back({i,j});
                    j+=1;
                }
            }
        }



        if (is_PNF) {
            printf("YES\n");
        } else {
            printf("NO\n");    

            for (auto it:ans) {
                auto k = it.first;
                auto v = it.second;
                if (v.size() >= 2) {
                    printf("%d %d\n", k.first , k.second);
                    cout << join(v, " ") << "\n";
                }
            }
        }
        
    }
    return 0;
}