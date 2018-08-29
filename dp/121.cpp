#include <vector>
using namespace std;
/*
Input: [7,1,5,3,6,4]
Output: 5
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int bestProfit = 0;

        for (int i =0 ; i < prices.size(); i++) {
            if (prices[i] < minPrice) {
                minPrice = prices[i];
            }

            if (prices[i] - minPrice > bestProfit ) {
                bestProfit = prices[i] - minPrice;
            }
        }

        return bestProfit; 
    }
};