#include <cstdio>
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <algorithm>
#include <set>

using namespace std;

string normalized(string s)  {
    for (int i=0; i < s.size(); i ++) {
        s[i] = tolower(s[i]);
    }
    sort(s.begin(), s.end());
    return s;
}

int main() {
    string s, buf;
    set<string> ans;
    unordered_map<string, vector<string>> map;
    
    while (cin >> s && s != "#") {
        stringstream ss(s);
        while (ss >> buf) {
            string key = normalized(buf);
            map[key].push_back(buf);
        }
    }

    for ( auto it=map.begin(); it != map.end(); it++) {
        if ( (*it).second.size() ==1 ) { 
            ans.insert((*it).second[0]);
        }
    }

      for (auto it:ans) {
        cout << it << "\n";
    }


    return 0;
}