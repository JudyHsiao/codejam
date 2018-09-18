#include <cstdio>
#include <deque>
#include <queue>
#include <string>
#include <iostream>
#include <unordered_set>

using namespace std;

int line[8][7] = {
  { 0, 2, 6,11,15,20,22}, // A
  { 1, 3, 8,12,17,21,23}, // B
  {10, 9, 8, 7, 6, 5, 4}, // C
  {19,18,17,16,15,14,13}, // D
};

struct Node {
    int A[24];
    string path;
    Node():path(""){}

    bool operator < (const Node& rhs) const{
       if (path.length() == rhs.path.length()) {
           return path > rhs.path;
       }
       return path.length() > rhs.path.length();
    }

    bool operator == (const Node& rhs) const{
        for (int i = 0; i < 24 ; i++) {
            if (A[i]!= rhs.A[i])
                return false;
        }
        
        return true;
    }

    void move(int i) {
        int tmp = A[line[i][0]];
        for(int j = 0; j < 6; j++) 
            A[line[i][j]] = A[line[i][j+1]];
        A[line[i][6]] = tmp;

        path += char('A'+ i);
    }
};


template<> struct hash<Node>
{
    size_t operator()(const Node& a) const
    {
        string s = "";
        for (int i = 0; i < 24 ; i++) {
            s+=a.A[i];
        }
        return std::hash<std::string>()(s);
    }
};



const int rev[8] = {5, 4, 7, 6, 1, 0, 3, 2}; // reverse lines of each line
const int center[8] = {6, 7, 8, 11, 12, 15, 16, 17};

bool done(Node n) {
    for (int i =0; i < 8; i++) {
        if (n.A[center[i]] == 0)
            return false;
    }
    return true;
}

void print(Node n) {
    cout << n.path << endl;
    for (int i =0; i < 24; i++)
        printf("%d ", n.A[i]);
    printf("\n");
}

Node bfs(int *a) {
    priority_queue <Node> q;
    unordered_set<Node> h;
    
    for (int k = 1; k <= 3 ; k++) {
        Node s;
        for (int i = 0; i < 24; i++) {
            if (a[i] == k) {
                s.A[i] = k;
            } else {
                s.A[i] = 0;
            }
        }
        h.insert(s);
        q.push(s);
    }

    while(!q.empty()) {
        Node n =  q.top();
        q.pop();
        //print(n);
        if (done(n))
            return n; 

        for (int i = 0; i <8; i++) {
            Node v;
            memcpy(&v, &n, sizeof(n));
            v.move(i);

            if (h.find(v) == h.end()) {
                h.insert(v);
                q.push(v);
            }
        }
    }
}

int main() {
    int a[24];
    int d ;
    int i = 0;

    while(scanf("%d", &d) == 1 && d) {
        a[i] = d;
        i++;
        if (i == 24) {
            Node n = bfs(a);
            if (n.path.length()== 0) {
                printf("No moves needed\n");
            } else {
                cout << n.path << endl;
            }
            printf("%d\n", n.A[center[0]]);
            i = 0; 
        }
    }

    return 0;
}