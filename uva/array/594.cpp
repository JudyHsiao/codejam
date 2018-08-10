#include <iostream>
using namespace std;



long endianSolBits(long x){
   long temp = 0;   // variable to hold result
   int j;



   for (j=0; j<32; j++){
      if (x&(1<<j)){   // check every bits
         temp|= 1<<(3-j/8)*8+(j%8);   // set bits accordingly ;)
      }
   }

   return temp;
}



int main(){
    long x;    
    while(cin>>x)
        cout<<x<<" converts to "<<endianSolBits(x)<<endl;

    return 0;
}