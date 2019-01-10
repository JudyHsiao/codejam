#include <string>
#include <iostream>
#include <vector>
using namespace std;

class HasPtr {
friend void swap(HasPtr &lhs, HasPtr& rhs);
public:
        HasPtr():ps(nullptr), i(0){};
        HasPtr(const string& s, int v):ps(new string(s)), i(v){};
        HasPtr(const HasPtr& rhs):ps (new string(*rhs.ps)), i(rhs.i){};
        HasPtr& operator=(HasPtr rhs);
        bool operator<(const HasPtr& rhs) const;
        ~HasPtr(){delete ps;};
        const string& getPs() const { return *ps;} ;

private:
        string *ps;
        int i;      
};

void swap(HasPtr &lhs, HasPtr& rhs) {
    swap(lhs.ps, rhs.ps);
    swap(lhs.i, rhs.i);
    cout<< "in my swap" << endl;
    
}

bool HasPtr::operator<(const HasPtr& rhs)const{
    return i < rhs.i;
}

HasPtr& HasPtr::operator=(HasPtr rhs) 
{
    swap(*this, rhs);
    return (*this);
}

int main() {
    vector<HasPtr> v;
    for(size_t i = 10; i != 0; i-- ) {
        v.push_back(HasPtr(to_string(i),i));
    }
    sort(v.begin(), v.end());

    for(const auto & u :v)
        cout<< u.getPs() << endl;
    return 0;
}
