#include <string>
#include <vector>
#include <iostream>
using namespace std;

class StrLen {
public:
    StrLen(size_t lo, size_t hi):low(lo),high(hi) {};
    bool operator()(const string& s) const {
        return s.size() >= low && s.size() <= high;
    }
private:
    size_t low;
    size_t high;
};

int main() {
    vector<string> s = {"a", "b", "c", "dd","eee","fadfasd"};
    
    int count = count_if(s.begin(), s.end(), StrLen(1,2));
    cout << count << endl;
     
    return 0;
}