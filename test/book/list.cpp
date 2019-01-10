#include<list>
#include<iostream>

using namespace std;
int main()
{
    list<int> li = {0,123,24,2,5,6};
    li.sort();
    for (const auto &i :li)
        cout << i << endl;

}