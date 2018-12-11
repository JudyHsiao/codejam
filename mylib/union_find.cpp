#include <vector>
#include <set>
using namespace std;


vector<int> pset(1000); // 1000 is just an initial number, it is user-adjustable.
void initSet(int size) { 
    pset.resize(size+1); 
    for (int i = 0; i <= size ;i ++) 
        pset[i] = i; 
} 
int findSet(int i) { return (pset[i] == i) ? i : (pset[i] = findSet(pset[i])); } 
void unionSet(int i, int j) { pset[findSet(i)] = findSet(j); }
bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
int sizeOfSet(){
    set <int> s;
    int n = pset.size();
    for (int i =0 ; i < n; i++) {
        s.insert(pset[i]);
    }
    return s.size();
}