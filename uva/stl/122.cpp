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

void addnode(int v, char *s){
    int n = strlen(s);
    Node* u =root;
    for(int i = 0; i < n; i++) {
        if(s[i] == 'L'){
            if (u->left == NULL)
                u->left = newnode();
            u= u->left;
        } else if(s[i] == 'R'){
            if (u->right == NULL)
                u->right = newnode();
            u= u->right;      
        }
    }
    if (u->have_value)
        failed = true;
    u->v = v;
    u->have_value = true;
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

char s[maxn];
bool read_input() {
    failed = false;
    remove_tree(root);
    root = newnode();
    for(;;){
        if(scanf("%s", s)!=1)
            return false;
        if(!strcmp(s, "()")) break;
        int v;
        sscanf(&s[1],"%d", &v);
        addnode(v, strchr(s,',')+1);
    }
    return true;
}

void init() {
  for(int i = 0; i < maxn; i++)
    freenodes.push(&node[i]);
}
bool bfs(vector<int>& ans){
    queue< Node*> q;
    ans.clear();
    q.push(root);
    while(!q.empty()){
        Node* u = q.front();
        q.pop();
        if(!u->have_value)
            return false;
        ans.push_back(u->v);
        if (u->left !=NULL) {
            q.push(u->left);
        }
        if (u->right!=NULL){
            q.push(u->right);
        }
    }
    return true;
}

int main(){
    vector<int> ans;
    init();
    while(read_input()){
        if(!bfs(ans)){
            failed = true;
        }
        if(failed) {
            printf("not complete\n");
        }else{
            for(int i =0; i < ans.size(); i++) {
                if ( i!=0) 
                    printf(" ");
                printf("%d", ans[i]);
            }
            printf("\n");
        }

    }
    return 0;
}
