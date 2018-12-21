#include <cstdio>
#include <string>
#include <map>

using namespace std;

int main() {
    int a, b;
    while(scanf("%d%d", &a, &b) == 2) {
        printf("%d/%d = ", a, b);
        map<int,int> h;
        string ans;
        ans += to_string(a/b);
        ans += ".";
        a = a%b;
        a = a*10;
        int len = 0;
        while (true) {
            if (h.count(a) == 0 ) {
                ans+= to_string(a/b);
                h.insert({a, ans.length()});
                a = (a % b) * 10;
            } else {
                len = ans.length() - h[a]+1;
                if (ans.substr(ans.find(".")).length()>50) {
                    ans = ans.substr(0, h[a]-1) + "(" + ans.substr(h[a]-1, ans.find(".") + 50 -h[a]+2) + "...)\n";
                } else{
                    ans = ans.substr(0, h[a]-1) + "(" + ans.substr(h[a]-1) + ")\n";
                }
                break;
            } 
        }
        printf("%s", ans.c_str());
        printf("  %d = number of digits in repeating cycle\n", len);
    }
}