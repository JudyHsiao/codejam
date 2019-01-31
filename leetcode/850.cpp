#include <vector>
#include <cstdio>

using namespace std;
class SGT {
public:
    SGT():root( new Node(0, 1000000005, 0)) {}
    void add (int start, int end) {   // [start, end) +1
        update(start, end, root, 1);
        return ;
    }

    void remove (int start, int end) {   // [start, end) +1
        update(start, end, root, -1);
        return ;
    }

    int active () {   // [start, end) +1
        int x = 0;
        dfs(root, x);
        return x;
    }


    ~SGT(){
        delete root;
    }


private:
    struct Node {
        Node(int l, int r, int count):l(l),r(r),m(-1),count(count){}
        int l;
        int m;
        int r;
        int count =0;
        Node* left =nullptr;
        Node* right =nullptr;;
        ~Node() {
            //printf("l:%d r:%d count:%d\n", l, r, count);
            if (left)
                delete left;
            if (right)
                delete right;
        }
    };

    void dfs(Node* root, int& ans) {
        //printf("l:%d r:%d count:%d\n", root->l, root->r, root->count);
        if (root->right)
            dfs(root->right,  ans);
            
        if (root->m == -1 && root->count) {   // only leave contains data
            ans += (root->r - root->l);
        }

        if (root->left)
            dfs(root->left,  ans);    
    }
    void update(int start, int end, Node* root, int val) {
        if (root->m != -1) { 
            if (end <= root->m)
                update(start, end, root->left, val);
            else if (start >= root->m) {
                update(start, end, root->right, val);
            } else {
                update(start, root->m, root->left, val);
                update(root->m, end, root->right, val);
            }
            return;
        }

        if (root->left || root->right)
            assert("it's not leave");

        if (start == root->l && end == root-> r){
            root->count+=val;
        } else if (start == root->l) {
            root-> m = end;
            root->left = new Node(start, root->m, root->count + val);
            root->right = new Node(root->m, root->r, root->count);
        } else if (end == root->r) {
            root->m = start;
            root->left = new Node(root->l, root->m, root->count);
            root->right = new Node(root->m, root->r, root->count+val);
        } else {
            root->m = start;
            root->left = new Node(root->l, root->m, root->count);
            root->right= new Node(root->m, root->r, root->count);
            update(start, end, root->right, val);
        }
    }
    Node* root;
};



struct Node {
    int l;
    int r;
    int y;
    int type;
    Node(int x1, int x2, int t, int yy):l(x1), r(x2),type(t), y(yy){}
    bool operator < (const Node& rhs) const {
        if (y == rhs.y) {
            if (type == rhs.type) {
                return l < rhs.l;
            }
            return type > rhs.type;
        } 
        return y < rhs.y;
    }
};


int rectangleArea(vector<vector<int>>& rectangles) {
    vector<Node> h;
    SGT sgt;
    for (const auto& r: rectangles){
        int x1 = r[0];
        int y1 = r[1];
        int x2 = r[2];
        int y2 = r[3];
        h.push_back(Node(x1, x2, 1, y1));
        h.push_back(Node(x1, x2, -1, y2));
    }
    sort(h.begin(), h.end());
    int i = 0;
    int area = 0;
    const int MOD = 1000000007;
    while(i <h.size()){
        while(i+1 < h.size() ) {
            //printf("%d, %d, %d, %d\n", h[i].y, h[i].type, h[i].l, h[i].r);
            if (h[i].type == 1) {
                sgt.add(h[i].l, h[i].r);
            } else {
                sgt.remove(h[i].l, h[i].r);
            }
            if (h[i].y  != h[i+1].y)
                break;
            i++;
        }
        if (i+1 < h.size()) {
            long long y = h[i+1].y - h[i].y ;
            long long x = sgt.active();
            area = ( area + ((y % MOD) * (x % MOD)%MOD)) %MOD;
        }
        i++;
    }
    return area;
 
}

int main() {
    vector<vector<int>> rectangles;
    rectangles= {{0,0,2,2},{1,0,2,3},{1,0,3,1}};
    int area = rectangleArea(rectangles);

    printf("%d\n",area);

    return 0;
}
