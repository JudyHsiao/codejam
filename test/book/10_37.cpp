#include<vector>
#include<list>
#include<iterator>

#include<iostream>
using namespace std;
int main() {
    vector<int> v = {0,1,2,3,4,5,6,7,8,9};
    list <int> li;
    copy(v.begin()+3, v.begin()+8, front_inserter(li));

    for(const auto &it :li) 
        cout << it << endl;

    
}