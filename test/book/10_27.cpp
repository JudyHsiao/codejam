#include <algorithm>
#include <list>
#include <vector>
#include <iostream>
#include <iterator>

using namespace std;

int main() {
    vector<int> a = {1,4,2,4,1,33,5,2};
    list<int>b;

    sort(a.begin(), a.end());
    unique_copy(a.cbegin(), a.cend(), back_inserter(b));

    for(auto v:b)
        cout<<v<< endl;

    return 0;
}