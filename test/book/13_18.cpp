#include <iostream>
#include <string>
using namespace std;
class Employ {
public:
    Employ(const string &s):name(s),id(++cnt){};
    string name;
    int id;
private:
    static int cnt;
};

int Employ::cnt = 0;

int main() {
    Employ a ("Judy"); 
    cout << "Name:"<< a.name << " Id:"<<a.id << endl;
    Employ b(a);
    cout << "Name:"<< b.name << " Id:"<<b.id << endl;

}