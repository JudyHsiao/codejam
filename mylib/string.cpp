#include <cstdio>
#include <iostream>
#include <sstream>
#include <vector>

#include <map>
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

void split(const string& s, char delim, vector<string>& result) {
    istringstream ss(s);
    string token;
    
    while(getline(ss, token, delim)) {
        result.push_back(token);
    }
    return;
}

map<string, int> id;
int ID(const string& s) {
  if(!id.count(s)) {
    id[s] = id.size();
  }
  return id[s];
}


string trim(const string& str)
{
    size_t first = str.find_first_not_of(' ');
    if (string::npos == first)
    {
        return str;
    }
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last - first + 1));
}

int main() {

    string s = "1,2,3,4,5";
    vector<string> v;
    split(s, ',', v);
    for (auto n:v) {
        cout << n << "\n"; 
    }
    cout << join(vector<int>({1, 2, 3, 4, 5}), ",") << endl;

    cout<< ID("a") <<" " <<ID("b") <<" " <<ID("b")<< " " <<ID("c")<< endl;
}



