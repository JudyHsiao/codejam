#include <vector>
using namespace std;

/*
Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int s = 0;
        int ans = -INT_MAX;
        for (int i =0 ; i< nums.size();i++){
            s += nums[i];

            if (s > ans) {
                ans = s;
            }
            
            if (s < 0) {
                s = 0;
            }
        }
        return ans;
    }
};