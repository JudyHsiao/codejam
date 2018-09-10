#include <stdio>
#include <queue>
#include <set>

using namespace std;

int a, b, c, d;
typedef struct {
    int v[3];
    int dist;
    bool operator < (const Node& rhs) const{
        return dist > rhs.dist;
    }
}Node;
Node bfs() {
    priority_queue<Node> q;
    Node start;
    start.v[0] = 0;
    start.v[1] = 0;
    start.v[2] = c;
    start.dist = 0;
    set<int[3]> h;
    q.push(start);
    int cap[3];
    cap[0] = a;
    cap[1] = b;
    cap[2] = c;
    h.insert({0,0,c});
    Node best;
    int best_diff = 100000;
    while(q.size() > 0 ) {
        Node n = q.top();
        q.pop();
        if (abs(n.v[0] -d) < best_diff ||abs(n.v[1] -d) < best_diff ||abs(n.v[2] -d) < best_diff ) {
            best = n;
        }

        for (int i = 0; i< 3; i++) {
            for(int j = 0; j< 3; j++) {
                int tmp[3];
                memcpy(n.v, tmp, sizeof(tmp));
                if (i !== j) {
                    if (tmp[i] > 0 && tmp[j] < cap[j]) {
                        int diff = cap[j] - tmp[j];
                        int fill = min(tmp[i], diff);
                        tmp[i] -= fill;
                        tmp[j] += fill;
                        if (h.count(tmp) == 0) {
                            Node u;
                            memcpy(tmp, u.v, sizeof(tmp));
                            u.dist = n.dist +fill;
                            if (u.v[0] == d || u.v[1] == d || u.v[2] == d) {
                                return u;
                            }
                            q.push(u);
                            h.insert(tmp);
                        }
                    }
                }
            }
        }

        return best;

    }


}
int main(){
    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%d %d %d", &a, &b, &c, &d);
        Node n = bfs();
    }

    return 0;
}