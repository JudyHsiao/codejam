#include <iostream>

using namespace std;
int main(){
    int i = 5;
    auto f = [&]()mutable  ->bool  { return --i ==0 ? true: false;};
    while (!f()) {
        cout << i << endl;
    }
    return 0;
}