#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n;
    while(scanf("%d",&n) == 1) {
        vector<string> filenames;
        for (int i =0; i <n; i++) {
            cin >> filenames[i];
        }
        sort(filenames.begin(),filenames.end());
        printf("------------------------------------------------------------\n");

        int col = n;
        while( col > 0) {
            int width = 60;
            int number_of_words = n / col;

            for (int c = 0; c < col; c++) {
                auto start = filenames.begin()+ c * number_of_words;
                auto end = start + number_of_words;
                auto longest_filename = max_element(start, end,
                 [](string a, string b) {  
                    return (a.length() < b.length()); 
                });

                if (c < col -1) {
                    width -= (longest_filename->length() + 2);
                } else {
                    width -= longest_filename->length();
                }

                if (width < 0){
                    col--;
                    break;
                }
            }
            if (width >= 0) {
                break;
            }
        }

        cout << "columm:" << col << endl;
    }
}