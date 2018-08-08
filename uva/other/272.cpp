#include <stdio.h>

int main() {
    int c =1;
    bool start = true;

    while((c=getchar()) != EOF) {
         if (c == '"') {
            if (start == true)
                printf("``");
            else
                printf("''");
            start = ! start;
            
         } else {
             printf("%c",c);
         }
    }
    return 0;
}