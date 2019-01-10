#include <iostream>
using namespace std;
void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

void print(const char *cp) {
    while(cp && *cp)
        cout <<*cp++;
    cout << endl;
}

int main() {
    int a = 2, b=5;
    //swap(&a, &b);
    swap(a, b);
    cout << a << ":" << b << endl;

    char s2[] = {"hello"};
    print(s2);
    char* s = NULL;
    print(s);
}