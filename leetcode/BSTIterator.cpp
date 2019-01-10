#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int n): val(n),left(nullptr), right(nullptr){};
};

class BSTIterator {
public:
    BSTIterator(TreeNode* root, bool r=false):node(root),reverse(r){};
    bool hasNext() {
        return node != nullptr || !s.empty();
    };
    int next() {
        while(node || !s.empty()) {
            if (node) {
                s.push(node);
                node = reverse ? node->right : node->left;
            } else {
                node =  s.top();
                s.pop();
                int ret = node-> val;
                node = reverse ? node->left : node->right;
                return ret;
            }

        }
        return -1;
    }; 
private:
    stack<TreeNode*> s;
    TreeNode* node;
    bool reverse;
};