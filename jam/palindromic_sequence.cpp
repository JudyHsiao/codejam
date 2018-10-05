#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <math>

using namespace std;
string ans;
map<string, int> f_cache;
map<string, int> g_cache;
int L;
int K;
int N;

int g(string s) {
    if (g_cache.count(s)) {
        return g_cache[s];
    }

    int r = 0;
    int l = s.length();
    // s ="abc"
    // x =3 , 4, , 5 => abc XXX abc
    // y =3, 2, 1 
    for (int x = l; x<2*l; x++) {
        int y = 2*l-x;
        if (x<=N && isPal(s.substr(l-y,y)))
            r+=1;
    }

    for(int x = 2*l; x<= N; x++) {
        r+= pow(L,((x - 2*l + 1) / 2));
    }

    g_cache[s] = r
    cout << "g:" <<s << " => " << r<<endl; 
    return r
} 

int f(string s) {
    if (f_cache.count(s)) {
        return f_cache[s];
    }
    int r = g(s);
    for(int i = 0; i < s.length();i ++) {
        char c =s[i];
        for(char ch = 'a'; ch < 'a' + L; ch++) {
            string p = s.substr(0, i) + ch;
            if (ch >=c) {
                if (isPal(p))
                    r+=1;
            } else{
                r+= g(p);
            }
        }
    }

    // r -= 1 if p == p[::-1] else 0
    cout << "f:" <<s << " => " << r<<endl;  
    f_cache[s] = r
    return r;
}

int main(){
    int T;
    int kase = 1;




    cin >> T;

    while(T--) {
        cin >> L >> N >> K;
        ans = "";
        while (ans.length() < N) {
            for (char ch = 'a'; ch < 'a'+L ; ch++) {
                if (f(ans + ch) >=K) {
                    ans+=c;
                    break;
                }

            }
        }

        


        printf("Case #%d: %ld",kase++, ans);
    }
}