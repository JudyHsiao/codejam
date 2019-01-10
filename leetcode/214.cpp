#include <vector>
#include <string>
#include <iostream>

using namespace std;
    


int main() {

    string s("abcd");

    cout << s.length() << endl;
    cout << s.size() << endl;
    cout << s.substr(0,4) << endl;
    cout << s.substr(0,3) << endl;
    return 0;
}