#include <iostream>
using namespace std;

class Solution {
public:
    //map<tuple<int,int,int>, double>  memo;
    
    double memo [30][30][105] ;
    bool inside(int r, int c ,int N) {
        if (r>=0 && c>=0 && r< N && c<N)
            return true;
        
        return false;  
    }
    
    double dfs (const int N, int k, int r, int c) {
        
        if (!inside(r,c,N)) {
            return 0;
        }
        
        if (k==0) {
            return 1;
        }
        
        if(memo[r][c][k] != 0) 
            return memo[r][c][k];
        
        const pair<int,int> dirs[8] = {{1,2}, {2,1}, {2,-1}, {1,-2}, {-1,-2}, {-2,-1}, {-2,1}, {-1,2}};
        
        double p = 0;
        for (const auto& d:dirs) {
            int x = r+ d.first;
            int y = c+ d.second;
            p += dfs (N, k-1, x, y);
        }
        memo[r][c][k] = p/8;
        return memo[r][c][k]; 
    }
    
    double knightProbability(int N, int K, int r, int c) {
        //memset(memo, -1, sizeof(memo));
        cout << memo [10][10][5] << endl;
        return dfs(N, K, r, c);
    }
};


int main (){
    Solution s;
    
    double p = s.knightProbability(3,2,0,0);
    cout << p << endl;
}