#include <cstdio>
#include <set>

using namespace std;
int main(){
    set<long> heap;
    heap.insert(1);
    int t = 1500;
    long min;
    while (t--){
        min = *heap.begin();
        heap.erase(min);
        if (heap.find(2*min) == heap.end()){
            heap.insert(2*min);
        }
        if (heap.find(3*min) == heap.end()){
            heap.insert(3*min);
        }
        if (heap.find(5*min) == heap.end()){
            heap.insert(5*min);
        }
    }
    printf("The 1500'th ugly number is %ld.\n", min);
    return 0;

}