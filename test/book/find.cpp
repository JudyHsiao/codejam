#include <string>
#include <iostream>
using namespace std;

int main() {
    string s1 ("Judy");
    string s2 ("Alvin");

    cout << (s1+s2).find('d') << endl;


    (s1+s2) = string("family");
    cout<<s1 << endl;
    cout <<s2 << endl;
}