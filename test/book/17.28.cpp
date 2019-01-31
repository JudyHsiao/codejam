#include <iostream>
#include <random>

using namespace std;
int gen() {
    static default_random_engine e(time(0));
    static uniform_int_distribution<int> u;

    return u(e);
}

int main () {
    int y = gen();
    printf("%d\n", y);

    return 0;
}