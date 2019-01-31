#include <string>
#include <iostream>
using namespace std;

int main() {
    string s("(");
    int pos = -1;
    
    while( (pos = s.find(')', pos+1))!=string::npos) {
        cout <<pos << endl;
                    
    }
    pos = string::npos;
    while( (pos = s.rfind('(', pos-1))!=string::npos) {
        cout <<pos << endl;
                    
    }
}