#include <cstdio>
#include <deque>
#include <queue>
#include <string>
#include <iostream>
#include <set>

using namespace std;
struct Node {
    int A[4][7];
    string path;
    Node():path(""){}

    bool operator < (const Node& rhs) const{
       if (path.length() == rhs.path.length()) {
           return path > rhs.path;
       }
       return path.length() > rhs.path.length();
    }

    bool operator == (const Node& rhs) const{
       for (int i = 0; i < 4 ; i++) {
            for (int j = 0; j <7; j++) {
                if (A[i][j] != rhs.A[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }
};

int Q[4][7];
bool done(Node n, int k) {

    for (int i = 0; i < 4 ; i++) {
        for (int j = 2; j <5; j++) {
            if (n.A[i][j] != k) {
                return false;
            }
        }
    }
    return true;
}

void print(Node n) {
    for (int i = 0; i < 4 ; i++) {
        for (int j = 0; j <7; j++) {
            printf("%d ",n.A[i][j]);
        }
        printf("\n");
    }
}

Node bfs(int k) {
    priority_queue <Node> q;
    Node start;
    set<Node> h;
    for(int i=0; i <4; i++) {
        for (int j = 0; j < 7; j++) {
            if (Q[i][j] == k) {
                start.A[i][j] = k;
            } else {
                start.A[i][j] = 0;
            }
        }
    }
    h.insert(start);
    q.push(start);
    while(!q.empty()) {
        Node n =  q.top();
        print(n);
        if (done(n, k))
            return n; 
        q.pop();
        for (int i = 0; i <8; i++) {
            Node v;
            if (i == 0 || i== 5) { 
                memcpy(v.A[1], n.A[1], 7);
                memcpy(v.A[2], n.A[2], 7);
                memcpy(v.A[3], n.A[3], 7);
                if (i == 0) {
                    memcpy(v.A[0], &n.A[0][1], 6);
                    v.A[0][6] = n.A[0][0];
                    v.A[2][2] = n.A[0][3];
                    v.A[3][2] = n.A[0][5];
                } else {
                    memcpy(&v.A[0][1], &n.A[0][0], 6);
                    v.A[0][0] = n.A[0][6];
                    v.A[2][2] = n.A[0][1];
                    v.A[3][2] = n.A[0][3];
                }
            } else if (i == 1 || i == 4) {
                memcpy(v.A[0], n.A[0], 7);
                memcpy(v.A[2], n.A[2], 7);
                memcpy(v.A[3], n.A[3], 7);
                if (i == 1) {
                    memcpy(v.A[1], &n.A[1][1], 6);
                    v.A[1][6] = n.A[1][0];
                    v.A[2][4] = n.A[1][3];
                    v.A[3][4] = n.A[1][5];
                } else {
                    memcpy(&v.A[1][1], &n.A[1][0], 6);
                    v.A[1][0] = n.A[1][6];
                    v.A[2][4] = n.A[1][1];
                    v.A[3][4] = n.A[1][3];
                }
            } else if (i == 2 || i== 7) {
                memcpy(v.A[0], n.A[0], 7);
                memcpy(v.A[1], n.A[1], 7);
                memcpy(v.A[3], n.A[3], 7);
                if (i == 7) {
                    memcpy(v.A[2], &n.A[2][1], 6);
                    v.A[2][6] = n.A[2][0];
                    v.A[0][2] = n.A[2][3];
                    v.A[1][2] = n.A[2][5];
                } else {
                    memcpy(&v.A[2][1], &n.A[2][0], 6);
                    v.A[2][0] = n.A[2][6];
                    v.A[0][2] = n.A[2][1];
                    v.A[1][2] = n.A[2][3];
                }
            } else {
                    memcpy(v.A[0], n.A[0], 7);
                    memcpy(v.A[1], n.A[1], 7);
                    memcpy(v.A[2], n.A[2], 7);
                    if (i == 6) {
                        memcpy(v.A[3], &n.A[3][1], 6);
                        v.A[3][6] = n.A[3][0];
                        v.A[0][4] = n.A[3][3];
                        v.A[1][4] = n.A[3][5];
                    } else {
                        memcpy(&v.A[3][1], &n.A[3][0], 6);
                        v.A[3][0] = n.A[3][6];
                        v.A[0][4] = n.A[3][1];
                        v.A[1][4] = n.A[3][3];
                    }
            }

            v.path = n.path + char('A'+ i);
            if (!h.count(v)) {
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
            memset(Q,0,sizeof(Q));

            i = 0;    
            Q[0][0] = a[0];
            Q[0][1] = a[2];
            Q[0][2] = a[6];
            Q[0][3] = a[11];
            Q[0][4] = a[15];
            Q[0][5] = a[20];
            Q[0][6] = a[22];

            Q[1][0] = a[1];
            Q[1][1] = a[3];
            Q[1][2] = a[8];
            Q[1][3] = a[12];
            Q[1][4] = a[17];
            Q[1][5] = a[21];
            Q[1][6] = a[23];

            Q[2][0] = a[4];
            Q[2][1] = a[5];
            Q[2][2] = a[6];
            Q[2][3] = a[7];
            Q[2][4] = a[8];
            Q[2][5] = a[9];
            Q[2][6] = a[10];

            Q[3][0] = a[13];
            Q[3][1] = a[14];
            Q[3][2] = a[15];
            Q[3][3] = a[16];
            Q[3][4] = a[17];
            Q[3][5] = a[18];
            Q[3][6] = a[19];

            int bestk = 0;
            string best = "";
            for (int k = 2; k <=3 ; k++){
                Node n = bfs(k);
                if (bestk ==0 || n.path.length() < best.length()) {
                    bestk = k;
                    best = n.path;
                }
            }
            if (best.length() == 0) {
                printf("No moves needed\n");
            } else {
                cout << best << endl;
            }
            printf("%d\n", bestk);
        }
    }

    return 0;
}