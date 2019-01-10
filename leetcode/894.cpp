#include <map>
#include <vector>
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

map<int, vector<TreeNode*>> ans;
    
vector<TreeNode*>& allPossibleFBT(int N) {
    if (ans.count(N)) {
        return ans[N];
    }
    
    if (N %2 == 0) {
        ans[N] = {};
        return ans[N];
    }
    if (N==1) {
        ans[N] = {new TreeNode(0)};
        return ans[N];
    }
    
    for (int x = 1; x <N-1; x++) {
        int y = N -1 -x;
        const auto &L = allPossibleFBT(x);
        const auto &R = allPossibleFBT(y);
        
        for (const auto& l: L) {
            for (const auto& r:R) {
                TreeNode* root = new TreeNode(0);
                root->left = l;
                root->right = r;
                ans[N].push_back(root);
            }
        }
    }
    
    return ans[N];
}