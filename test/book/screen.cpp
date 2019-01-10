#include "screen.h"
#include <iostream>

using namespace std;
std::ostream& print(std::ostream& os, Screen& s) {
    cout<< "w: " << s.width << "h: " << s.height << endl;
    return os;
}