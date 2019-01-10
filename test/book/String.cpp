#include "String.h"
#include <iostream>
#include <algorithm>
using namespace std;
std::allocator<char> String::alloc;

String::String(const char* s) {
    int n = strlen(s);
    if (n) {
        auto data = alloc.allocate(n+1);
        uninitialized_copy(s, s+n, data);
        *(data+n+1) = '\0';
        elements = data;
        first_free = cap= elements + n;
    } 
}
String::String(const String& s){
    cout << "copy constructor" << endl;
    int n = s.size();
    if (n) {
        auto data = alloc.allocate(n+1);
        auto ele = data;
        auto p = s.elements;
        alloc.construct(ele++, *p++);
        elements = data;
        first_free = cap = ele;
    } 
}
String& String::operator=(const String& rhs) &{
    cout << "operator=" << endl;
    auto new_first_elem = alloc.allocate(rhs.size());
    auto new_first_free = std::uninitialized_copy(rhs.begin(), rhs.end(),
                                                new_first_elem);

    free();
    elements = new_first_elem;
    first_free = cap = new_first_free;
    return *this;

}

String::String(String&& s) noexcept:elements(s.elements),first_free(s.first_free),cap(s.cap){
    cout << "move constructor" << endl;
    s.elements = s.first_free = s.cap =nullptr; 
}

String& String::operator=(String&& s)noexcept {
    cout << "move assignment" << endl; 
    if (this != &s) {
        free();
        elements = s.elements;
        first_free = s.first_free;
        cap = s.cap;
        s.elements = s.first_free = s.cap =nullptr; 
    }
    return *this;
}

void String::free() {
  while (!empty())
    alloc.destroy(--first_free);

  alloc.deallocate(elements, capacity());
  elements = first_free = cap = nullptr;
}

String::~String() {
    free();
}