#include <cstdio>
#include <queue>
#include <set>
#include <tuple>
#include <cstring>
#include <iostream>

using namespace std;

int a, b, c, d;
struct Node {
    int v[3];
    int dist;
    bool operator < (const Node& rhs) const{
        return dist > rhs.dist;
    }
};


void bfs() {
    if (c == d) {
        printf("%d %d\n",  0, d);
        return;
    }


    priority_queue<Node> q;
    Node start;
    start.v[0] = 0;
    start.v[1] = 0;
    start.v[2] = c;
    start.dist = 0;
    set<tuple<int, int, int>> h;
    q.push(start);
    h.insert({0,0,c});
    int cap[3];
    cap[0] = a;
    cap[1] = b;
    cap[2] = c;

    int best_dis = 0;
    int best_d = -100;



    while(q.size() > 0 ) {
        Node n = q.top();
        q.pop();
        for (int i = 0; i<3 ; i++) {
            if ( (n.v[i] < d && (d - n.v[i] < d- best_d)) ) {
                best_d = n.v[i];
                best_dis = n.dist;
            }
        }

        for (int i = 0; i< 3; i++) {
            for(int j = 0; j< 3; j++) {
                if (i != j) {
                    if (n.v[i] > 0 && n.v[j] < cap[j]) {
                        int diff = cap[j] - n.v[j];
                        int fill = min(n.v[i], diff);
                        Node u;
                        memcpy(&u, &n, sizeof(n));
                        u.dist = n.dist +fill;
                        u.v[i] -= fill;
                        u.v[j] += fill;
                        if (h.count({u.v[0],u.v[1],u.v[2]}) == 0) {
                            q.push(u);
                            h.insert({u.v[0],u.v[1],u.v[2]});
                        }
                        if (u.v[0] == d || u.v[1] == d || u.v[2] == d) {
                            best_d = d;
                            best_dis = u.dist;
                            printf("%d %d\n",  best_dis, best_d);
                            return;
                        }

                    }
                }
            }
        }
    }
    printf("%d %d\n",  best_dis, best_d);
    return ;
}
int main(){
    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%d %d %d %d", &a, &b, &c, &d);
        bfs();
    }

    return 0;
}