#include <iostream>
#include <set>
#include <queue>
using namespace std;
struct Node {
    int v;
    int i;
    int j;
    Node(int x, int y, int value):i(x),j(y),v(value){}
};

int main() {

    auto f = [](const Node& l, const Node& r) {return l.v> r.v;};       
    priority_queue<Node, vector<Node>, decltype(f)> pq(f);

    set<Node,decltype(f)>s(s);

}