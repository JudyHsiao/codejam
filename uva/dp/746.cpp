#include <vector>
using namespace std;

class Solution {
public:

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size(); 
        int f[n+1];
        f[n] = 0;
        f[n-1] = 0;
        for (int i = n-2; i>=0; i--) {
            f[i] = min(cost[i]+f[i+1], cost[i+1]+f[i+2]);
        }
        return f[0];
    }
};