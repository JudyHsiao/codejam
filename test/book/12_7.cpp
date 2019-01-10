#include <vector>
#include <iostream>

using namespace std;

shared_ptr<vector<int>> f() {
    return make_shared<vector<int>>();
}

void input(shared_ptr<vector<int>> v) {
    int i;
    while (cin >> i) {
        v->push_back(i);
    }
    return;
} 

void print(const shared_ptr<vector<int>> v) {
    for(const auto & i : *v) {
        cout << i << endl;
    }
    return;
}


int main() {
    shared_ptr<vector<int>> v = f();
    input(v);
    print(v);
    return 0;
}