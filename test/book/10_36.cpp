#include <algorithm>
#include <list>
#include <iterator>
#include<iostream>

using namespace std;

int main() {
    list <int> li = {0,1,2,3,0,4,5,6,0,9,10};
    auto it = find (li.crbegin(), li.crend(), 0);
    cout << distance(li.cbegin(), it.base()) -1 << endl;

}