#include <string>

using namespace std;

std::string local_str;
int g_int;

int main() {
    int local_int;
    string local_str;

    printf("%d %d\n", g_int, local_int);
    printf("%s %s\n", local_str.c_str(), local_str.c_str());
}



