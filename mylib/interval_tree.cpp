#include <memory>
#include <algorithm>
#include <climits>
#include <iostream>
using namespace std;

class SGT {
public:
    SGT():max_count(0),root( new Node(0, 100000000, 0)) {}
    int update (int start, int end) {   // [start, end) +1
        Add(start, end, root);
        return max_count;
    }
    ~SGT(){
        delete root;
    }

    int Kthlargest (int k ) {
        int ans = INT_MIN;
        int cur = 0;
        kthlarge(root, k, cur, ans);
        return ans;
    }

    int Kthsmallest (int k ) {
        int ans = INT_MAX;
        int cur = 0;
        kthsmall(root, k, cur, ans);
        return ans;
    }


private:
    struct Node {
        Node(int l, int r, int count):l(l),r(r),m(-1),count(count){}
        int l;
        int m;
        int r;
        int count;
        Node* left =nullptr;
        Node* right =nullptr;;
        ~Node() {
            if (left)
                delete left;
            if (right)
                delete right;
        }
    };



    void kthsmall(Node* root, int k, int &cur, int &ans) {

        if (ans != INT_MAX)
            return;
        
        if (root->left)
            kthsmall(root->left, k, cur , ans);
        
        if (root->m == -1 && root->count) {   // only leave contains data
            for (int i = root->l; i < root->r; i++) {
                cur += root->count;
                if (cur >= k) {
                    ans = i;
                    return;
                }

            }
        }

        if (root->right)
            kthsmall(root->right, k, cur, ans);
        
    }

     void kthlarge(Node* root, int k, int &cur,int& ans) {

        if (ans != INT_MIN)
            return;
        

        if (root->right)
            kthlarge(root->right, k, cur, ans);
        
        
        if (root->m == -1 && root->count) {   // only leave contains data
            for (int i = root->r-1; i >= root->l; i--) {
                cur += root->count;
                cout << cur << endl;
                if (cur >= k){
                    ans = i;
                    return;
                }
            }
        }

        if (root->left)
            kthlarge(root->left, k, cur, ans);    
    }

    void Add(int start, int end, Node* root) {
        if (root->m != -1) { 
            if (end <= root->m)
                Add(start, end, root->left);
            else if (start >= root->m) {
                Add(start, end, root->right);
            } else {
                Add(start, root->m, root->left);
                Add(root->m, end, root->right);
            }
             return;
        }

        if (root->left || root->right)
            assert("it's not leave");

        if (start == root->l && end == root-> r)
            max_count = max(max_count, ++root->count);
        else if (start == root->l) {
            root-> m = end;
            root->left = new Node(start, root->m, root->count +1);
            root->right = new Node(root->m, root->r, root->count);
            max_count = max(max_count, root->count + 1);
        }else if (end == root->r) {
            root->m = start;
            root->left = new Node(root->l, root->m, root->count);
            root->right = new Node(root->m, root->r, root->count+1);
            max_count = max(max_count, root->count + 1);
        } else {
            root->m = start;
            root->left = new Node(root->l, root->m, root->count);
            root->right= new Node(root->m, root->r, root->count);
            Add(start, end, root->right);
        }
    }
    int max_count;   
    Node* root;
};

int main() {
    SGT sgt;

    sgt.update(3,4+1);
	sgt.update(2,8+1);
	sgt.update(4,8+1);
	sgt.update(1,3+1);
	sgt.update(7,9+1);

    int i5 = sgt.Kthlargest(5);

	int i1 = sgt.Kthlargest(1);

	
    int i30 = sgt.Kthlargest(30);

    cout << "5th: " << i5 << " 1st:" << i1 << " 30th:" << i30 << endl;

}