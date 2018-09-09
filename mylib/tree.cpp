#include <cstdio>
#include<cstdlib>

#include<cstring>
#include <vector>
#include<queue>
using namespace std;

const int maxn = 256 + 10;

struct Node {
    Node* left;
    Node* right;
    int v;
    bool have_value;
    Node():have_value(false),left(NULL),right(NULL){}
};


Node* root;
queue<Node*> freenodes;

Node node[maxn];
bool failed;

Node* newnode() {
    Node* u= freenodes.front();
    u->left = u->right = NULL;
    u->have_value=false;
    freenodes.pop();
    return u;
}

void deletenode(Node* u) {
  freenodes.push(u);
}


void remove_tree(Node* u) {
    if (u == NULL)
        return;
    remove_tree(u->left);
    remove_tree(u->right);
    deletenode(u);
}


void init() {
  for(int i = 0; i < maxn; i++)
    freenodes.push(&node[i]);
}

int main(){

    init();
    
    remove_tree(root);
    root = newnode();
    return 0;
}
