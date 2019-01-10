
#include "windows.h"
#include "screen.h"
#include <iostream>
using namespace std;

std::ostream& print(std::ostream& os, Windows& w) {
    size_t count = 0;
    for (auto &s:w.screens){
        cout <<count << ":\n";
        print(os, s);
        count++;
    }
    return os ;
}