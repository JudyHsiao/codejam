#include <string>
#include <iostream>
#include <vector>

using namespace std;

class TreeNode {
public:
    TreeNode(const std::string& s, int c):value(s), count(c){};
    TreeNode(const TreeNode& n);
    TreeNode& operator=(const TreeNode& n);
    ~TreeNode();
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;

private:
    std::string value;
    int count = 0;
    
};

TreeNode::TreeNode(const TreeNode& n):value(n.value), count(n.count),left(nullptr), right(nullptr){
    if (n.left)
        left = new TreeNode(*n.left);
    if (n.right)
        right = new TreeNode(*n.right);
};

TreeNode &TreeNode::operator=(const TreeNode &n) {
    value = n.value;
    count = n.count;

    TreeNode *tmp = nullptr;
    if (n.left)
        tmp = new TreeNode(*n.left);
    delete left;
    left = tmp;

    tmp = nullptr;
    if (n.right)
        tmp = new TreeNode(*n.right);
    delete right;
    right = tmp;

    return *this;
}
TreeNode::~TreeNode() {
    cout << "~TreeNode()" << endl;
    delete left;
    delete right;
}

class BinStrTree {
public:
    BinStrTree():root(nullptr){};
    BinStrTree(const TreeNode& r):root(nullptr){
            root = new TreeNode (r);
    };
    BinStrTree(const BinStrTree& t):root(nullptr){
        if (t.root)
            root = new TreeNode (*t.root);
    };
    BinStrTree& operator=(const BinStrTree& rhs){
        TreeNode *tmp = nullptr;
         if (rhs.root)
            tmp = new TreeNode (*rhs.root);
        delete root;
        root = tmp;
        return *this;
    };

    ~BinStrTree(){ delete root; };

private:
    TreeNode *root;
};



int main() {
    TreeNode n1("hello", 1);
    n1.left = new TreeNode ("hello2", 2);
    n1.right = new TreeNode ("hello2", 3);

    TreeNode n2(n1);

    BinStrTree t(n1);

    return 0;

}