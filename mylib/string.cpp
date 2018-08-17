#include <cstdio>
#include <iostream>
#include <sstream>
#include <vector>
#include <sstream>
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

void split(string s, char delim, vector<string>& result) {
    istringstream ss(s);
    string token;
    
    while(getline(ss, token, delim)) {
        result.push_back(token);
    }
    return;
}


void trim(string &s) {
    
}

int main() {

    string s = "1,2,3,4,5";
    vector<string> v;
    split(s, ',', v);
    for (auto n:v) {
        cout << n << "\n"; 
    }
    cout << join(vector<int>({1, 2, 3, 4, 5}), ",") << endl;
}



