#include<cstdio>
#include<iostream>

using namespace std;
int main() {
   double dval = 3.14;
   const double *ri = &dval;
   dval = 4.2;
   cout << *ri << endl;
}