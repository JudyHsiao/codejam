#include <vector>
#include <map>
using namespace std;


struct Comp {
  bool operator() (const pair<int,int>& lhs, const pair<int,int>& rhs) const
  {return lhs.first < rhs.first;}
};
void init (vector<int>& A, vector<vector<int>>& G ) {
    int n = A.size();
    map<int,int> q;

    for (int i = n-2; i >=0 ; i--) {
        q[A[i+1]] = i+1;
        auto it = q.lower_bound(A[i]);
        if (it != q.end())
            G[i][0] = it->second;
        auto it2 = q.upper_bound(A[i]);
        if (it2 != q.begin())
            G[i][1] = prev(it2)->second;
    }
    
    for (int i = 0; i < n; i++)
        printf("[%d, %d, %d]\n", i, G[i][0], G[i][1]);
}

int oddEvenJumps(vector<int>& A) {
    int n = A.size();
    vector<vector<int>> G(n, vector<int>(2, -1));
    
    init(A, G);
    
    
    vector<vector<bool>> dp(n, vector<bool>(2, false));
    dp[n-1][0] = true;
    dp[n-1][1] = true;
    
    for (int i = n-2; i>= 0; i--) {
        int j = G[i][0];
        if (j!= -1 && dp[j][1] == true)
            dp[i][0] = true;
        
        j = G[i][1];
        if (j != -1 && dp[j][0] == true)
            dp[i][1] = true;
    }
    
    int ans = 0;
    for (int i = 0; i< n; i++) {
        printf("dp[%d, %s, %s]\n",i, dp[i][0]?"true" : "false",dp[i][1]?"true" : "false");
        if (dp[i][0] == true)   
            ans++;
    }
    
    return ans;
    
    
}

int main() {

    vector<int> A({2,3,1,1,4});
    oddEvenJumps(A);

}