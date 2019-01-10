#include <iostream>


using namespace std;

void process(const shared_ptr<int> p) {
    cout << *p <<endl;
} 
int main() {
    shared_ptr<int> p(new int(41));
    process(shared_ptr<int>(p);
}