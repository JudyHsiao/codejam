#include <iostream>
using namespace std;

class numbered {
public:
    numbered():mysn(++sn){}
    numbered(const numbered& n):mysn(++sn){}
    int mysn;
private:
    static int sn;
};

int numbered::sn = 0;

void f(numbered s) {
    cout << s.mysn << endl;
}

int main() {
    numbered a, b=a, c=b;
    f(a);
    f(b);
    f(c);
    numbered d;
    f(d);
    return 0;
}