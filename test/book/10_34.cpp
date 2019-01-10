#include <vector>
#include <iterator>
#include <iostream>

using namespace std;

int main() {
    vector <int> v = {1,2,3,4,5,6,7,8};

    for(auto it = v.crbegin(); it!=v.crend(); it++)
        cout << *it << endl;

    for(auto it = v.cend() -1; it+1!=v.cbegin(); it--)
        cout << *it << endl;
   

    return 0;
}