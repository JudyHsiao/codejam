#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
using namespace std;

const int maxn = 30;
vector<int> A[maxn];
int n;
void find_block(int a, int& p, int&h) {
    for (int i =0 ; i < n; i++){
        for (vector<int> ::iterator it = A[i].begin(); it != A[i].end(); it++) {
            if (*it == a ) {
                p = i;
                h = it - A[i].begin();
                return ;
            }
        }
    }
    return ;
}

void clear_above(int p, int h) {
    for (int i = h +1 ; i < A[p].size(); i++) {
        int b = A[p][i];
        A[b].push_back(b);
    }
    A[p].resize(h+1);
}

void pile_onto(int p, int h, int p2){
    for (int i = h  ; i < A[p].size(); i++) {
        int b = A[p][i];
        A[p2].push_back(b);
    }
    A[p].resize(h);
}

void print(){
    for (int i = 0; i < n ;i ++) {
        printf("%d:", i);
        for(int j =0 ; j< A[i].size(); j ++){
            printf(" %d",A[i][j]);
        }
        printf("\n");
    }
}
 

int main(){


    scanf("%d", &n);

    for (int i=0 ; i < n; i++) {
        A[i].push_back(i);
    }

    string s1, s2;
    int a, b;
    while (cin >> s1 >> a >> s2 >> b) {
        int pa, pb, ha, hb;
        find_block(a, pa, ha);
        find_block(b, pb, hb);
    
        if (pa == pb)
            continue;
        if (s1 == "move")
            clear_above(pa, ha);
        if (s2 =="onto")
            clear_above(pb, hb);

        pile_onto(pa, ha, pb);
    }
    print();
    return 0;
}