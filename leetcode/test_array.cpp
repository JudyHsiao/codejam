#include <iostream>


int main() {
    int d[10][10][10] ={{{0}}};
    //memset (d, 0, sizeof(d));
    

    for (int i =0; i< 10; i++) {
        for (int j = 0; j < 10; j++) {
            for (int k =0 ; k<10; k++) {
                printf("%d\n", d[i][j][k]);
            }
        }
    }
    return 0;
}