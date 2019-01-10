#include "Message.h"
#include "Folder.h"
#include <iostream>
using namespace std;

int main() {
    Folder f1, f2;
    Message m1("m1"), m2("m2"), m3("m3"), m4("m4"), m5("m5");
    m1.save(f1); m2.save(f1); m5.save(f1);
    m3.save(f2); m4.save(f2); m5.save(f2);
    std::cout << "\n===== Message save =====\n";
    f1.print(); f2.print(); std::cout << std::endl;
    m1.print(); m2.print(); m3.print(); m4.print(); m5.print();

}