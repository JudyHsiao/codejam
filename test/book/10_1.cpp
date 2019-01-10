#include<algorithm>
#include<vector>
#include<list>
#include<iostream>

using namespace std;

int main () {
    vector<int> v = {0,0,0,1,2,3,3,4,4,5};
    auto i = count(v.begin(), v.end(), 0);


    list<string> l = {"aa", "aa", "bb"};
    auto j = count(l.begin(), l.end(), "aa");
    cout << i << endl;
    cout << j << endl;
}