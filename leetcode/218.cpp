#include <vecotr>
#include <iostream>

using namespace std;

class SGT {
public: 
    SGT():{
        root = newNode(0, LONG_LONG_MAX, 0);
    };
    
    void update(int x1, int x2,int h){
        update(root, x1,  x2, h);
    }
    
    void skyline(vector<pair<int, int>>& ans) {
        dfs(root, ans);
    }

    Node* newNode(int left,int right,int height){
        data.emplace_back(left, right, height);
        return &data.back() 
    }
    
private:
    struct Node {
        long long l;
        long long r;
        int m = -1;
        int h;
        Node *left = nullptr;
        Node *right = nullptr;
        Node(int left,int right,int height):l(left),r(right),h(height){}
        
    };
    void update(Node* r, int x1, int x2, int h){
        if (r->m != -1) {
            if (x2 <= r->m) {
                update(r->left, x1, x2, h);
            }else if (x1>=r->m) {
                update(r->right, x1, x2, h);
            } else {
                update(r->left, x1, r->m, h);
                update(r->right,r->m, x2, h);
            }
            return ;
        }
        
        if (r->l == x1 && r->r == x2) {
            r->h = max(r->h, h);
        }else if (r->l == x1) {
            r->m = x2;
            r->left = new Node(r->l, r->m, max(h, r->h));
            r->right = new Node( r->m,r->r,  r->h);    
        }else if (r->r == x2) {
            r->m = x1;
            r->left = new Node(r->l, r->m, r->h);
            r->right = new Node( r->m,r->r,  max(h, r->h));
        }else {
            r->m = x1;
            r->left = new Node(r->l, r->m, r->h);
            r->right = new Node( r->m,r->r, r->h);
            update(r->right, x1, x2, h);
        }
    }
    
    void dfs(Node* r, vector<pair<int, int>>& ans) {
        if (r->m != -1) {
            dfs(r->left, ans);
            dfs(r->right,ans);
            return;
        }
        
        if (ans.empty() || r->h != ans.back().second) {
            if (r->l == 0 &&  r->h ==0)
                return;
            ans.push_back({r->l, r->h});
        }
        
    }
    
    Node * root;
    vector<Node> data;
};

class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        SGT sgt;
        for(const auto &b:buildings) {
            sgt.update(b[0], b[1], b[2]);
        }
        vector<pair<int, int>> ans;
        sgt.skyline(ans);
        
        return ans;
    }
};