#include<iostream>
#include<algorithm>

using namespace std;


long long sum (int a, int d, int n) {
    return (long long)(2*a-n*d)*(n+1)/2;

}

int main() {
    int n , k;

    while (cin >> n >> k) {
        int i = 1;
        long long ans = 0;
        while (i <= n) {
            int q = k %i;
            int p = k/i;

            int cnt = n -i;
            if (p >0) {
                cnt = min(q/p, cnt);
            }
            ans += sum(q, p, cnt);
            i += cnt + 1;
        }
        cout << ans << "\n";
    }
    return 0;
}