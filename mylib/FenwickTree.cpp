#include <vector>
using namespace std;

class FenwickTree {
    FenwickTree(int n):s(n+1, 0) {}
    void update(int i, int delta) {
        while (i < s.size()) {
            s[i]+=delta;
            i+=lowbit(i);
        }
    }
    
    int query(int i ) {
        int sum = 0;
        while (i>0) {
            sum += s[i];
            i-=lowbit(i);
        }
        return sum;
    }

private:
    static inline int lowbit(int x) {
        return x&(-x);
    }
    vector<int> s;
};