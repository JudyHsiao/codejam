#include <map>
#include <algorithm>
#include <list>
#include <string>
#include <iostream>
using namespace std;

int main() {
    map <string,list<int>> m ={{"yoyo", {0,1,2,3}}};
    auto it = m.begin(); 

    for(const auto &p:m) {
        cout << p.first <<endl;
    }

    list <int> li = {0};
    auto it2 = li.begin();
    (*it2)++;
    for(const auto &i:li) {
        cout << i <<endl;
    }
    
}