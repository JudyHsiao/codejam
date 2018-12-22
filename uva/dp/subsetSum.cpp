#include<cstdio>
#include<cstring>
#include <set>

using namespace std;

int main() {
    int A[8] = {-14, 2,2,2,2,2,2,2}; 
    
    set<pair<int,int>>s;

    for (int i =0 ; i < 8; i++) {
        s.insert({i,A[i]});
    }

    int min = 0;
    int max = 0;
    for (int i = 0; i < 8; i++) {
        if (A[i] > 0)
            max += A[i];
        else 
            min +=A[i];
    }

    for (int i =0 ; i < 8; i++) {
        for (int j = min; j<=max; j++){
            if (s.count({i-1, j}) >0 || s.count({i-1, j-A[i]})>0)
                s.insert({i,j});
        }
    }

    for(auto p: s)
        if (p.first == 7)
            printf("%d\n",p.second);


}