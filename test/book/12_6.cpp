#include <vector>
#include <iostream>

using namespace std;

vector<int>* f() {
    return new vector<int>();
}

void input(vector<int>* v) {
    int i;
    while (cin >> i) {
        v->push_back(i);
    }
    return;
} 

void print(const vector<int>* v) {
    for(const auto & i : *v) {
        cout << i << endl;
    }
    return;
}


int main() {
    vector<int>* v = f();
    input(v);
    print(v);
    delete v;
    return 0;
}