#include<vector>
#include<list>
#include <iostream>

using namespace std;

int main() {
    list <int> a = {1,2,3,4,5,6,7};

    auto it = a.erase(a.begin(), a.begin());
    cout <<*it << endl; 

    for(auto &v:a)
        cout << v << endl;
}