#include "String.h"
#include <iostream>
using namespace std;

int main() {
    String s;

    cout<< s.size() << endl;
    cout<<s.str() << endl;

    String s2("Judy");
    cout <<s2.size() << endl;
    cout << s2.str() << endl;

    s = s2;
    cout<< s.size() << endl;
    cout<<s.str() << endl;

    return 0;
}