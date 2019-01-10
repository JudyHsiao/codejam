#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    vector <string> v ={"aefasdf","aaa","asdfafdasf","aa","q"};
    string::size_type sz = 6;
    auto t = count_if(v.begin() , v.end(),[=](const string& s) ->bool {return s.length() > sz?true:false;});
    cout << t << endl;
}