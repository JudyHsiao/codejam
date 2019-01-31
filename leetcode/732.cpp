#include <memory>
#include <algorithm>
using namespace std;

class MyCalendarThree {
public:
    MyCalendarThree():max_count(0),root( new Node(0, 100000000, 0)) {}
    int book (int start, int end) {
        Add(start, end, root);
        return max_count;
    }
    ~MyCalendarThree(){
        delete root;
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
            printf("l:%d r:%d m:%d, count:%d\n", l,r,m,count);
            if (left)
                delete left;
            if (right)
                delete right;
        }
    };

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