#include <iostream>

using namespace std;
class A {
public:
    int a[10] = {0,1,2,3,4,5,6,7,8,9};
};

int main() {
    A a1;
    for (int i = 0; i < 10; i++)
        a1.a[i] += 10;
    
    A a2 = a1;

    for(int i = 0; i <10 ; i++)
        cout << a2.a[i] << endl;
}