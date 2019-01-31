
#include <vector>
using namespace std;


class SGT {
public:
    SGT():root(new Node(0, 1000000000, 0)){}
    ~SGT() {
        delete root;
    }
    int update(int x1, int x2, int v) {
        update(root, x1, x2, v);
        return maxHeight;
    }

    int query(int x1, int x2) {
        return query(root, x1, x2);
    }
    
private:
    struct Node {
        int l;
        int r;
        int m = -1;
        Node* left = nullptr;
        Node* right = nullptr;
        int h = 0;
        Node(int left, int right, int height):l(left), r(right), h(height){};
        ~Node() {
            if (left)
                delete left;
            if (right)
                delete right;
        }
    };
    int query(Node* r, int x1, int x2) {
        if (r->m != -1) {
            if (x2 <= r->m){
                return query(r->left, x1, x2);
            }else if (x1 >= r->m) {
                return query(r->right, x1, x2);
            } else {
                return max(query(r->left, x1, r->m), query(r->right, r->m, x2));
            }
        }

        return r->h;

    }

    void  update(Node* r, int x1, int x2, int v) {  //set height to v
        if (r->m != -1) {
            if (x2 <= r->m) {
                update(r->left, x1, x2, v);
            }else if (x1>=r->m) {
                update(r->right, x1, x2, v);
            } else {
                update(r->left, x1, r->m, v);
                update(r->right, r->m, x2, v);
            }
            return ;
        }

        if (x1 == r->l && x2 == r->r) {
            r->h = v;
            maxHeight = max(r->h, maxHeight);
        }else if (x1 == r->l) {
            r->m = x2;
            maxHeight = max(maxHeight, v);
            r->left = new Node(r->l, r->m, v);
            r->right = new Node(r->m, r->r, r->h);
        } else if (x2==r->r) {
            r->m = x1;
            r->left = new Node(r->l, r->m, r->h);
            r->right = new Node(r->m, r->r, v);
            maxHeight = max(maxHeight, v);
        } else {
            r->m = x1;
            r->left = new Node(r->l, r->m, r->h);
            r->right = new Node(r->m, r->r, r->h);
            update(r->right, x1, x2, v);
        }
    }

    Node* root = nullptr;
    int maxHeight = 0;
};

vector<int> fallingSquares(vector<pair<int, int>>& positions) {
    SGT sgt;
    vector<int> ans;
    for (const auto& p: positions) {
        int h = sgt.query(p.first, p.first+p.second);
        int h2 = sgt.update(p.first, p.first+p.second, h+p.second);
        ans.push_back(h2);
    }
    return ans;  
}

int main() {

}