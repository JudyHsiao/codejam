#include <string>
#include <iostream>
using namespace std;

class HasPtr {
public:
    HasPtr(const std::string &s = std::string()):
    ps(new std::string(s)), i (0) {}
    HasPtr(const HasPtr& p);
    HasPtr& operator=(const HasPtr&);
    std::string* getPs() {return ps;};
    void setPs(const std::string& s) {*ps = s;};
    ~HasPtr() {delete ps;};
private:
    std::string *ps;
    int i;
};
HasPtr::HasPtr(const HasPtr& p): ps(new string(*(p.ps))), i(p.i){};
HasPtr& HasPtr::operator=(const HasPtr& b){
    *ps = *(b.ps);  //copy value
    i = b.i; 
    return *this;
};


int main() {
    HasPtr h1("Hi, Judy");
    HasPtr h2(h1);
    h1.setPs("Hi, Alvin");


    cout << *h2.getPs() << endl;
    cout << *h1.getPs() << endl;

    h2 = h1;

    h1.setPs("Hi, Jane");
    cout << *h2.getPs() << endl;
    cout << *h1.getPs() << endl;

    return 0;
}
