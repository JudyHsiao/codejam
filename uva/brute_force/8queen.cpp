#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int G[8][8];

bool valid(int r, int c) {
    for (int i =0 ; i < r; i++) {
        if(G[i][c] == 1 ) {
            return false;
        }
    }
    int r1, c1;
    r1 = r, c1=c; 
    while(r1 >=0 && c1>=0) {
        r1-=1;
        c1-=1;
        if (G[r1][c1] == 1) {
            return false;
        }
    }

    r1 = r, c1=c; 
    while(r1 >=0 && c1 < 8) {
        r1-=1;
        c1+=1;
        if (G[r1][c1] == 1) {
            return false;
        }
    }

    return true;

}

void printG() {
    for(int i = 0; i <8; i++) {
        for (int j =0; j <8; j++) {
            if(G[i][j]==1) {
                printf("Q");
            } else {
                printf("*");
            }
            
        }
        printf("\n");
    }
}

void  search(int r,  int n) {
    if (n==8) {
        printG()
    }

    for (int c = 0 ; c < 8; c++) {
        if (valid(r, c)) {
            G[r][c] = 1;
            search(r+1, n+1);
            G[r][c] = 0;
        }
    }

}


int main(){
    memset(G, 0 , sizeof(G));
    search(r, 0)


}