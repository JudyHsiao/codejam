#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

    void dfs( bool[][] dp, const vector<int>& candidates, int target, int k, vector<int>& curr, vector<vector<int>>& ans) {
        if (target == 0) {
            ans.push_back(curr);
            return;
        }
        
        if (dp[k][target] == true) {
            if (target- candidates[k] >= 0 && dp[k][target- candidates[k]] == true) {
                curr.push_back(candidates[k]);
                dfs(dp, candidates, target- candidates[k], k-1, curr, ans );
                curr.pop_back();
            }
            dfs(dp, candidates, target, k-1, curr, ans );
        }
        
    }

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        bool dp[candidates.size()][target + 1];
        memset(dp, 0, sizeof(dp));
        sort(candidates.begin(), candidates.end());
        for(int i = 0; i <candidates.size(); i++) {
            dp[i][0] = true;
            if (candidates[i] <= target)
                dp[i][candidates[i]] = true;
        }
        
        
        for (int i=0;i <candidates.size(); i++) {
            for (int j = 1; j < target; j++) {
                if (i-1 > 0) {
                    if (j-candidates[i] >= 0) {
                        dp[i][j] = dp[i-1][j] || dp[i-1][j-candidates[i]];
                    } else {
                        dp[i][j] = dp[i-1][j];
                    }
                }
            }
        }
        
        vector<vector<int>> ans;
        vector<int> curr;
        dfs(dp, candidates, target, candidates.size()-1, curr, ans);
        
        return ans;