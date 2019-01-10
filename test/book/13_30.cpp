#include <string>
#include <iostream>
using namespace std;

class HasPtr {
friend void swap(HasPtr &lhs, HasPtr& rhs);
public:
        HasPtr():ps(nullptr), i(0){};
        HasPtr(const string& s, int v):ps(new string(s)), i(v){};
        HasPtr(const HasPtr& rhs):ps (new string(*rhs.ps)), i(rhs.i){};
        HasPtr& operator=(HasPtr rhs);
        ~HasPtr(){delete ps;};
        const string& getPs() { return *ps;}

private:
        string *ps;
        int i;      
};

void swap(HasPtr &lhs, HasPtr& rhs) {
    swap(lhs.ps, rhs.ps);
    swap(lhs.i, rhs.i);
    cout<< "in friend" << endl;
    
}

HasPtr& HasPtr::operator=(HasPtr rhs) 
{
    swap(*this, rhs);
    return (*this);
}

int main() {
    HasPtr h1 ("Judy",0);
    HasPtr h2("Alvin", 1);

    swap(h1, h2);
    cout << h1.getPs() << endl;
    cout << h2.getPs() << endl;

    h1 = h2;
    cout << h1.getPs() << endl;
    cout << h2.getPs() << endl;

    return 0;
}
