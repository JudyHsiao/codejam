
#include <algorithm>
#include <iterator>
#include <iostream>
using namespace std;


int main() {
    int nums[] = {0,0,1,1,1,2,2,3,3,4} ;
    auto it =  unique(begin(nums), end(nums));
     
    for (auto p = begin(nums); p!=it; p++)
        cout << *p << endl;

    return 0;
}