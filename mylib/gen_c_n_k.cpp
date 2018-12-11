#include <iostream>
#include <algorithm>
#include <vector>


const int maxn = 100;
long long c[maxn];
long long Combination(int n, int k){
    c[0] = 1;
    for (int i =1; i <=n; i++) {
        c[i] = c[i-1]*(n-i+1)/i;
    }
    return c[k];

}


int main() {
    int n, r;
    std::cin >> n;
    std::cin >> r;

    std::vector<bool> v(n);
    std::fill(v.end() - r, v.end(), true);

    do {
        for (int i = 0; i < n; ++i) {
            if (v[i]) {
                std::cout << (i + 1) << " ";
            }
        }
        std::cout << "\n";
    } while (std::next_permutation(v.begin(), v.end()));
    return 0;
}
