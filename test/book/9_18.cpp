#include<deque>
#include <iostream>
using namespace std;
int main() {
    string tmp;
    deque<string> q;

    while (cin >> tmp) {
        q.push_back(tmp);
    }

    string t = q.front();
    t = "he";
    for (auto &s:q) {
        cout << s << endl;
    }
    return 0;
}