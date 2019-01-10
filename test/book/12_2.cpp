#include <vector>
#include <string>
using namespace std;

class StrBlob {
public:
    typedef std::vector<std::string>::size_type size_type;
    StrBlob();
    StrBlob(std::initializer_list<std::string> li);
    size_type size() const;
    bool empty() const {return data->empty();};
    void push_back(const std::string &s);
    void pop_back();
    std::string &front();
    const std::string& front() const;
    std::string &back();
    const std::string& back() const;

private:
    shared_ptr<vector<string>> data;
    void check(size_type pos, const string & msg) const;
};

StrBlob::StrBlob():data(std::make_shared<std::vector<std::string>>()) {};
StrBlob::StrBlob(std::initializer_list<std::string> il)
    :data(std::make_shared<vector<string>>(il)) {}

void StrBlob::check(size_type pos, const string& msg) const {
    if (pos >= data->size())
        throw out_of_range(msg);
}

inline void StrBlob::push_back(const string& s) {
    data->push_back(s);
}

void StrBlob::pop_back() {
   check(0, "pop_back on empty StrBlob");
   data->pop_back();
}

string& StrBlob::front() {
    check(0, "front on empty StrBlob");
    return data->front();
}

const string& StrBlob::front() const{
    check(0, "front on empty StrBlob");
    return data->front();
}

std::string &StrBlob::back() {
  check(0, "back on empty StrBlob");
  return data->back();
}

const std::string &StrBlob::back() const {
  check(0, "back on empty StrBlob");
  return data->back();
}
