#include <vector>
#include <cstdio>

using namespace std;

class Solution {
public:
    void dfs(const vector<vector<int>>& grid, int i, int j, vector<vector<bool>>& visited, int& ans, int cnt) {
        printf("%d %d :%d\n", i , j , grid[i][j]);
        if (grid[i][j] == 2 && cnt ==0){
            ans++;
            return;
        }
        
        int m = grid.size();
        int n = grid[0].size();
        
        const pair<int,int> dirs[4] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        for (const auto &d:dirs) {
            int x = i + d.first;
            int y = j + d.second;
            if (x>=0 && y>=0 && x<m && y<n && grid[x][y] != -1 && visited[x][y] == false) {
                visited[x][y] = true;
                dfs(grid, x, y, visited, ans,  cnt-1);
                visited[x][y] = false;
            }
        }
    }
    
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        int cnt = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j<n; j++) {
                if (grid[i][j] == 0) {
                  cnt++;
                }
            }
        }
        
        
        int i = 0; 
        int j = 0;
        bool found = false;
        for (i = 0; i < m; i++) {
            for (j = 0; j<n; j++) {
                if (grid[i][j] == 1) {
                    found = true;
                    break;
                }
            }
            if (found == true)
                break;
        }
        printf("%d %d %d\n", i, j, cnt+1);
        
        visited[i][j] = true;
        
        int ans = 0;
        dfs(grid, i, j, visited, ans, cnt+1);
        
        return ans;
        
        
        
    }
};

int main() {
    Solution s;
    vector<vector<int>>v ({{0,0,0,0,0,0,2,0,0,0},{0,0,0,0,0,0,0,0,1,0}});
    s.uniquePathsIII(v);

}