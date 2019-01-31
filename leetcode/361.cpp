#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    
    void initH (vector<vector<int>>& H, const vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        for (int i = 0; i< m; i++) {
            if (grid[i][0] == 'E')
                H[i][0] =1; 
            for (int j= 1; j<n; j++) {
                H[i][j] = H[i][j-1];
                if (grid[i][j] == 'E') {
                    H[i][j]+=1;
                }else if (grid[i][j] == 'W'){
                     H[i][j]=0;
                }
            }
        }
        
        for (int i = 0; i< m; i++) { 
            for (int j= n-2; j>=0; j--) {
                H[i][j] = max(H[i][j-1], H[i][j]);
                if (grid[i][j] == 'W') {
                     H[i][j]=0;
                }
            }
        }
    }
                    
    void initV (vector<vector<int>>& V, const vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        for (int j= 0; j<n; j++) {
            if (grid[0][j] == 'E')
                V[0][j] =1; 
            for (int i = 1; i< m; i++) {
                V[i][j] = V[i-1][j];
                if (grid[i][j] == 'E') {
                    V[i][j]+=1;
                }else if (grid[i][j] == 'W') {
                     V[i][j]=0;
                }
            }
        }
        
        for (int j= 0; j<n; j++) {
            for (int i = m-2; i>= 0; i--) {
                V[i][j] = max(V[i][j], V[i+1][j]);
                if (grid[i][j] == 'W') {
                     V[i][j]=0;
                }
            }
        }
    }
                    
    int maxKilledEnemies(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> H(m, vector<int>(n, 0));
        vector<vector<int>> V(m, vector<int>(n, 0));
        
        initH(H, grid);
        initV(V, grid);
        
        int best =0;
        for (int i = 0; i < m ; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '0') {
                    best =max(best, H[i][j]+ V[i][j]);
                }
            }
        }
        
        return best;
        
        
    }
};