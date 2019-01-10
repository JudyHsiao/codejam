#include <iostream>
#include <vector>
using namespace std;

struct X {
    X() {cout << "X()" << endl;}
    X(const X& a) {cout << "X(const&X)" << endl;}
    X& operator=(const X&a) {cout << "=(const&X)" << endl; return *this;};
    ~X() {cout << "~X()" << endl;}
    int i;
};


void A(X x) {
    x.i +=1;
    cout << "A()\n";
}

void B(const X& x) {
    cout << "B()\n";
}

int main() {
    X x;
    //A(x);
    //B(x);
    //X* x = new (X);
    //delete x;

    vector<X> v;
    v.push_back(x);
    return 0;
}