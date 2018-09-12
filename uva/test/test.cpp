#include <iostream>

using namespace std;

struct Node{
    int a;
    int b;
    Node(int a, int b):a(a),b(b){};
};

Node foo() {
    Node n = Node(5,8);
    return n;
}
int main(){
    int a = 7/2 ;
    cout << a << endl;

    Node n =  foo();
    cout << n.a << " " << n.b << endl;
}