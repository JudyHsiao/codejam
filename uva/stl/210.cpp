#include <cstdio>
#include <deque>
#include <queue>
#include<cstring>
#include<cstdlib>
#include<cctype>

using namespace std;

const int maxn = 1000;
char prog[maxn][10];
deque<int> readyQ;
queue<int> blockQ;
int n, t[5], Q;
int  var[26], ip[maxn];
bool locked;

void run(int pid) {
    int q = Q;
    while (q > 0) {
        char* p = prog[ip[pid]];
        switch(p[2]) {
            case '=':
                var[p[0] - 'a'] = isdigit(p[5]) ? (p[4] - '0') * 10 + p[5] - '0' : p[4] - '0';
                q -= t[0];
                break;
            case 'i': // print
                printf("%d: %d\n", pid+1, var[p[6] - 'a']);
                q -= t[1];
                break;
            case 'c':
                if (locked) {
                    blockQ.push(pid); 
                    return;
                }
                locked = true;
                q -= t[2];
                break;
            case 'l': // unlock
                locked = false;
                if(!blockQ.empty()) {
                    int pid2 = blockQ.front(); blockQ.pop();
                    readyQ.push_front(pid2);
                }
                q -= t[3];
                break;
            case 'd':
                return;
        }
        ip[pid] ++;
    }
    readyQ.push_back(pid);

}

int main(){

    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%d %d %d %d %d %d %d\n", &n, &t[0], &t[1], &t[2], &t[3], &t[4], &Q);
        memset(var, 0, sizeof(var));
        int line =0;
        for(int i =0; i< n; i++) {
            fgets(prog[line++], maxn, stdin);
            ip[i] = line-1;
            while (prog[line-1][2] != 'd') {
                 fgets(prog[line++], maxn, stdin);
            }
            readyQ.push_back(i);
        }


        while(!readyQ.empty()) {
            int pid = readyQ.front();
            readyQ.pop_front();
            run(pid);
        }

        if (T) 
            printf("\n");
    }
}