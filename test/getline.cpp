#include <iostream>
#include <string>

using namespace std;
int main() {
    string line;
    while(getline(cin, line)) {
        const string s = line;
        for(auto &c:s)
            c = toupper(c);
        cout << line << endl;
    }

    
    return 0;
}