#include <cstdio>
#include <cstring>

using namespace std;
int main(){

    char A[] = {'a','b','c','d','e','f',0 };
    strncpy(A, A+1, 5);
    printf("%s\n",A);
}