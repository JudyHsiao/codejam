void printG() {
    printf("G\n");
    for(int i =0 ; i< 256; i++) {
        for(int j =0 ; j < 256; j++) {
            if(G[i][j] == 1) {
                printf("%c %c\n", i,j);
            }
        }
    }
}

void printV(const set<char>& V) {
    cout <<"V: ";
    for(auto v:V) {
        cout << v << " ";
    }
    cout << "\n";
}