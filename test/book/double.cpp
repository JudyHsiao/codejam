#include <iostream>

using namespace std;

int main() {
    if(0.1 + 0.1*2 ==0.3)
        cout << "1\n";

    double p = 0.1;
    if (p+p*2 == 0.3)
        cout <<"2\n";

    if (1/0.1 == 10)
        cout <<"3\n";

    if (1*0.1 == 0.1)
        cout <<"4\n";
}