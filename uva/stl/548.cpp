#include <iostream>
#include <queue>
#include <iostream>
#include <sstream>
#include <vector>
#include <climits>

using namespace std;
struct Node {
    Node* left;
    Node* right;
    int value;
    Node():left(NULL),right(NULL){}
};

const int maxn = 10000 +5;
Node node[maxn];
queue<Node*> freenodes;
Node* root;

Node* newNode(){
    Node* v = freenodes.front();
    v->left = NULL;
    v->right = NULL;
    freenodes.pop();
    return v;
}

void deletenode(Node* u) {
  freenodes.push(u);
}

void init(){
    for (int i =0 ; i < maxn; i++){
        freenodes.push(&node[i]);
    }
}

void split(const string& s, char delim, vector<int>& result) {
    istringstream ss(s);
    string token;
    
    while(getline(ss, token, delim)) {
        result.push_back(stoi(token));
    }
    return;
}

void deletetree(Node* r){
    if (r == NULL) {
        return;
    }
    if (r->left != NULL) {
        deletetree(r->left);
    }
    if (r->right != NULL){
        deletetree(r->right);
    }
    deletenode(r);
}

Node* buildtree(vector<int>& inorder, int L1,int  R1, vector<int> & postorder, int L2, int R2){
    if (L1 > R1) 
        return NULL;
    
    Node* n = newNode();
    int r = postorder[R2];
    n->value = r;
    //printf("%d ",r);
    int p = L1;
    while(inorder[p]!=r) {
        p++;
    }  
    int cnt = p - L1; 
    n->left = buildtree(inorder, L1, p-1, postorder, L2, L2+cnt-1);
    n->right = buildtree(inorder, p+1, R1, postorder, L2+cnt, R2-1);
    return n;
}

void dfs(Node* n, int sum, int & min, int& ans){
    if (n == NULL)
        return;

    int s = sum + n->value;

    if (n->left == NULL  && n->right==NULL){
        if (s  < min) {
            min = s;
            ans = n->value;
        } else if (s == min &&  (n->value < ans)){
            ans = n->value;
        }
    }

    dfs(n->left, s, min, ans);
    dfs(n->right, s, min, ans);

}

int main(){
    init();
    string s;
    while (getline(cin, s)){
        vector<int>inorder;
        split(s, ' ', inorder); //inorder
        getline(cin, s);
        vector<int>postorder;
        split(s, ' ', postorder); //postorder

        deletetree(root);
        root = buildtree(inorder, 0, inorder.size()-1,  postorder, 0 , postorder.size()-1);
        int min = INT_MAX;
        int ans = INT_MAX;
        dfs(root, 0, min, ans);

        cout << ans<< "\n";
    }

    return 0;


}