#include <set>
#include <tuple>
#include <iostream>

using namespace std;

int main() {
    set<tuple<int, int, int>> h;

    h.insert({1,2,3});
    cout << h.count({1,2,3}) << endl;
    cout << h.count({3,2,1}) << endl;
    return 0;
}