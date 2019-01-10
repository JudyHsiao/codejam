#ifndef MY_STRING_H
#define MY_STRING_H
#include <memory>
#include <string>
class String {
public:
    String():elements(nullptr), first_free(nullptr),cap(nullptr){};
    String(const char* s);

    String(const String&);
    String& operator=(const String&) &;
    String(String&&) noexcept;
    String& operator=(String&&) noexcept;
    ~String();


    size_t size() const{ return first_free-elements;};
    size_t capacity() const {return cap-first_free;};
    bool empty() {return first_free == elements; };
    char *begin()const {return elements;};
    char *end() const{return first_free;};
    const char *cbegin() const {return elements;};
    const char *cend() const{return first_free;};
    std::string str() const{return std::string(cbegin(), cend());};
    

private:
    static std::allocator<char>  alloc;
    char *elements;
    char *first_free;
    char *cap;
    void free();
};

#endif 