#ifndef STRVEC_H
#define STRVEC_H

#include <string>
#include <memory>

class StrVec {
public: 
    StrVec():elements(nullptr), first_free(nullptr), cap(nullptr){};
    StrVec(const std::initializer_list<std::string>&);
    
    StrVec(const StrVec&);
    StrVec &operator=(const StrVec&);
    StrVec(StrVec&&)noexcept;
    StrVec &operator=(StrVec&&) noexcept;

    ~StrVec();
    void push_back(const std::string&);
    void pop_back();


    size_t size() const {return first_free - elements;};
    size_t capacity() const {return cap - elements;};
    std::string *begin() const {return elements;};
    std::string *end() const {return first_free;};
    void reserve (size_t n);
    void resize(size_t, const std::string & s= std::string());
    



private:
    static std::allocator<std::string> alloc;
    void chk_n_alloc() {if (size() == capacity()) reallocate();}
    std::pair <std::string*, std::string*> alloc_n_copy(const std::string*, const std::string*);
    void reallocate();
    void reallocate(size_t n);
    void free();
    std::string *elements;
    std::string *first_free;
    std::string *cap;
};


#endif