#include <cstdio>
//ax + by =

void gcd(int a, int b, int &d, int &x, int &y) {
    if(!b) { d = a ; x = 1; y = 0 ;}
    else {
        gcd(b, a%b, d, y, x) ;
        y-= x*(a/b);
    }
}

//滿足 6x+15y = d , d = gcd(6, 15) 的一組整數解
//6x + 15y = 3 , x= -2 , y =1
int main() {
    int x, y ,d;
    gcd(6, 15, d, x, y);
    printf("%d %d %d\n", x, y, d);
}