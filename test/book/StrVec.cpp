#include <string>
#include <memory>
#include "StrVec.h"
#include <algorithm>
#include <iostream>
using namespace std;

std::allocator<std::string> StrVec::alloc;

std::pair <std::string*, std::string*> StrVec::alloc_n_copy(const std::string* b, const std::string* e)
{
    auto data = alloc.allocate(e-b);
    return {data, uninitialized_copy(b,e, data)};
}

StrVec::StrVec(const initializer_list<string>& s) {
    auto newdata = alloc_n_copy(s.begin(), s.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}

StrVec::StrVec(const StrVec& s) {
    auto newdata = alloc_n_copy(s.begin(), s.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}

StrVec &StrVec::operator=(const StrVec& s) {
    auto newdata = alloc_n_copy(s.begin(), s.end());
    free();
    elements = newdata.first;
    first_free = cap = newdata.second;
    return *this;
}

StrVec::StrVec(StrVec&& s)noexcept:elements (s.elements),first_free(s.first_free),cap(s.cap) {
    cout << "move constructor" << endl;
    s.elements = s.first_free = s.cap = nullptr;
}

StrVec&StrVec::operator=(StrVec&& s)noexcept{

    cout << "move assignment" << endl;
    free();
    elements = s.elements;
    first_free = s.first_free;
    cap = s.cap;

    s.elements = s.first_free = s.cap = nullptr;
    return *this;
}
StrVec::~StrVec() {
    free();
}

void StrVec::free() {
    if (elements)
        for_each(elements, first_free,[](string& p) { alloc.destroy(&p);});
        
    alloc.deallocate(elements, cap - elements);
}

/*
void StrVec::free() {
    if (elements)
        for (auto p = first_free; p!=elements;)
            alloc.destroy(--p);
    alloc.deallocate(elements, cap - elements);
}
*/

void StrVec::reserve(size_t n) {
    if (n < capacity())
        return;  
    reallocate(n);
}

void StrVec::reallocate() {
    auto newcapacity = size()?2*size():1;
    reallocate(newcapacity);
}

void StrVec::resize(size_t n, const std::string& s) {
    if (n < size()){
        for (int i = size() -n ; i!= 0; --i)
            pop_back();
    } else if (n > capacity()) {
        for (int i = n - size(); i != 0; --i)
            push_back(s);
    }
}

void StrVec::reallocate(size_t n) {
    
    auto newdata = alloc.allocate(n);
    auto dest = newdata;
    auto elem = elements;
    for (size_t i =0; i !=size(); i++)
        alloc.construct(dest++, std::move(*elem++));
    
    free();
    elements = newdata;
    first_free = dest;
    cap = elements + n;
}

void StrVec::push_back(const std::string& s) {
    chk_n_alloc();
    alloc.construct(first_free++, s);
}

void StrVec::pop_back() {
    alloc.destroy(--first_free);
 }
