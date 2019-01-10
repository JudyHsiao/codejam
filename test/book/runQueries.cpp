#include <iostream>
#include <fstream>
#include "TextQuery.h"
#include "QueryResult.h"

using namespace std;

int main() {
    ifstream is ("./text.txt");
    TextQuery tq(is);
    string s;
    while (cin >> s) {
        auto r = tq.query(s);
        print(cout, r) << endl;
        for (auto &l: *(tq.file))
            cout << l << endl;
    }
    is.close();
    return 0;
}