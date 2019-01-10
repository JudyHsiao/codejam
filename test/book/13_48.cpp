#include "String.h"
#include <vector>
#include <iostream>
using namespace std;

int main() {
    vector<String> v;

    for (char ch = 'a' ; ch < 'k'; ch++){
        cout << v.capacity() << endl;
        cout << ch << endl;
        v.push_back(String(&ch));
    }

    String s1("Judy");
    

    return 0;
}