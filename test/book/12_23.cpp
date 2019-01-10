#include <string>
#include <cstring>
#include <iostream>

using namespace std;
int main () {
    const char *ch1 = "Hello ";
    const char *ch2 = "World";

    char* ch3 = new char [strlen(ch1) + strlen(ch2)+1];
    strcpy(ch3, ch1);
    strcat(ch3, ch2);
    printf("%s\n", ch3);
    delete [] ch3;

    string s1("Hello ");
    string s2("World");
    string s3(s1+s2);
    cout << s3 << endl;
    return 0;

}