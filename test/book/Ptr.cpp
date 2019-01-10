#include<iostream>
#include<cstring>

using namespace std;
class Ptr{
public:
    Ptr():str(nullptr),v(0){};
    Ptr(const char *, int n);
    const char* getP()const;
private:
    const char *str;
    const int v;
};

const char* Ptr::getP()const {
    return str;
}

Ptr::Ptr(const char* s, int n):str((new string(s))->c_str()), v(n){};

int main() {
    Ptr p1("Judy",1);
    Ptr p2("Alvin",2);

    cout << p1.getP() << endl;
    cout << p2.getP() << endl;

    p1 = p2;  //synthesized copy assignment is defined as memberwise assign, and it didnot free the allocated memory of p1. 
              // const int member make the copy assignment deleted;
    cout << p1.getP() << endl;
    cout << p2.getP() << endl;

}