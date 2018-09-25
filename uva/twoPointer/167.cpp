#include <vector>
using namespace std;

/*
[2,7,11,15], target = 9
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0;
        int j = numbers.size()-1;

        while (i < j) {
            if (numbers[i] + numbers[j] < target) {
                i+=1;
            } else if (numbers[i] + numbers[j] > target) {
                j-=1;
            } else {
                return vector<int>{i+1,j+1};
            }
        }
        
    }
};