#include <vector>
#include <cstdio>
#include <iostream>

using namespace std;

void Merge(vector<int>& A, int s, int mid ,int e) {
    vector<int> left(A.begin()+s, A.begin()+mid+1);
    vector<int> right(A.begin()+mid+1, A.begin()+e+1);
    int i = 0;
    int j = 0;

    int k = s;

    //printf("%d, %d, %d\n", s, mid, e);

    while (i<left.size() && j<right.size()) {
        if (left[i]<=right[j])
            A[k++]=left[i++];
        else
            A[k++]=right[j++];
    }

    while (i<left.size() ) {
        A[k++]=left[i++];
    }

    while (j<right.size() ) {
        A[k++]=right[j++];
    }
}

void Mergesort(vector<int>& A, int s, int e) {
    if (s < e) {
        int mid = (s+e)/2;
        Mergesort(A, s, mid);
        Mergesort(A, mid+1, e);
        //inplace_merge(A.begin(), A.begin()+mid+1, A.begin()+e+1);
        Merge(A, s, mid, e);  
    }

}
int main(){
    vector<int> A({5,3,8,6,2,7,1,4});
    Mergesort(A, 0, A.size()-1);
    for(const auto &i:A){
        cout << i << endl;
    }
}