#include <iostream>

using namespace std;

typedef long long LL;

LL gcd(LL a, LL b) {
  if(!b) return a;
  return gcd(b, a%b);
}

LL lcm(LL a, LL b) {
  return a / gcd(a, b) * b;
}

void print_chars(int cnt, char ch) {
  while(cnt--) cout << ch;
}

void output(LL a, LL b, LL c){
    if (b ==0)
        cout << a << "\n";
    else {
        int L1 = to_string(a).length();
        print_chars(L1+1, ' '); cout << b << "\n";
        cout << a << " "; print_chars(to_string(c).length(), '-'); cout << "\n";
        print_chars(L1+1, ' '); cout << c << "\n";
    }    
}
int main() {
    int n;
    while(cin >> n && n) {
        if (n==1) {
            output(1,0,0);
            continue;
        }

        LL x =1;
        for (int i = 2; i <= n-1; i++)
            x = lcm(x, i);

        LL c = x, b =0;
        for (int i = 2; i <= n-1; i++)
            b+= x/i;
        b*=n;
        LL g = gcd(b,c);
        b/=g; c/=g;

        LL a = 1+n + b/c;
        b%=c;
        output(a,b,c);
    }
    return 0;

}