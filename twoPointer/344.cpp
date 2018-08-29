#include <cstdlib>
#include <cstring>

/*
Input: "hello" 
        012345 
Output: "olleh"
*/

char* reverseString(char* s) {
    int j = strlen(s)-1;
    int i = 0;
    char tmp;
    while (i<j) {
        tmp = s[i];
        s[i]=s[j];
        s[j]=tmp;
        j--;
        i++; 
    }
    return s;   
}