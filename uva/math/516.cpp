#include<cstdio>
#include<cstring>
#include<iostream>
#include<sstream>
#include<vector>
#include<cmath>
using namespace std;

bool primes[32768];
void init_primes(){
    for (int i = 0; i < 32768; i++) {
        primes[i] = true;
    }
    for (int i = 2; i< 32768; i++) {
        if (primes[i]) {
            for (int j = i+i; j < 32768; j+=i) {
                primes[j] = false;
            }
        }
    }
}

int main() {
    init_primes();
    string line;
    while(getline(cin, line)) {
        stringstream ss(line);
        int x = 1;
        int p, e = 0;
        while (ss >> p) {
            if (p == 0)
                return 0;

            ss >> e;
            x= x* pow(p,e);
        }
        x -=1;
        vector<int> P;
        vector<int> E;
        for (int i = 2; i < 32768; i++) {
            if (i > x)
                break;
            if (primes[i] && x%i ==0) {
                int p = i;
                int e = 0;
                
                while (x > 1 && x%p ==0) {
                    x/=p;
                    e++;
                }
                P.push_back(p);
                E.push_back(e);
            }
        }
        for (int i = P.size()-1; i >=0; i--) {
            printf("%d", P[i]);
            if (i > 0)
                printf(" %d ", E[i]);
            else
                printf(" %d\n", E[i]);

        }
        
    }
    return 0;
}