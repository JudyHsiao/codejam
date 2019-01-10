#include <algorithm>
#include <deque>
#include <vector>
#include <iostream>
#include <iterator>

using namespace std;
int main() {
    vector<int> v = {1,2,3,4,5,6,7,8,9};
    deque<int> vi1, vi2, vi3;
    copy(v.cbegin(), v.cend(), front_inserter(vi1));
    copy(v.cbegin(), v.cend(), back_inserter(vi2));
    copy(v.cbegin(), v.cend(), inserter(vi3, vi3.begin()));

    for(auto &n:vi1)
        cout << n << " ";
    cout << endl;
    
    for(auto &n:vi2)
        cout << n << " ";
    cout << endl;

    for(auto &n:vi3)
        cout << n << " ";
    cout << endl;

}