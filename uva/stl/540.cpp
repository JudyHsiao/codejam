#include<cstdio>
#include <queue>
#include<unordered_map>
#include <string>
#include <iostream>

using namespace std;



int main(){
    int kase = 1;
    while (true) {
        int t;
        queue<int>teams[1005] ;
        queue<int>line;
        unordered_map <int, int> teamID;

        scanf("%d", &t);
        if (t == 0) {
            return 0;
        }

        printf("Scenario #%d\n", kase);
        kase+=1;

        for (int i = 0; i < t; i++) {
            int n;
            scanf("%d", &n);
            for (int j = 0; j <n; j++) {
                int a;
                scanf("%d", &a);
                teamID[a] = i;
            }
        }

        while (true) {
            string cmd;
            int p;
            cin >> cmd ;
            if (cmd == "ENQUEUE")  {
                cin >>p;
                int tID = teamID[p];
                if (teams[tID].empty()) {
                    line.push(tID);
                }
                teams[tID].push(p);
            } else if (cmd == "DEQUEUE")  {
                int first = line.front();
                int p = teams[first].front();
                printf("%d\n", p);
                teams[first].pop();
                if (teams[first].empty()) {
                    line.pop();
                }
            } else if (cmd == "STOP") {
                break;
            }
        }
        printf("\n");
    }

}