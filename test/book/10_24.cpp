#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
using namespace std::placeholders;

bool check_size(const string& s , string::size_type sz) {
    return s.length() > sz?true:false;
}
int main() {
    vector <string> v ={"aefasdf","aaa","asdfafdasf","aa","q"};
    string::size_type sz = 6;
    auto it = find_if(v.begin() , v.end(), bind(check_size, _1, 6));
    cout << *it << endl;
}