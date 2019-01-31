#include <memory>
#include <iostream>

using namespace std;

bool f (unique_ptr<int>& p) {
    cout << *p << endl;
    return true;
}

int main() {

    unique_ptr<int> a (new int(10));
    f(a);

    shared_ptr<int> b (new int(10),[]( int *p ) {
                               cout << "delete 10!" << endl;
                               delete p;
                           });
    b = shared_ptr<int> (new int(20));
    cout << *b << endl;


}