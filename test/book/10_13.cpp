#include<string>
#include<vector>
#include<algorithm>
#include<iostream>

#include <functional>

using namespace std;
using namespace std::placeholders;

bool is_longer(const string& s, string::size_type length) {
    return s.length()>=length;
}
int main() {
    vector<string> v({"adafa","as","affasdfa","ii","asfdfasdf","hhh"});
    //auto it = partition(v.begin(), v.end(), [](const string&a) -> bool {return is_longer(a,5);});

    auto it = partition(v.begin(), v.end(), bind(is_longer, _1, 5));
    v.erase(it, v.end());
    for (auto &s:v)
        cout << s << endl; 

}