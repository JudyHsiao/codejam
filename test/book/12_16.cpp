#include <memory>
using namespace std;

int main(){
    unique_ptr<int> p (new int(12));
    unique_ptr<int> q;
    q = p;
}