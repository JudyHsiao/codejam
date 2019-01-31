#include <iostream>
using namespace std;
class A {
public:
    virtual void print() {
        printf("I am A\n");
    }
};

class B: public A {
public:
    void print() {
        printf("I am B\n");
    }
};


int main () {


    B b;
    b.print();

    A &p = b;
    p.print();


    double g = 1.0/3;
    if (8/g/g/g ==24*9)
        cout << "YES\n" <<endl;

   
    return 0;

}