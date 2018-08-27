#include <cstdio>

using namespace std;
bool solve(int& W) {
    int Wl, Dl, Wr, Dr;
    bool b1 =true, b2=true;;
    scanf("%d%d%d%d",&Wl,&Dl,&Wr,&Dr);

    if (Wl == 0) {
        b1 = solve(Wl); 
    }

    if (Wr == 0) {
        b2 = solve(Wr);
    }
    
    W = Wr + Wl;
    return b1 && b2 && Wl*Dl == Wr*Dr;

}

int main(){
    int T,W;
    scanf("%d", &T);
    while (T--) {
        if(solve(W)) {
            printf("YES\n");
        } else{
            printf("NO\n");
        }
        if (T)
            printf("\n");
    }
}