#include <cstdio>
#include <string>
#include <iostream>
#include <set>
#include <sstream>
using namespace std;

int main(){
    string s, buf;
    set<string> dict;
    while (cin >> s){
        for (int i=0; i < s.length(); i++) {
            if (isalpha(s[i]))
                s[i] = tolower(s[i]);
            else
                s[i]= ' ';
        }
        stringstream ss(s);
        while (ss >> buf) {
            dict.insert(buf);
        }
    }

    for (auto it:dict) {
        cout << it << "\n";
    }

    return 0;
}